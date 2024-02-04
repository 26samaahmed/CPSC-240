#include <iostream>
using namespace std;


int main(){
  int input1, input2, total, drink_total, sandwich_total;
  int two = 2;
  int four = 4;
  cout << "=============MENU===========\n";
  cout << "Drinks -------------------- $2\n";
  cout << "Sandwiches ---------------- $4\n";
  cout << "How many drinks? ";
  cin >> input1;
  cout << "How many sandwiches: ";
  cin >> input2;
  -asm {
    mov eax, input1; // eax = input1
    imul two;    // eax = input1 * 2
    mov drink_total, eax; // drink_total = input1 * 2

    mov eax, input2; // eax = input2
    imul four;    // eax = input2 * 4
    mov sandwich_total, eax; // sandwich_total = input1 * 2

    mov eax, drink_total;
    add eax, sandwich_total;
    mov total, eax;


  }
  cout << "Your total bill $" << total << endl;

}