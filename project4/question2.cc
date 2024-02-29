// project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

// BEEF has a total digit of 54 which is valid
// FADE has a total digit of 52 which is valid
// CABE has a total digit of 47 which is invalid

short sum, firstChar, secondChar, thirdChar, fourthChar;
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
        shr ax, 4;                  // ax = 0000000000001111
        mov thirdChar, ax;          // thirdChar = 0000000000001111


        mov ax, 0xBEEF;             // ax = 1011111011101111
        and ax, 0000000000101100b;  // Binary Number for B which is 11
        shr ax, 2;                  // ax = 0000000000001011
        mov fourthChar, ax;

        mov ax, firstChar;          // ax = firstChar
        add ax, secondChar;         // ax = firstChar + secondChar
        add ax, thirdChar;          // ax = firstChar + secondChar + thirdChar
        add ax, fourthChar;         // ax = firstChar + secondChar + thirdChar + fourthChar
        cwd;
        idiv two;                   // ax = (firstChar + secondChar + thirdChar + fourthChar) / 2
        mov sum, dx;                // store the remainder of the division operation.
        cmp sum, 0;                 // comparing the sum with 0
        Je Valid;                   // If they're equal, jump to Valid
        cmp sum, 0;                 
        Jne Invalid;                // If they are not equal, jump to Invalid


    Invalid:
        call displayInvalid

    Valid:
        call displayValid;


        // FADE
        mov sum, 0;                 // sum = 0;
        mov ax, 0xFADE;             // ax = 1111101011011110
        and ax, 0000000000001110b;  // Binary Number for E which is 14
        mov firstChar, ax;          // firstChar = ax which is E

        mov ax, 0xFADE;             // ax = 1111101011011110
        and ax, 0000000011010000b;  // Binary Number for D which is 13
        shr ax, 4;                  // ax = 0000000000001101
        mov secondChar, ax;         // secondChar = ax which is D

        mov ax, 0xFADE;             // ax = 1111101011011110
        and ax, 0000101000000000b;  // Binary Number for A which is 10
        shr ax, 8;                  // ax = 0000000000001010
        mov thirdChar, ax;          // thirdtChar = ax which is A
        

        mov ax, 0xFADE;             // ax = 1111101011011110
        and ax, 0000000000011110b;  // Binary Number for F which is 15
        shr ax, 1;                  // ax = 0000000000001111
        mov fourthChar, ax;         // fourthChar = ax which is F

        mov ax, firstChar;          // ax = firstChar
        add ax, secondChar;         // ax = firstChar + secondChar
        add ax, thirdChar;          // ax = firstChar + secondChar + thirdChar
        add ax, fourthChar;         // ax = firstChar + secondChar + thirdChar + fourthChar
        cwd;
        idiv two;                   // ax = (firstChar + secondChar + thirdChar + fourthChar) / 2
        mov sum, dx;                // store the remainder of the division operation.
        cmp sum, 0;                 // comparing the sum with 0
        Je Valid2;                  // If they're equal, jump to Valid
        cmp sum, 0;
        Jne Invalid2;               // If they are not equal, jump to Invalid


    Invalid2:
        call displayInvalid

    Valid2:
        call displayValid;

        // CABE
        mov sum, 0;                 // sum = 0;
        mov ax, 0xCABE;             // ax = 1100101010111110
        and ax, 0000000000001110b;  // Binary Number for E which is 14
        mov firstChar, ax;          // firsTChar = ax which is E


        mov ax, 0xCABE;             // ax = 1100101010111110
        and ax, 0000000010110000b;  // Binary Number for B which is 11
        shr ax, 4;                  // ax = 0000000000001011
        mov secondChar, ax;         // secondChar = ax which is B

        mov ax, 0xCABE;             // ax = 1100101010111110
        and ax, 0000001010000000b;  // Binary Number for A which is 10
        shr ax, 6;                  // ax = 0000000000001010
        mov thirdChar, ax;          // thirdChar = ax which is A

        mov ax, 0xCABE;             // ax = 1100101010111110
        and ax, 1100000000000000b;  // Binary Number for C which is 12
        shr ax, 12;                 // ax = 0000000000001100
        mov fourthChar, ax;         // fourthChar = ax which is C


        mov ax, firstChar;          // ax = firstChar
        add ax, secondChar;         // ax = firstChar + secondChar
        add ax, thirdChar;          // ax = firstChar + secondChar + thirdChar
        add ax, fourthChar;         // ax = firstChar + secondChar + thirdChar + fourthChar
        cwd;
        idiv two;                   // ax = (firstChar + secondChar + thirdChar + fourthChar) / 2
        mov sum, dx;                // store the remainder of the division operation.
        cmp sum, 0;                 // comparing the sum with 0
        Je Valid3;                  // If they're equal, jump to Valid
        cmp sum, 0;
        Jne Invalid3;               // If they are not equal, jump to Invalid

    Valid3:
        call displayValid;

    Invalid3:
        call displayInvalid;

    }

    return 0;
}
