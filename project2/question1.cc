// question1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main() {
    short sandwiches, drinks, total, drink_total, sandwich_total;
    short two = 2;
    short four = 4;
    cout << "=============MENU===========\n";
    cout << "Drinks -------------------- $2\n";
    cout << "Sandwiches ---------------- $4\n";
    cout << "How many drinks? ";
    cin >> drinks;
    cout << "How many sandwiches: ";
    cin >> sandwiches;
    __asm {
        mov eax, drinks;                // eax = drinks
        imul two;                       // eax = drinks * 2
        mov drink_total, eax;           // drink_total = drinks * 2
        
        mov eax, sandwiches;            // eax = sandwiches
        imul four;                      // eax = sandwiches * 4
        mov sandwich_total, eax;        // sandwich_total = sandwiches * 4

        mov eax, drink_total;           // eax = drink_total
        add eax, sandwich_total;        // eax = drink_total + sandwich_total
        mov total, eax;                 // eax = drink_total + sandwich_total


    }
    cout << "Your total bill $" << total << endl;

}
