//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include <System.SysUtils.hpp>

#include "column.h"
#include "laba1.h"

#include <windows.h>
#include <locale.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

//---------------------------------------------------------------------------
#pragma package(smart_init)


//Преобразование ключа в порядок чтения столбцов
int* column_create_key(UnicodeString key)
{
	int count = key.Length();

	TKeyPair* tmp = new TKeyPair[count];
	for (int i = 0; i < count; i++)
	{
		tmp[i].elem = key[i + 1];
		tmp[i].index = i;
	}

	column_sort_key(tmp, key.Length());

	int* res = new int[count];
	for (int i = 0; i < count; i++)
	{
		res[tmp[i].index] = i;
	}

	delete[] tmp;

	return res;
}

//Сортировка ключа
void column_sort_key(TKeyPair* key, int n)
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

//Создание карты шифрования
int** column_create_map(int* key, int key_len, int size)
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
		j = column_find_elem(key, step, width);

		while ((i < height) && (i * width + j < size))
		{
			map[i][j] = position;
			position++;
			i++;
		}
	}

	return map;
}

//Поиск элемента в массиве
int column_find_elem(int* arr, int elem, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == elem) return i;
	}

	return -1;
}

//Шифрование
UnicodeString column_encrypt(UnicodeString message, int* key, int key_len)
{
	int mes_len = message.Length();
	int** map = column_create_map(key, key_len, mes_len);

	int width = key_len;
	int height = mes_len / width + 1;
	int count = 1;

	wchar_t* encrypted_message_c = new wchar_t[mes_len + 1];
	for (int i = 0; i < mes_len + 1; i++)
		encrypted_message_c[i] = '\0';

	UnicodeString encrypted_message("");

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
UnicodeString column_decrypt(UnicodeString message, int* key, int key_len)
{
	int mes_len = message.Length();
	int** map = column_create_map(key, key_len, mes_len);

	int width = key_len;
	int height = mes_len / width + 1;

	UnicodeString decrypted_message("");

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (map[i][j] != -1)
				decrypted_message = decrypted_message + message[map[i][j] + 1];

	for (int i = 0; i < height; i++)
		delete[] map[i];
	delete[] map;

	return decrypted_message;
}


bool column_encryption(UnicodeString message, UnicodeString s_key)
{
	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
		return false;
	}

	s_key = s_key.UpperCase();

	if (s_key.Length() <= 1)
	{
		ShowMessage("Invalid key!");
		return false;
	}

	int* m_key = column_create_key(s_key);

	UnicodeString encrypted_message = column_encrypt(message, m_key, s_key.Length());
	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(encrypted_message);

	delete[] m_key;
	return true;
}

bool column_decryption(UnicodeString message, UnicodeString s_key)
{
    if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
		return false;
	}

	s_key = s_key.UpperCase();

	if (s_key.Length() <= 1)
	{
		ShowMessage("Invalid key!");
		return false;
	}

	int* m_key = column_create_key(s_key);

	UnicodeString decrypted_message = column_decrypt(message, m_key, s_key.Length());

	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(decrypted_message);

	delete[] m_key;
	return true;
}