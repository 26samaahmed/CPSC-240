#include <iostream>
using namespace std;
int main(){
  short n = 567;
  short hundred = 100;
  short ten = 10;
  short d3, d2, d1, r;
  _asm {
    // Digit 3
    mov ax, n;
    cwd;
    idiv hundred;
    mov d3, ax;

    // Digit 2
    mov ax, dx;
    cwd;
    idiv ten;
    mov d2, ax;

    // Digit 1
    mov ax, dx;
    mov d1, ax;

    // Sum of digits
    add ax, d2;
    add ax, d3;
    mov r, ax;
  }
  cout << "r = " << r << endl;
}