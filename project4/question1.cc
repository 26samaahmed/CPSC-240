// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short numOfPrinters;

void displayPrinters() {
    cout << "The number of printers connected is " << numOfPrinters << endl;
}

int main()
{
    __asm {
        mov ax, 00111010011100;
        mov bx, 110000000000000b;   // bit 15 and 16 are for the printer
        and ax, bx;
        shr ax, 14;                 // would give 000000000000011 -> this is 3's binary number
        mov numOfPrinters, ax;      // numOfPrinters = 3
        call displayPrinters;

    }
}
