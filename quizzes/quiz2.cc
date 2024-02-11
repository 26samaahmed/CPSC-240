#include <iostream>
using namespace std;
int main()
{
  short a, b, c, result, remainder, denominator;
  short two_hundred = 200;
  cout << "Please enter your input for a, b, c: " << endl;
  cin >> a >> b >> c;
  __asm {

    // Calculate denominator (Note: a^3 = a * a * a)
    mov ax, a;              // ax = a
    imul ax, a;             // ax = a * a
    imul ax, a;             // ax = a * a * a
    imul ax, b;             // ax = a * a * a * b
    mov denominator, ax;    // move ax into the var denominator so that i can use it to divide after i find the numerator,  denominator = a * a * a * b

    // Calculate numerator
    mov ax, a;              // ax = a
    imul b;                 // ax = a * b
    add ax, c;              // ax = c + a * b
    imul two_hundred;       // ax = 200*(c + a * b)


    //divide numerator by denominator
    cwd;
    idiv denominator;       // dx:ax = 200*(c + a * b) / a * a * a * b
    mov result, ax;         // result = 200*(c + a * b) / a * a * a * b
    mov remainder, dx;      // remainder = 200*(c + a * b) / a * a * a * b
  }

  cout << "result= " << result << endl;
  cout << "remainder= " << remainder << endl;
}
