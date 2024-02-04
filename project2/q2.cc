#include <iostream>
using namespace std;

int main(){
  int a, b, c, h, length, width, t_area, t_perimeter, r_area, r_perimeter;
  int two = 2;
  cout << "Enter the values for a, b, c, and h for the triangle: ";
  cin >> a >> b >> c >> h;
  cout << "Enter the length and the width of the rectangle: ";
  cin >> length >> width;
  -asm {

    // Triangle Area
    mov eax,h; // eax = h
    imul b; // eax = b * h
    idiv two; // eax = b *h / 2
    mov t_area, eax;

    // Triangle Perimeter
    mov eax, a; // eax = a
    add eax, b; // eax = a + b
    add eax, c; // eax = a+b+c
    mov t_perimeter, eax; // t_perimeter = a+b+c

    // Rectangle Area
    mov eax, length;
    imul width;
    mov r_area, eax;

    // Rectangle Perimeter 2(15+10) or 2(15) + 2(10)
    mov eax, length;
    add eax, width;
    imul two;
    mov r_perimeter, eax;

  }
  cout << "       Triangle\n";
  cout << "             Area .................... " << t_area << endl;
  cout << "             Perimeter ............... " << t_perimeter << endl;

  cout << "       Rectangle\n";
  cout << "             Area .................... " << r_area << endl;
  cout << "             Perimeter ............... " << r_perimeter << endl;

}