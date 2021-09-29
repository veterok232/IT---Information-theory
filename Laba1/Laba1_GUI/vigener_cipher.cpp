//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include <System.SysUtils.hpp>

#include "vigener_cipher.h"
#include "laba1.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)


bool vigener_in_alphabet(wchar_t symb)
{
	if (alphabet.Pos(symb) != 0)
		return true;
    else
        return false;
}

UnicodeString vigener_create_key(UnicodeString input_key, UnicodeString message)
{
	UnicodeString key = input_key;

	while (key.Length() < message.Length())
	{
        key.Insert(input_key, key.Length() + 1);
    }

	while (input_key.Length() > message.Length())
	{
        key.Delete(key.Length(), 1);
    }

    return key;
}

UnicodeString vigener_encrypt(UnicodeString message, UnicodeString key)
{
	UnicodeString encrypted_message;
	int message_len = message.Length();
	int indexI, indexJ;

	for (int i = 1; i <= message_len; i++)
	{
		indexI = key[i] - 'A';
		indexJ = message[i] - 'A';
		encrypted_message = encrypted_message + alphabet[(indexI + indexJ) % alphabet.Length() + 1];
	}

	return encrypted_message;
}

UnicodeString vigener_decrypt(UnicodeString message, UnicodeString key)
{
	UnicodeString decrypted_message;
	int message_len = message.Length();
	int indexI, indexJ;

	for (int i = 1; i <= message_len; i++)
	{
		indexI = key[i] - 'A';
		indexJ = message[i] - 'A';
		decrypted_message = decrypted_message + alphabet[(indexJ - indexI + alphabet.Length()) % alphabet.Length() + 1];
	}

	return decrypted_message;
}


bool vigener_encryption(UnicodeString message, UnicodeString s_key)
{
	if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
		return false;
	}

	//Перевод в верхний регистр
	message = message.UpperCase();
	s_key = s_key.UpperCase();

	int currPos = 1;

	//Проверка ключа на корректность
	while (currPos <= s_key.Length())
	{
		if (!vigener_in_alphabet(s_key[currPos]))
		{
			ShowMessage(L"Invalid key!\n");
			return false;
		}
		currPos++;
	}

	currPos = 1;

	//Удаление всех символов не из алфавита
	while (currPos <= message.Length())
	{
		if (!vigener_in_alphabet(message[currPos]))
		{
			message.Delete(currPos, 1);
			continue;
		}
		currPos++;
	}

	//Создание ключа
	s_key = vigener_create_key(s_key, message);

	//Шифрование
	UnicodeString encrypted_message = vigener_encrypt(message, s_key);
	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(encrypted_message);

	return true;
}

bool vigener_decryption(UnicodeString message, UnicodeString s_key)
{
    if (message.Length() == 0)
	{
		ShowMessage(L"Empty message");
		return false;
	}

	//Перевод в верхний регистр
	message = message.UpperCase();
	s_key = s_key.UpperCase();

	int currPos = 1;

	//Проверка ключа на корректность
	while (currPos <= s_key.Length())
	{
		if (!vigener_in_alphabet(s_key[currPos]))
		{
			ShowMessage(L"Invalid key!\n");
			return false;
		}
		currPos++;
	}

	currPos = 1;

	//Удаление всех символов не из алфавита
	while (currPos <= message.Length())
	{
		if (!vigener_in_alphabet(message[currPos]))
		{
			message.Delete(currPos, 1);
			continue;
		}
		currPos++;
	}

    //Создание ключа
	s_key = vigener_create_key(s_key, message);

	//Шифрование
	UnicodeString decrypted_message = vigener_decrypt(message, s_key);
	frmMain->resultMessageField->Lines->Clear();
	frmMain->resultMessageField->Lines->Add(decrypted_message);

    return true;
}