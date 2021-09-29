#pragma once
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

void column_sort_key(TKeyPair* key, int n);
int* column_create_key(string key);
int column_find_elem(int* arr, int elem, int n);
string column_encrypt(string message, int* key, int key_len);
string column_decrypt(string message, int* key, int key_len);
bool column_encryption();
bool column_decryption();