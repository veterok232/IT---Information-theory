#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

int** create_matrix(int);
int** create_template(int, int, int**, int*);
string encrypt(int n, int** matr_template, string message);
string decrypt(int n, int** matr_template, string message);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Сообщение для шифрования
    //string message("HERE, IS A SECRET MESSAGE WRITE!");
    string message("Привет, мир мой дорогой!");
    //Ключ
    //string key("121342323");
    string key("1234");

    char message_c[255];
    char key_c[255];

    printf("Введите исходное сообщение: ");
    cin.getline(message_c, 255);
    message = message_c;
    printf("\n");

    printf("Введите ключ: ");
    cin.getline(key_c, 255);
    key = key_c;
    printf("\n");

    int count = key.length();
    int n;

    //Проверка сообщения на корректность
    if (message.find("*", 0) != -1)
    {
        printf("Illegal character in the message!\n");
        return -1;
    }

    //Проверка ключа на корректность
    for (int i = 0; i < count; i++)
    {
        if (!((key[i] > '0') && (key[i] < '5')) || (key.length() <= 2))
        {
            printf("Invalid key!\n");
            return -1;
        }
    }

    //Вычисление размерности матрицы по ключу
    if ((int)sqrt(count * 4) * (int)sqrt(count * 4) == count * 4)
        n = (int)sqrt(count * 4);
    else if ((int)sqrt(count * 4 - 3) * (int)sqrt(count * 4) == (count * 4 - 3))
        n = (int)sqrt(count * 4 - 3);
    else
    {
        cout << "Key error!" << endl;
        return -1;
    }

    int* m_key = new int[count];

    //Перевод ключа в массив интов
    for (int i = 0; i < count; i++)
    {
        m_key[i] = key[i] - '0';
    }
   
    int** matrix;

    //Создание первоначальной марицы  
    matrix = create_matrix(n);

    printf("Первоначальная матрица:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n");

    int** matr_template;

    //Создание матрицы-трафарета
    matr_template = create_template(n, count, matrix, m_key);

    printf("Матрица-трафарет:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d ", matr_template[i][j]);
        printf("\n");
    }
    printf("\n");

    //Шифрование
    string encrypted_message = encrypt(n, matr_template, message);
    printf("Encrypted message: %s\n", encrypted_message.c_str());

    //Дешифрование
    string decrypted_message = decrypt(n, matr_template, encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message.c_str());

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < n; i++)
        delete[] matr_template[i];
    delete[] matr_template;

    delete[] m_key;

    getchar();
    return 0;
}

//Создание первоначальной матрицы
int** create_matrix(int n)
{
    int counter, max_counter = 1;
    int** matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int [n];
    }

    for (int k = 0; k < n / 2; k++)
    {
        for (int step = 1; step <= 4; step++)
        {
            counter = max_counter;
            switch (step)
            {
            case 1:
                for (int j = k; j < n - k - 1; j++)
                    matrix[k][j] = counter++;
                break;
            case 2:
                for (int i = k; i < n - k - 1; i++)
                    matrix[i][n - k - 1] = counter++;
                break;
            case 3:
                for (int j = n - k - 1; j > k; j--)
                    matrix[n - k - 1][j] = counter++;
                break;
            case 4:
                for (int i = n - k - 1; i > k; i--)
                    matrix[i][k] = counter++;
                max_counter = counter;
                break;
            }
        }
    }

    if (n % 2)
        matrix[n / 2][n / 2] = max_counter;

    return matrix;
}

