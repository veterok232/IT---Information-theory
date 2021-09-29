#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

//Алфавит
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool vigener_in_alphabet(char symb);
string vigener_create_key(string key, string message);
string vigener_encrypt(string message, string key);
string vigener_decrypt(string message, string key);
bool vigener_encryption();
bool vigener_decryption();