//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#pragma hdrstop

#include "laba1.h"
#include "rail_fence_cipher.h"
#include "column.h"
#include "trailing_grille_cipher.h"
#include "vigener_cipher.h"

using namespace std;

const _RAIL_FENCE      = 0;
const _COLUMN          = 1;
const _TRAILING_GRILLE = 2;
const _VIGENER         = 3;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnStartClick(TObject *Sender)
{
	UnicodeString message(sourceMessageField->Text);
	UnicodeString key = keyField->Text;

	if (rbtnEncrypt->Checked)
	{
		switch (cboxSelectMethod->ItemIndex)
		{
		case _RAIL_FENCE:
			rail_fence_encryption(message, key);
			break;
		case _COLUMN:
			column_encryption(message, key);
			break;
		case _TRAILING_GRILLE:
			trailing_grille_encryption(message, key);
			break;
		case _VIGENER:
			vigener_encryption(message, key);
			break;
		default:
			break;
		}
	}
	else if (rbtnDecrypt->Checked)
	{
		switch (cboxSelectMethod->ItemIndex)
		{
		case _RAIL_FENCE:
			rail_fence_decryption(message, key);
			break;
		case _COLUMN:
			column_decryption(message, key);
			break;
		case _TRAILING_GRILLE:
			trailing_grille_decryption(message, key);
			break;
		case _VIGENER:
			vigener_decryption(message, key);
			break;
		default:
			break;
		}
	}

}
//---------------------------------------------------------------------------
