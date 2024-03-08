// project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float input, X1, X2, a, b, c = 0;
    float four = 4;
    float two = 2;
    float one = -1;
    cout << "To see the two real roots of aX^2+ bX + c=0, enter the a,b, and c values: ";
    cin >> a >> b >> c;

    __asm {
        // Calculate X1
        fld b;          // st[0] = b
        fld one;        // st[0] = -1, st[1] = b
        fmul;           // st[0] = -b
        fld b;          // st[0] = b, st[1] = -b
        fld b;          // st[0] = b, st[1] = b, st[2] = -b
        fmul;           // st[0] = b^2, st[1] = -b
        fld four;       // st[0] = 4, st[1] = b^2, st[2] = -b
        fld a;          // st[0] = a, st[1] = 4, st[2] = b^2, st[3] = -b
        fmul;           // st[0] = 4a, st[1] = b^2, st[2] = -b
        fld c;          // st[0] = c, st[1] = 4a, st[2] = b^2, st[3] = -b
        fmul;           // st[0] = 4ac, st[1] = b^ 2, st[2] = -b
        fsub;           // st[0] = b^2 - 4ac, st[1] = -b
        fsqrt;          // st[0] = sqrt(b^2 - 4ac), st[1] = -b
        fadd;           // st[0] = -b + sqrt(b^2 - 4ac)
        fld two;        // st[0] = 2, st[1] = -b + sqrt(b^2 - 4ac)
        fld a;          // st[0] = a, st[1] = 2, st[2] = -b + sqrt(b^2 - 4ac)
        fmul;           // st[0] = 2a, st[1] = -b + sqrt(b^2 - 4ac)
        fdiv;           // st[0] = (-b + sqrt(b^2 - 4ac)) / 2a(-b + sqrt(b^2 - 4ac)) / 2a
        fstp X1;        // X1 = (-b + sqrt(b^2 - 4ac)) / 2a
        
        
        // Calculate X2
        fld b;          // st[0] = b
        fld one;        // st[0] = -1, st[1] = b
        fmul;           // st[0] = -b
        fld b;          // st[0] = b, st[1] = -b
        fld b;          // st[0] = b, st[1] = b, st[2] = -b
        fmul;           // st[0] = b^2, st[1] = -b
        fld four;       // st[0] = 4, st[1] = b^2, st[2] = -b
        fld a;          // st[0] = a, st[1] = 4, st[2] = b^2, st[3] = -b
        fmul;           // st[0] = 4a, st[1] = b^2, st[2] = -b
        fld c;          // st[0] = c, st[1] = 4a, st[2] = b^2, st[3] = -b
        fmul;           // st[0] = 4ac, st[1] = b^ 2, st[2] = -b
        fsub;           // st[0] = b^2 - 4ac, st[1] = -b
        fsqrt;          // st[0] = sqrt(b^2 - 4ac), st[1] = -b
        fsub;           // st[0] = -b - sqrt(b^2 - 4ac)
        fld two;        // st[0] = 2, st[1] = -b - sqrt(b^2 - 4ac)
        fld a;          // st[0] = a, st[1] = 2, st[2] = -b - sqrt(b^2 - 4ac)
        fmul;           // st[0] = 2a, st[1] = -b - sqrt(b^2 - 4ac)
        fdiv;           // st[0] = (-b + sqrt(b^2 - 4ac)) / 2a(-b - sqrt(b^2 - 4ac)) / 2a
        fstp X2;        // X1 = (-b - sqrt(b^2 - 4ac)) / 2a
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "X1= " << X1 << endl;
    cout << "X2= " << X2 << endl;
    return 0;
}
