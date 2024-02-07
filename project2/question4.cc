// question4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int input, total, a, b, c;
    int ten = 10;
    cout << "Enter a 3 digit number ";
    cin >> input;
    __asm {
      mov eax, input;     // eax = input
      cdq;                // edx : eax = input
      idiv ten;           // eax = input / 10 -> 358/10
      mov a, edx;         // a = input % 10 358 % 10 gives a = 8

      mov eax, input;     // eax = input
      cdq;                // edx : eax = input
      idiv ten;           // eax = input/10 ,  edx = remainder, eax = input / 10  so 358/10 making ebx = 35.8
      cdq;               
      idiv ten;           // edx:ebx = input / 10  so 35/10, eax = 3.5
      mov b, edx;         // b = 35 % 10 so b = 5
      mov c, eax;         // eax hold the whole number from the number 3.5 so c = 3
        
      mov eax, a;         // eax = a
      add eax, b;         // eax = a + b
      add eax, c;         // eax = a + b + c
      mov total, eax;     // total = a + b + c
    }

    cout << "The total of digits in " << input << " is " << total << endl;
    return 0;
}
