//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include <System.SysUtils.hpp>

#include "Trailing_grille_cipher.h"
#include "laba1.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//Создание первоначальной матрицы
int** trailing_grille_create_matrix(int n)
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
int** trailing_grille_create_template(int n, int count, int** matrix, int* m_key)
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

UnicodeString trailing_grille_encrypt(int n, int** matr_template, UnicodeString message)
{
	UnicodeString encrypted_message;
	UnicodeString temp_message = message;
	UnicodeString curr_message = message;

	wchar_t** encr_mes = new wchar_t* [n];
	for (int i = 0; i < n; i++)
	{
		encr_mes[i] = new wchar_t[n];
	}

	int count = 0, curr_len = message.Length();

	while (temp_message.Length())
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				encr_mes[i][j] = 0;

		if (temp_message.Length() > n * n)
		{
			curr_message = temp_message;
			curr_message.Delete(n * n + 1, curr_message.Length() - n * n);
			temp_message.Delete(1, n * n);
		}
        else
        {
            curr_message = temp_message;
			while (curr_message.Length() < n * n)
				curr_message = curr_message + "*";
			temp_message = "";
		}

		count = 1;
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

UnicodeString trailing_grille_decrypt(int n, int** matr_template, UnicodeString message)
{
	UnicodeString decrypted_message;
	UnicodeString temp_message = message, curr_message = message;

	wchar_t** decr_mes = new wchar_t* [n];
	for (int i = 0; i < n; i++)
	{
		decr_mes[i] = new wchar_t[n];
	}

	int count = 0, curr_len = message.Length();

	while (temp_message.Length())
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				decr_mes[i][j] = 0;

		count = 1;
		if (temp_message.Length() > n * n)
		{
			curr_message = temp_message;
			curr_message.Delete(n * n + 1, curr_message.Length() - n * n);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					decr_mes[i][j] = curr_message[count++];
				}
			temp_message.Delete(1, n * n);
		}
		else
		{
			curr_message = temp_message;
			while (curr_message.Length() < n * n)
				curr_message = curr_message + "*";
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					decr_mes[i][j] = curr_message[count++];
				}
			temp_message = "";
		}

		count = 1;
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

	while (decrypted_message[decrypted_message.Length()] == '*')
	{
		decrypted_message.Delete(decrypted_message.Length(), 1);
	}

	for (int i = 0; i < n; i++)
		delete[] decr_mes[i];
	delete[] decr_mes;

	return decrypted_message;
}


bool trailing_grille_encryption(UnicodeString message, UnicodeString s_key)
{
	int count = s_key.Length();
	int n;

	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
		return false;
	}

	//Проверка сообщения на корректность
	if (message.Pos("*") != 0)
	{
		ShowMessage("Illegal character in the message!\n");
		return false;
	}

	//Проверка ключа на корректность
	for (int i = 1; i <= count; i++)
	{
		if (!((s_key[i] > '0') && (s_key[i] < '5')) || (s_key.Length() <= 2))
		{
			ShowMessage("Invalid key!\n");
			return false;
		}
	}

	//Вычисление размерности матрицы по ключу
	if ((int)sqrt(count * 4.0) * (int)sqrt(count * 4.0) == count * 4)
		n = (int)sqrt(count * 4.0);
	else if ((int)sqrt(count * 4.0 - 3.0) * (int)sqrt(count * 4.0) == (count * 4 - 3))
		n = (int)sqrt(count * 4.0 - 3.0);
	else
	{
		ShowMessage(L"Key error!");
		return false;
	}

	int* m_key = new int[count];

	//Перевод ключа в массив интов
	for (int i = 0; i < count; i++)
	{
		m_key[i] = s_key[i + 1] - '0';
	}

	int** matrix;

	//Создание первоначальной марицы
	matrix = trailing_grille_create_matrix(n);

	int** matr_template;

	//Создание матрицы-трафарета
	matr_template = trailing_grille_create_template(n, count, matrix, m_key);

	//Шифрование
	UnicodeString encrypted_message = trailing_grille_encrypt(n, matr_template, message);

	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(encrypted_message);

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	for (int i = 0; i < n; i++)
		delete[] matr_template[i];
	delete[] matr_template;

	delete[] m_key;

	return true;
}

bool trailing_grille_decryption(UnicodeString message, UnicodeString s_key)
{
	int count = s_key.Length();
	int n;

	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
        return false;
	}

	//Проверка ключа на корректность
	for (int i = 1; i <= count; i++)
	{
		if (!((s_key[i] > '0') && (s_key[i] < '5')) || (s_key.Length() <= 2))
		{
			ShowMessage("Invalid key!\n");
			return false;
		}
	}

	//Вычисление размерности матрицы по ключу
	if ((int)sqrt(count * 4.0) * (int)sqrt(count * 4.0) == count * 4)
		n = (int)sqrt(count * 4.0);
	else if ((int)sqrt(count * 4.0 - 3.0) * (int)sqrt(count * 4.0) == (count * 4 - 3))
		n = (int)sqrt(count * 4.0 - 3.0);
	else
	{
		ShowMessage(L"Key error!");
		return false;
	}

	int* m_key = new int[count];

	//Перевод ключа в массив интов
	for (int i = 0; i < count; i++)
	{
		m_key[i] = s_key[i + 1] - '0';
	}

	int** matrix;

	//Создание первоначальной марицы
	matrix = trailing_grille_create_matrix(n);

	int** matr_template;

	//Создание матрицы-трафарета
	matr_template = trailing_grille_create_template(n, count, matrix, m_key);

	//Шифрование
	UnicodeString decrypted_message = trailing_grille_decrypt(n, matr_template, message);

	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(decrypted_message);

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	for (int i = 0; i < n; i++)
		delete[] matr_template[i];
	delete[] matr_template;

	delete[] m_key;

	return true;
}