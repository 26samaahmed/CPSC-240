// question4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    short a, b, c, d, e, f, X, Y, y_denominator, x_denominator;
    cout << "Enter the values of a, b, c: ";
    cin >> a >> b >> c;
    cout << "Enter the values of d, e, f: ";
    cin >> d >> e >> f;
    __asm {
        // Calculate Y's denominator first
        mov ax, e;              // ax = e
        imul a;                 // ax = e * a
        mov bx, b;              // bx = b
        imul d;                 // bx = b * d
        sub ax, bx;             // ax = e * a - b * d
        mov y_denominator, ax;  // y_denominator = e * a - b * d

        // Calculate Y's numerator and divide by denominator
        mov ax, f;              // ax = f
        imul a;                 // ax = f * a
        mov bx, c;              // bx = c
        imul d;                 // bx = c * d
        sub ax, bx;             // ax = a * f - c * d
        idiv y_denominator;     // ax = a * f - c * d / e * a - b * d
        mov Y, ax;

        // Calculate X's denominator first
        mov ax, e;              // ax = e
        imul a;                 // ax = e * a
        mov bx, b;              // bx = b
        imul d;                 // bx = b * d
        sub ax, bx;             // ax = e * a - b * d
        mov x_denominator, ax;  // x_denominator = e * a - b * d

        // Calculate X's numerator and divide by denominator
        mov ax, e;              // ax = e
        imul c;                 // ax = c * e
        mov bx, b;              // bx = b
        imul f;                 // bx = b * f
        sub ax, bx;             // ax = c * e - b * f
        idiv x_denominator;     // ax = c * e - b * f / e * a - b * d
        mov X, ax;              // X = c * e - b * f / e * a - b * d


    }

    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;
    return 0;
}