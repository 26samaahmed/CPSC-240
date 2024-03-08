// project 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a, b, c, h, lengths, widths, t_area, t_perimeter, r_area, r_perimeter = 0;
    float two = 2;
    cout << "Enter the values for a, b, c, and h for the triangle: ";
    cin >> a >> b >> c >> h;
    cout << "Enter the length and the width of the rectangle: ";
    cin >> lengths >> widths;

    __asm {
        // Triangle Area
        fld c;          // st[0] = c
        fld h;          // st[0] = h, st[1] = c
        fmul;           // st[0] = c * h
        fld two;        // st[0] = 2, st[1] = c * h
        fdiv;           // st[0] = c * h / 2
        fstp t_area;    // t_area = c * h / 2
        
        // Triangle Perimeter
        fld a;              // st[0] = a
        fld b;              // st[0] = b, st[1] = a
        fadd;               // st[0] a + b
        fld c;              // st[1] = c, st[0] = a + b
        fadd;               // st[0] = a + b + c
        fstp t_perimeter;   // t_perimeter = a + b + c
        
        // Rectangle Area
        fld lengths;        // st[0] = lengths
        fld widths;         // st[0] = widths, st[1] = lengths
        fmul;               // st[0] = lengths * widths
        fstp r_area;        // r_area = lengths * widths
        
        // Rectangle Perimeter
        fld lengths;        // st[0] = lengths
        fld widths;         // st[0] = widths, st[1] = lengths
        fadd;               // st[0] = lengths + widths
        fld two;            // st[0] = 2, st[1] = lengths + widths
        fmul;               // st[0] = 2 * (lengths + widths)
        fstp r_perimeter;   // r_perimeter = 2 * (lengths + widths)
    }
    
    cout << setfill(' ') << setw(16) << " Triangle" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << setfill(' ') << setw(20) << " Area" << setfill('.') << setw(20) << t_area << endl;
    cout << setfill(' ') << setw(25) << " Perimeter" << setfill('.') << setw(15) << t_perimeter << endl;

    cout << setfill(' ') << setw(17) << " Rectangle" << endl;
    cout << setfill(' ') << setw(20) << " Area" << setfill('.') << setw(20) << r_area << endl;
    cout << setfill(' ') << setw(25) << " Perimeter" << setfill('.') << setw(15) << r_perimeter << endl;
    
    return 0;
}
