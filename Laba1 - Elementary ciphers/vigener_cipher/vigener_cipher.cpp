#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

const int _ENG = 26;
const int _RUS = 32;

//Алфавит
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool in_alphabet(char symb);
string create_key(string key, string message);
string encrypt(string message, string key);
string decrypt(string message, string key);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Исходное сообщение
    string message("Hello, world!");
    //Ключ
    string key("moDE");

    char message_c[255];
    char key_c[255];

    printf("Input ONLY in English!\n\n");

    printf("Введите исходное сообщение: ");
    cin.getline(message_c, 255);
    message = message_c;
    printf("\n");

    printf("Введите ключ: ");
    cin.getline(key_c, 255);
    key = key_c;
    printf("\n");

    //Перевод в верхний регистр
    transform(message.begin(), message.end(), message.begin(), toupper);
    transform(key.begin(), key.end(), key.begin(), toupper);

    printf("Key: %s\n", key.c_str());
    printf("Message: %s\n\n", message.c_str());

    int currPos = 0;

    //Проверка ключа на корректность
    while (currPos < key.length())
    {
        if (!in_alphabet(key[currPos]))
        {
            printf("Invalid key!\n");
            return -1;
        }
        currPos++;
    }

    currPos = 0;

    //Удаление всех символов не из алфавита
    while (currPos < message.length())
    {
        if (!in_alphabet(message[currPos]))
        {
            message.replace(currPos, 1, "");
            continue;
        }
        currPos++;
    }

    //Создание ключа
    key = create_key(key, message);

    //Шифрование
    string encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message.c_str());

    //Дешифрование
    string decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message.c_str());

    return 0;
}

bool in_alphabet(char symb)
{
    if (alphabet.find(symb) != -1)
        return true;
    else
        return false;
}

string create_key(string input_key, string message)
{
    string key = input_key;

    while (key.length() < message.length())
    {
        key.insert(key.length(), input_key);
    }

    while (input_key.length() > message.length())
    {
        key.erase(key.length() - 1, 1);
    }

    return key;
}

string encrypt(string message, string key)
{
    string encrypted_message;
    int message_len = message.length();
    int indexI, indexJ;

    for (int i = 0; i < message_len; i++)
    {
        indexI = key[i] - 'A';
        indexJ = message[i] - 'A';
        encrypted_message = encrypted_message + alphabet[(indexI + indexJ) % alphabet.length()];
    }

    return encrypted_message;
}

string decrypt(string message, string key)
{
    string decrypted_message;
    int message_len = message.length();
    int indexI, indexJ;

    for (int i = 0; i < message_len; i++)
    {
        indexI = key[i] - 'A';
        indexJ = message[i] - 'A';
        decrypted_message = decrypted_message + alphabet[(indexJ - indexI + alphabet.length()) % alphabet.length()];
    }

    return decrypted_message;
}