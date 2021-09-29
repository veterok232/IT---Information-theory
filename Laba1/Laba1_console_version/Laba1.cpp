#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

#include "column.h"
#include "rail_fence_cipher.h"
#include "Trailing_grille_cipher.h"
#include "vigener_cipher.h"

using namespace std;

void show_main_menu();
bool rail_fence_cipher();
bool column_cipher();
bool trailing_grille_cipher();
bool vigener_cipher();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    show_main_menu();

    int command;
    char command_c[255];

    do
    {
        bool is_correct;

        printf("Enter the command(main menu): ");
        (cin >> command).get();
        if (cin.fail())
        {
            command = 100;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        printf("\n");

        switch (command)
        {
        case 1:
            printf("--------Rail-fence cipher--------\n");
            do
            {
                is_correct = rail_fence_cipher();
            } while (!is_correct);
            break;
        case 2:
            printf("----------Column cipher----------\n");
            do
            {
                is_correct = column_cipher();
            } while (!is_correct);
            break;
        case 3:
            printf("----------Trailing-grille cipher----------\n");
            do
            {
                is_correct = trailing_grille_cipher();
            } while (!is_correct);
            break;
        case 4:
            printf("----------Vigener's cipher----------\n");
            do
            {
                is_correct = vigener_cipher();
            } while (!is_correct);
            break;
        case 5:
            show_main_menu();
            break;
        case 0:
            printf("Выход..\n");
            break;
        default:
            printf("Unknown command!\n");
        }
    }
    while (command != 0);

    return 0;
}

void show_main_menu()
{
    printf("------------Main menu-------------\n");
    printf("1. Rail-fence method\n");
    printf("2. Column method\n");
    printf("3. Trailing-grille method\n");
    printf("4. Viginer's method\n");
    printf("5. Show main menu\n");
    printf("0. Exit\n\n");
}

bool rail_fence_cipher()
{
    int command;
    bool is_correct;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("0. Exit\n\n");

    do
    {
        command = 0;
        printf("Enter the command(Rail-fence): ");
        (cin >> command).get();
        if (cin.fail())
        { 
            command = 100;
            cin.clear();
            cin.ignore(32767, '\n');
        }
            
        printf("\n");

        switch (command)
        {
        case 1:
            printf("--------Encryption--------\n");
            do
            {
                is_correct = rail_fence_encryption();
            } while (!is_correct);
            break;
        case 2:
            printf("--------Decryption--------\n");
            do
            {
                is_correct = rail_fence_decryption();
            } while (!is_correct);
            break;
        case 0:
            break;
        default:
            printf("Unknown command!\n");
        }
    } while (command != 0);

    return true;
}

bool column_cipher()
{
    int command;
    bool is_correct;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("0. Exit\n\n");

    do
    {
        printf("Enter the command(Column): ");
        (cin >> command).get();
        if (cin.fail())
        {
            command = 100;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        printf("\n");

        switch (command)
        {
        case 1:
            printf("--------Encryption--------\n");
            do
            {
                is_correct = column_encryption();
            } while (!is_correct);
            break;
        case 2:
            printf("--------Decryption--------\n");
            do
            {
                is_correct = column_decryption();
            } while (!is_correct);
            break;
        case 0:
            break;
        default:
            printf("Unknown command!\n");
        }
    } while (command != 0);

    return true;
}

bool vigener_cipher()
{
    int command;
    bool is_correct;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("0. Exit\n\n");

    do
    {
        printf("Enter the command(Viginer's): ");
        (cin >> command).get();
        if (cin.fail())
        {
            command = 100;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        printf("\n");

        switch (command)
        {
        case 1:
            printf("--------Encryption--------\n");
            printf("Input ONLY in English!\n\n");
            do
            {
                is_correct = vigener_encryption();
            } while (!is_correct);
            break;
        case 2:
            printf("--------Decryption--------\n");
            printf("Input ONLY in English!\n\n");
            do
            {
                is_correct = vigener_decryption();
            } while (!is_correct);
            break;
        case 0:
            break;
        default:
            printf("Unknown command!\n");
        }
    } while (command != 0);

    return true;
}

bool trailing_grille_cipher()
{
    int command;
    bool is_correct;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("0. Exit\n\n");

    do
    {
        printf("Enter the command(Trailing-grille): ");
        (cin >> command).get();
        if (cin.fail())
        {
            command = 100;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        printf("\n");

        switch (command)
        {
        case 1:
            printf("--------Encryption--------\n");
            do
            {
                is_correct = trailing_grille_encryption();
            } while (!is_correct);
            break;
        case 2:
            printf("--------Decryption--------\n");
            do
            {
                is_correct = trailing_grille_decryption();
            } while (!is_correct);
            break;
        case 0:
            break;
        default:
            printf("Unknown command!\n");
        }
    } while (command != 0);

    return true;
}