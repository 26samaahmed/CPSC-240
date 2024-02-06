// question4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main() {
    int input, total, a, b, c;
    int ten = 10;
    cout << "Enter a 3 digit number ";
    cin >> input;
    __asm{
      mov eax, input;     // eax = input
      cwd;
      idiv ten;           // eax = input / 10
      mov a, edx;         // a = input % 10 this should make a = 8 if the input is 358


      mov ebx, input;     // ebx = input
      cwd;
      idiv ten;           // ebx = input / 10 so ebx = 35
      idiv ten;           // ebx = input / 10 so ebx = 3.5 and edx = 5
      mov b, edx;         // b = 25 % 10 this should make b = 5 if the input is 358

        


      mov ecx, a;
      add ecx, b;
      mov total, ecx;

    }
    cout << "The total of the 3 digits in " << input << " is " << total << endl;
}
