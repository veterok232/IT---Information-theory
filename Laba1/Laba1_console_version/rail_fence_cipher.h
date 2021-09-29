#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int** rail_fence_create_map(int key, int size);
string rail_fence_encrypt(string message, int key);
string rail_fence_decrypt(string message, int key);
bool rail_fence_encryption();
bool rail_fence_decryption();