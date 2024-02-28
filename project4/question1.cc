// project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short numOfPrinters, numOfDrives, ramSize;

void displayPrinters() {
    cout << "The number of printers connected = " << numOfPrinters << endl;
}

void displayFloppyDrives() {
    cout << "The number of floppy drives connected = " << numOfDrives << endl;
}

void displayRamSize() {
    cout << "The size of the RAM = " << ramSize << " GB RAM" << endl;
}

int main()
{
    __asm {
        // calculate number of printers
        mov ax, 1100111010011100b;
        mov bx, 1100000000000000b;   // bit 15 and 16 are for the printer
        and ax, bx;                  // ax = 110000000000000
        shr ax, 14;                  // would give 000000000000011 -> this is 3's binary number
        mov numOfPrinters, ax;       // numOfPrinters = 3
        call displayPrinters;

        // calculate number of floppy drives
        mov ax, 1100111010011100b;
        mov bx, 0000000011000000b;   // bit 7 and 8 are for the printer
        and ax, bx;                  // ax = 0000000010000000
        shr ax, 7;                   // ax = 0000000000000001
        mov numOfDrives, ax;         // numOfDrives = 1
        call displayFloppyDrives;


        // calculate the size of the ram
        mov ax, 1100111010011100b;
        mov bx, 0000000000001100b;    // bit 3 and 4 are for the ram size
        and ax, bx;                   // ax = 0000000000001100
        shr ax, 2;                    // ax = 0000000000000011
        cmp ax, 00b;                  // compare the value of ax with 00b
        Je Zero;                      // if they're equal then jump to Zero
        cmp ax, 01b;                  // compare the value of ax with  01b
        Je One;                       // if they're equal then jump to One
        cmp ax, 10b;                  // compare the value of ax with 10b
        Je Two;                       // if they're equal then jump to Two
        cmp ax, 11b;                  // compare the value of ax with 11b
        Je Three;                     // if they're equal then jump to Three

    Zero:
        mov ax, 16;
        mov ramSize, ax;              // ramSize = 16
        call displayRamSize;

    One:
        mov ax,32;
        mov ramSize, ax;              // ramSize = 32
        call displayRamSize;

    Two:
        mov ax, 48;
        mov ramSize, ax;              // ramSize = 48
        call displayRamSize;

    Three:
        mov ax, 64;
        mov ramSize, ax;              // ramSize = 64
        call displayRamSize;
    }
}
