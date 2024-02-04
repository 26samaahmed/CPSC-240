#include <iostream>
using namespace std;


int main() {
  int input, total, a, b, c;
  int ten = 10;
  cout << "Enter a 3 digit number ";
  cin >> input;
  -asm {
    mov eax, input;
    idiv ten; // eax = input / 10
    mov a, edx;


    idiv ten;
    mov b, edx;

    idiv ten;
    mov c, edx;
    add eax, a; 
    add eax, b; 
    add eax, c; // eax = a+b+c
    mov total, eax;

  }
  cout << "The total of the 3 digits in " << input << " is " << total << endl;
}