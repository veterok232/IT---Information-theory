#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <locale.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

typedef struct KeyPair
{
    char elem;
    int index;
} TKeyPair;

void sort_key(TKeyPair* key, int n);
int* create_key(string key);
int find_elem(int* arr, int elem, int n);
string encrypt(string message, int* key, int key_len);
string decrypt(string message, int* key, int key_len);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string s_key("аавб");

    //Исходное сообщение
    string message("Привет_мир");
    //Ключ

    char message_c[255];
    char s_key_c[255];

    printf("Введите исходное сообщение: ");
    cin.getline(message_c, 255);
    message = message_c;
    printf("\n");

    printf("Введите ключ: ");
    cin.getline(s_key_c, 255);
    s_key = s_key_c;
    printf("\n");

    transform(s_key.begin(), s_key.end(), s_key.begin(), toupper);

    int* m_key = create_key(s_key);

    string encrypted_message = encrypt(message, m_key, s_key.length());
    printf("Encrypted message: %s\n", encrypted_message.c_str());

    string decrypted_message = decrypt(encrypted_message, m_key, s_key.length());
    printf("Decrypted message: %s\n", decrypted_message.c_str());

    delete[] m_key;

    getchar();
    return 0;
}

//Преобразование ключа в порядок чтения столбцов
int* create_key(string key)
{
    int count = key.length();

    TKeyPair* tmp = new TKeyPair[count];
    for (int i = 0; i < count; i++)
    {
        tmp[i].elem = key[i];
        tmp[i].index = i;
    }

    sort_key(tmp, key.length());

    int* res = new int[count];
    for (int i = 0; i < count; i++)
    {
        res[tmp[i].index] = i;
    }

    delete[] tmp;

    return res;
}

void sort_key(TKeyPair* key, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (key[i].elem > key[j].elem)
            {
                TKeyPair tmp = key[i];
                key[i] = key[j];
                key[j] = tmp;
            }
}

int** create_map(int* key, int key_len, int size)
{
    int width = key_len;
    int height = size / width + 1;

    int** map = new int* [height];
    for (int i = 0; i < height; i++)
    {
        map[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            map[i][j] = -1;

    int position = 0, step = 0, i = 0, j = 0;

    for (step = 0; step < width; step++)
    {
        i = 0;
        j = find_elem(key, step, width);

        while ((i < height) && (i * width + j < size))
        {
            map[i][j] = position;
            position++;
            i++;
        }
    }

    return map;
}

int find_elem(int* arr, int elem, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem) return i;
    }
}

//Шифрование
string encrypt(string message, int* key, int key_len)
{
    int mes_len = message.length();
    int** map = create_map(key, key_len, mes_len);

    int width = key_len;
    int height = mes_len / width + 1;
    int count = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            printf("%3d", map[i][j]);
        printf("\n");
    }
    printf("\n");

    char* encrypted_message_c = new char[mes_len + 1];
    for (int i = 0; i < mes_len + 1; i++)
        encrypted_message_c[i] = '\0';

    string encrypted_message("");

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (map[i][j] != -1)
                encrypted_message_c[map[i][j]] = message[count++];

    for (int i = 0; i < height; i++)
        delete[] map[i];
    delete[] map;

    encrypted_message = encrypted_message_c;

    delete[] encrypted_message_c;

    return encrypted_message;
}

//Дешифрование
string decrypt(string message, int* key, int key_len)
{
    int mes_len = message.length();
    int** map = create_map(key, key_len, mes_len);

    int width = key_len;
    int height = mes_len / width + 1;
    int count = 0;

    string decrypted_message("");

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (map[i][j] != -1)
                decrypted_message = decrypted_message + message[map[i][j]];

    for (int i = 0; i < height; i++)
        delete[] map[i];
    delete[] map;

    return decrypted_message;
}