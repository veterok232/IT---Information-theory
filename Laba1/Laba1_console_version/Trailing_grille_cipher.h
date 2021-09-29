#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

int** trailing_grille_create_matrix(int);
int** trailing_grille_create_template(int, int, int**, int*);
string trailing_grille_encrypt(int n, int** matr_template, string message);
string trailing_grille_decrypt(int n, int** matr_template, string message);
bool trailing_grille_encryption();
bool trailing_grille_decryption();