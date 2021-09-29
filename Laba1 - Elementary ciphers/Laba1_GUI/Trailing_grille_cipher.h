//---------------------------------------------------------------------------

#ifndef Trailing_grille_cipherH
#define Trailing_grille_cipherH
//---------------------------------------------------------------------------
#endif


int** trailing_grille_create_matrix(int);
int** trailing_grille_create_template(int, int, int**, int*);
UnicodeString trailing_grille_encrypt(int n, int** matr_template, UnicodeString message);
UnicodeString trailing_grille_decrypt(int n, int** matr_template, UnicodeString message);
bool trailing_grille_encryption(UnicodeString message, UnicodeString s_key);
bool trailing_grille_decryption(UnicodeString message, UnicodeString s_key);
