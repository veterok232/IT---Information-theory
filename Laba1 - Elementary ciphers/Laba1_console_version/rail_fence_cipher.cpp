#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>

#include "rail_fence_cipher.h"

using namespace std;

//Создание карты шифрования
int** rail_fence_create_map(int key, int size)
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
string rail_fence_encrypt(string message, int key)
{
    int** map = rail_fence_create_map(key, message.length());
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
string rail_fence_decrypt(string message, int key)
{
    int** map = rail_fence_create_map(key, message.length());
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

bool rail_fence_encryption()
{
    //Исходное сообщение
    string message("");
    //Ключ
    string s_key("");

    char message_c[255];
    char s_key_c[255];

    printf("Введите исходное сообщение: ");
    cin.getline(message_c, 255);
    message = message_c;

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
        return false;
    }

    if (key < 2)
    {
        printf("Invalid key!\n");
        return false;
    }

    int** map;

    string encrypted_message = rail_fence_encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message.c_str());
    printf("\n");

    return true;
}

bool rail_fence_decryption()
{
    //Исходное сообщение
    string message("");
    //Ключ
    string s_key("");

    char message_c[255];
    char s_key_c[255];

    printf("Введите исходное сообщение: ");
    cin.getline(message_c, 255);
    message = message_c;

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
        return false;
    }

    if (key < 2)
    {
        printf("Invalid key!\n");
        return false;
    }

    int** map;

    string decrypted_message = rail_fence_decrypt(message, key);
    printf("Decrypted message: %s\n", decrypted_message.c_str());
    printf("\n");

    return true;
}