//Создание матрицы-трафарета
int** create_template(int n, int count, int** matrix, int* m_key)
{
    int** matr_template = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matr_template[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr_template[i][j] = 0;

    int i, j, curr_i = 0, curr_j = 0;
    bool is_found = false;

    for (int k = 1; k <= count; k++)
    {
        is_found = false;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                if (matrix[i][j] == k)
                {
                    curr_i = i;
                    curr_j = j;
                    is_found = true;
                    break;
                }
            if (is_found) break;
        }

        switch (m_key[k - 1])
        {
        case 1:
            matr_template[curr_i][curr_j] = 1;
            break;
        case 2:
            matr_template[curr_j][n - curr_i - 1] = 1;
            break;
        case 3:
            matr_template[n - curr_i - 1][n - curr_j - 1] = 1;
            break;
        case 4:
            matr_template[n - curr_j - 1][curr_i] = 1;
            break;
        }
    }

    return matr_template;
}

string encrypt(int n, int** matr_template, string message)
{
    string encrypted_message;
    string temp_message = message, curr_message = message;

    char** encr_mes = new char* [n];
    for (int i = 0; i < n; i++)
    {
        encr_mes[i] = new char[n];
    }

    int count = 0, curr_len = message.length();

    while (temp_message.length())
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                encr_mes[i][j] = 0;

        if (temp_message.length() > n * n)
        {
            curr_message = temp_message;
            curr_message.erase(n * n, curr_message.length() - n * n);
            temp_message.erase(0, n * n);
        }
        else
        {
            curr_message = temp_message;
            while (curr_message.length() < n * n)
                curr_message = curr_message + "*";
            temp_message = "";
        }

        count = 0;
        for (int step = 1; step <= 4; step++)
        {
            switch (step)
            {
            case 1:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if (matr_template[i][j])
                            encr_mes[i][j] = curr_message[count++];
                    }

                break;
            case 2:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[n - j - 1][i]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            encr_mes[i][j] = curr_message[count++];
                    }
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[n - i - 1][n - j - 1]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            encr_mes[i][j] = curr_message[count++];
                    }
                break;
            case 4:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[j][n - i - 1]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            encr_mes[i][j] = curr_message[count++];
                    }
                break;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                    encrypted_message = encrypted_message + encr_mes[i][j];
    }
  
    for (int i = 0; i < n; i++)
        delete[] encr_mes[i];
    delete[] encr_mes;

    return encrypted_message;
}

string decrypt(int n, int** matr_template, string message)
{
    string decrypted_message;
    string temp_message = message, curr_message = message;

    char** decr_mes = new char* [n];
    for (int i = 0; i < n; i++)
    {
        decr_mes[i] = new char[n];
    }

    int count = 0, curr_len = message.length();

    while (temp_message.length())
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                decr_mes[i][j] = 0;

        count = 0;
        if (temp_message.length() > n * n)
        {
            curr_message = temp_message;
            curr_message.erase(n * n, curr_message.length() - n * n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    decr_mes[i][j] = curr_message[count++];
                }
            temp_message.erase(0, n * n);
        }
        else
        {
            curr_message = temp_message;
            while (curr_message.length() < n * n)
                curr_message = curr_message + "*";
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    decr_mes[i][j] = curr_message[count++];
                }
            temp_message = "";
        }

        count = 0;
        for (int step = 1; step <= 4; step++)
        {
            switch (step)
            {
            case 1:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if (matr_template[i][j])
                            decrypted_message = decrypted_message + decr_mes[i][j];
                    }
                break;
            case 2:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[n - j - 1][i]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            decrypted_message = decrypted_message + decr_mes[i][j];
                    }
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[n - i - 1][n - j - 1]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            decrypted_message = decrypted_message + decr_mes[i][j];
                    }
                break;
            case 4:
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if ((matr_template[j][n - i - 1]) && !(((i == n / 2) && (j == n / 2)) && (n % 2)))
                            decrypted_message = decrypted_message + decr_mes[i][j];
                    }
                break;
            }
        }
    }

    while (decrypted_message[decrypted_message.length() - 1] == '*')
    {
        decrypted_message.erase(decrypted_message.length() - 1, 1);
    }

    for (int i = 0; i < n; i++)
        delete[] decr_mes[i];
    delete[] decr_mes;

    return decrypted_message;
}