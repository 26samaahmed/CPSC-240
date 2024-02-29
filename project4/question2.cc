// project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

// BEEF has a total digit of 54 which is valid
// FADE has a total digit of 52 which is valid
// CABE has a total digit of 47 which is invalid

short sum, firstChar, secondChar, thirdChar, fourthChar, result1;
short two = 2;

void displayValid() {
    cout << "This is a valid ID for the family\n";
}

void displayInvalid() {
    cout << "This is not a valid ID for the family\n";
}


int main()
{
    __asm {
        // BEEF
        mov sum, 0;                 // sum = 0;
        mov ax, 0xBEEF;             // 0x indicates hexadecimal so ax = BEEF whose binary number is 1011111011101111
        and ax, 0000000000001111b;  // Binary Number for F which is 15
        mov firstChar, ax;          // firstChar = ax which is F


        mov ax, 0xBEEF;             // ax = 1011111011101111
        and ax, 0000000011110000b;  // Binary Number for E
        shr ax, 4;                  // ax = 0000000000001110
        mov secondChar, ax;         // secondChar = 0000000000001110
        

        mov ax, 0xBEEF;             // ax = 1011111011101111
        and ax, 0000000011110000b;  // Binary Number for E which is 14
        shr ax, 4;
        mov thirdChar, ax;


        mov ax, 0xBEEF;             //  ax = 1011111011101111
        and ax, 0000000000101100b;  // Binary Number for B which is 11
        shr ax, 2;
        mov fourthChar, ax;

        mov ax, firstChar;
        add ax, secondChar;
        add ax, thirdChar;
        add ax, fourthChar;
        cwd;
        idiv two;
        mov result1, dx;             // store the remainder of the division operation.
        cmp result1, 0;
        Je Valid;


    Valid:
        call displayValid;

        // FADE
        mov sum, 0;                 // sum = 0;
        mov ax, 0xFADE;             // 0x indicates hexadecimal so ax = FADE whose binary number is 1111101011011110
        and ax, 0000000011110000b;  // Binary Number for E which is 14
        shr ax, 4;
        mov firstChar, ax;          

        mov ax, 0xFADE;                   // 1111101011011110
        and ax, 0000000011010000b;       // 0000000000001101
        shr ax, 4;
        mov secondChar, ax;
        



        // CABE

    }
    cout << firstChar << "     " << secondChar << endl;
}
