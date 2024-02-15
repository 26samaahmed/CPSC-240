/ question1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

short number_of_customers, num_of_drinks, num_of_sandwiches, sandwich_size, total, counter, drink_total, sandwich_total;
char  drink_type;
short soda_price = 2;
short water_price = 1;
short ten_inches_price = 3;
short twelve_inch_price = 5;

void menu() {
    cout << setfill('-') << setw(10) << '-' << "7-11 Convenience Store" << setfill('-') << setw(10) << '-' << endl;

    cout << "Drinks\n";
    cout << "   Soda(S)" << setfill('.') << setw(18) << "$2\n";
    cout << "   Water(W)" << setfill('.') << setw(18) << "$1\n";

    cout << "Sandwiches\n";
    cout << "   10 inches" << setfill('.') << setw(18) << "$3\n";
    cout << "   12 inches" << setfill('.') << setw(18) << "$5\n";
    cout << "Enter the number of customers: ";
    cin >> number_of_customers;
}

void readInput() {
    cout << "   How many drinks? ";
    cin >> num_of_drinks;
    cout << "       What kind of drink(S=Soda, W=Water)?";
    cin >> drink_type;
    cout << "   How many Sandwiches? ";
    cin >> num_of_sandwiches;
    cout << "       What size of sandwich (10/12 inches)? ";
    cin >> sandwich_size;

}

void display_total() {
    cout << "           Your total bill = " << total << endl;
}


int main()
{

    __asm {
        call menu;
        mov al, drink_type;             // al = drink_type

    Loop1:                        
        call readInput;
        cmp drink_type, 'W';            // comparing the drink type to check if it's equal to 'W'
        je Water;                       // If drink_type ='w', jump to Water


    TestWater:
        cmp drink_type, 'w';            // comparing the drink type to check if it's equal to 'w'
        jne Soda;                       // If drink_type !='w', jump to Soda

    Water:
        mov ax, num_of_drinks;          // ax = num_of_drinks
        imul water_price;               // ax = num_of_drinks * water_price
        mov drink_total, ax;            // drink_total = num_of_drinks * water_price
        jmp Sandwich;                   // jump to Sandwich

    Soda:
        mov ax, num_of_drinks;          // ax = num_of_drinks
        imul soda_price;                // ax = num_of_drinks * soda_price
        mov drink_total, ax;            // drink_total = num_of_drinks * soda_price


    Sandwich:
        cmp sandwich_size, 10;          // comparing the sandwich size and the number 10
        jne Twelve;                     // if sandwich_size != 10, jump to Twelve

    Ten:
        mov ax, num_of_sandwiches;      // ax = num_of_sandwiches
        imul ten_inches_price;          // ax = num_of_sandwiches * ten_inches_price
        mov sandwich_total, ax;         // sandwich_total = num_of_sandwiches * ten_inches_price
        jmp Total;                      // jump to Total

    Twelve:
        mov ax, num_of_sandwiches;      // ax = num_of_sandwiches
        imul twelve_inch_price;         // ax = num_of_sandwiches * twelve_inch_price
        mov sandwich_total, ax;         // sandwich_total = num_of_sandwiches * twelve_inch_price
            
    Total:
        mov ax, drink_total;            // ax = drink_total
        add ax, sandwich_total;         // ax = drink_total + sandwich_total
        mov total, ax;                  // total = drink_total + sandwich_total
        call display_total;            
        cmp number_of_customers, 0;
        dec number_of_customers;        // -- number_of_customer
        jnz Loop1;                      // if number_of_customer != 0, jump to Loop1

    }

    return 0;

}
