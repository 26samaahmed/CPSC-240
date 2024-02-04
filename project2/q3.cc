#include <iostream>
using namespace std;


int main() {
  short celsius, fahrenheit;
  short thirty_two = 32;
  short five = 5;
  short nine = 9
  cout << "Enter temperature in Fahrenheit: ";
  cin >> fahrenheit;
  - asm {
    mov eax, fahrenheit;
    sub eax, thirty_two;
    imul 5;
    idiv 9;
    mov celsius, eax;

  }
  cout << fahrenheit << " F° is " << celsius << " C°\n";

}