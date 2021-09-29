//---------------------------------------------------------------------------

#ifndef columnH
#define columnH
//---------------------------------------------------------------------------
#endif

typedef struct KeyPair
{
    char elem;
    int index;
} TKeyPair;

void column_sort_key(TKeyPair* key, int n);
int* column_create_key(UnicodeString key);
int column_find_elem(int* arr, int elem, int n);
UnicodeString column_encrypt(UnicodeString message, int* key, int key_len);
UnicodeString column_decrypt(UnicodeString message, int* key, int key_len);
bool column_encryption(UnicodeString message, UnicodeString s_key);
bool column_decryption(UnicodeString message, UnicodeString s_key);
