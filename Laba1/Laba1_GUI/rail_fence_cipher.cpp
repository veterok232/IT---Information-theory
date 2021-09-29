//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include <System.SysUtils.hpp>

#include "rail_fence_cipher.h"
#include "laba1.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//using namespace std;

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
UnicodeString rail_fence_encrypt(UnicodeString message, int key)
{
	int** map = rail_fence_create_map(key, message.Length());
	int width = message.Length() / key + 5;

	UnicodeString encrypted_message("");

	for (int i = 0; i < key; i++)
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == -1) break;
			encrypted_message = encrypted_message + message[map[i][j] + 1];
		}

	for (int i = 0; i < key; i++)
		delete[] map[i];
	delete[] map;

	return encrypted_message;
}

//Дешифрование
UnicodeString rail_fence_decrypt(UnicodeString message, int key)
{
	int** map = rail_fence_create_map(key, message.Length());
	int width = message.Length() / key + 5;

	wchar_t* decrypted_message_c = new wchar_t[message.Length() + 1];

	for (int i = 0; i < message.Length() + 1; i++)
		decrypted_message_c[i] = '\0';

	UnicodeString decrypted_message("");

	int count = 1;

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

bool rail_fence_encryption(UnicodeString message, UnicodeString s_key)
{
	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message!");
		return false;
	}

	int key;

	try
	{
		key = StrToInt(s_key);
	}
	catch (EConvertError &E)
	{
		ShowMessage(L"Invalid key!");
		return false;
	}

	if (key < 2)
	{
		ShowMessage(L"Invalid key!");
		return false;
	}

	int** map;

	UnicodeString encrypted_message = rail_fence_encrypt(message, key);
	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(encrypted_message);
	return true;
}

bool rail_fence_decryption(UnicodeString message, UnicodeString s_key)
{
	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message!");
		return false;
	}

	int key;

	try {
		key = StrToInt(s_key);
	}
	catch (EConvertError &E)
	{
		ShowMessage(L"Invalid key!");
		return false;
	}

	if (key < 2)
	{
		ShowMessage(L"Invalid key!");
		return false;
	}

	int** map;

	UnicodeString decrypted_message = rail_fence_decrypt(message, key);
    frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(decrypted_message);
	return true;
}