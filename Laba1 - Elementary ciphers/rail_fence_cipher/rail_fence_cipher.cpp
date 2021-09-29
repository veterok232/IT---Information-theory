#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int** create_map(int key, int size);
string encrypt(string message, int key);
string decrypt(string message, int key);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Исходное сообщение
    string message("Это лабораторная работа по КиОКИ");
    //Ключ
    string s_key("4");

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
    
    int key;

    try {
        key = stoi(s_key);
    }
    catch (std::invalid_argument e) 
    {
        cout << "Invalid key!\n";
        return -1;
    }

    //string message("привет мир");
    //int key = 3;

    if (key < 2)
    {
        printf("Invalid key!");
        return -1;
    }

    int** map;

    string encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message.c_str());

    string decrypted_message = decrypt(encrypted_message, key);
    printf("decrypted message: %s\n", decrypted_message.c_str());

    getchar();
    return 0;
}

//Создание карты шифрования
int** create_map(int key, int size)
{
    int period = 2 * (key - 1);
    int width = size / key + 5;

    int** map = new int* [key];
    for (int i = 0; i < key; i++)
    {
        map[i] = new int[width];
    }

    int* ind_arr = new int[key];
    for (int i = 0; i < key; i++)
        ind_arr[i] = 0;

    for (int i = 0; i < key; i++)
        for (int j = 0; j < width; j++)
        {
            map[i][j] = -1;
        }

    int mod, j;

    for (int i = 0; i < size; i++)
    {
        mod = i % period;
        if (mod < key - 1)
            j = mod;
        else
            j = period - mod;

        map[j][ind_arr[j]++] = i;
    }

    return map;
}

//Шифрование
string encrypt(string message, int key)
{
    int** map = create_map(key, message.length());
    int width = message.length() / key + 5;

    string encrypted_message("");
    
    for (int i = 0; i < key; i++)
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == -1) break;
            encrypted_message = encrypted_message + message[map[i][j]];
        }

    for (int i = 0; i < key; i++)
        delete[] map[i];
    delete[] map;
            
    return encrypted_message;
}

//Дешифрование
string decrypt(string message, int key)
{
    int** map = create_map(key, message.length());
    int width = message.length() / key + 5;

    char* decrypted_message_c = new char[message.length() + 1];

    for (int i = 0; i < message.length() + 1; i++)
        decrypted_message_c[i] = '\0';

    string decrypted_message("");

    int count = 0;

    for (int i = 0; i < key; i++)
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == -1) break;
            decrypted_message_c[map[i][j]] = message[count++];
        }

    decrypted_message = decrypted_message_c;

    for (int i = 0; i < key; i++)
        delete[] map[i];
    delete[] map;
    delete[] decrypted_message_c;

    return decrypted_message;
}