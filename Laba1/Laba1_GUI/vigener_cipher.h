//---------------------------------------------------------------------------

#ifndef vigener_cipherH
#define vigener_cipherH
//---------------------------------------------------------------------------
#endif


//Алфавит
const UnicodeString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool vigener_in_alphabet(wchar_t symb);
UnicodeString vigener_create_key(UnicodeString key, UnicodeString message);
UnicodeString vigener_encrypt(UnicodeString message, UnicodeString key);
UnicodeString vigener_decrypt(UnicodeString message, UnicodeString key);
bool vigener_encryption(UnicodeString message, UnicodeString s_key);
bool vigener_decryption(UnicodeString message, UnicodeString s_key);
