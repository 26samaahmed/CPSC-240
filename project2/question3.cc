// question3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main() {
    short celsius, fahrenheit;
    short thirty_two = 32;
    short five = 5;
    short nine = 9;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    __asm{
      mov ax, fahrenheit;       // ax = fahrenheit
      sub ax, thirty_two;       // ax = fahrenheit - 32
      imul five;                // ax = 5* (fahrenheit - 32)
      cwd;                      // dx: ax =  5* (fahrenheit - 32)
      idiv nine;                // ax = 5* (fahrenheit - 32) / 9
      mov celsius, ax;          // celsius = 5* (fahrenheit - 32) / 9

    }
    cout << fahrenheit << " F° is " << celsius << " C°\n";

}
