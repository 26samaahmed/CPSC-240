// question1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    short sandwiches, drinks, total, drink_total, sandwich_total;
    short two = 2;
    short four = 4;
    cout << setfill('-') << setw(18) << '-' << "MENU" << setfill('-') << setw(18) << '-' << endl;
    cout << "Drinks" << setfill('.') << setw(33) << ".$" << two << endl;
    cout << "Sandwiches" << setfill('.') << setw(29) << ".$" << four << endl;
    cout << "How many drinks? ";
    cin >> drinks;
    cout << "How many sandwiches: ";
    cin >> sandwiches;
    __asm {
        mov ax, drinks;                // eax = drinks
        imul two;                       // eax = drinks * 2
        mov drink_total, ax;           // drink_total = drinks * 2
        
        mov ax, sandwiches;            // eax = sandwiches
        imul four;                      // eax = sandwiches * 4
        mov sandwich_total, ax;        // sandwich_total = sandwiches * 4

        mov ax, drink_total;           // eax = drink_total
        add ax, sandwich_total;        // eax = drink_total + sandwich_total
        mov total, ax;                 // eax = drink_total + sandwich_total

    }
    cout << "Your total bill $" << total << endl;

}