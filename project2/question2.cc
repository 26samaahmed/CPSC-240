// question2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() {
    int a, b, c, h, lengths, widths, t_area, t_perimeter, r_area, r_perimeter;
    int two = 2;
    cout << "Enter the values for a, b, c, and h for the triangle: ";
    cin >> a >> b >> c >> h;
    cout << "Enter the length and the width of the rectangle: ";
    cin >> lengths >> widths;


    __asm{

        // Triangle Area
        mov eax,h;              // eax = h
        imul c;                 // eax = c * h
        idiv two;               // eax = c * h / 2
        mov t_area, eax;        // t_area = c * h / 2


        // Triangle Perimeter
        mov eax, a;             // eax = a
        add eax, b;             // eax = a + b
        add eax, c;             // eax = a + b + c
        mov t_perimeter, eax;   // t_perimeter = a + b + c


        // Rectangle Area
        mov eax, lengths;        // eax = lengths
        imul widths;             // eax = lengths * widths
        mov r_area, eax;        // r_area = lengths * widths


        // Rectangle Perimeter
        mov eax, lengths;        // eax = lengths
        add eax, widths;         // eax = lengths + width s
        add eax, eax;           // eax = 2(lengths) + 2(widths) 
        mov r_perimeter, eax;   // r_perimeter = 2(lengths) + 2(widths) 
    }

    cout << "       Triangle" << endl;
    cout << "             Area .................... " << t_area << endl;
    cout << "             Perimeter ............... " << t_perimeter << endl;

    cout << "       Rectangle" << endl;
    cout << "             Area .................... " << r_area << endl;
    cout << "             Perimeter ............... " << r_perimeter << endl;

}

  cout << "       Rectangle\n";
  cout << "             Area .................... " << r_area << endl;
  cout << "             Perimeter ............... " << r_perimeter << endl;

}
