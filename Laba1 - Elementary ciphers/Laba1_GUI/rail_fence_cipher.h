//---------------------------------------------------------------------------

#ifndef rail_fence_cipherH
#define rail_fence_cipherH
//---------------------------------------------------------------------------
#endif


int** rail_fence_create_map(int key, int size);
UnicodeString rail_fence_encrypt(UnicodeString message, int key);
UnicodeString rail_fence_decrypt(UnicodeString message, int key);
bool rail_fence_encryption(UnicodeString message, UnicodeString s_key);
bool rail_fence_decryption(UnicodeString message, UnicodeString s_key);