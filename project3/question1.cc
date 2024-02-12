// project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

short number_of_customers, num_of_drinks, num_of_sandwiches, sandwich_size, total, counter, drink_total, sandwich_total;
char  drink_type;
short ten = 10;
short twelve = 12;
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
}
void askData() {
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
        call askData;
        mov ax, number_of_customers;
     

    forLoop:
        call readInput;                           // Ask the user how many customers there are
        cmp number_of_customers, 0;              // compare 0 and the number of customers
        je exitLoop;                          // if number_of_customers <= 0, jump to exit loop
  
        call readInput;
        // do the calculations here
        mov ax, num_of_drinks;          // ax = num_of_drinks
        mov ah, drink_type;             // ah = drink_type
        cmp ah, 'w';                    // comparing the drink type to check if it's equal to w
        je Water;                       // If ah ='w', jump to Water

        cmp ah, 's';                    // comparing the drink type to check if it's equal to s
        je Soda;                        // If ah ='s', jump to Soda

    Water:
        imul ax, water_price;           // ax = num_of_drinks * water_price
        mov drink_total, ax;            // drink_total = num_of_drinks * water_price

    Soda:
        imul ax, soda_price;            // ax = num_of_drinks * soda_price
        mov drink_total, ax;


        mov ax, num_of_sandwiches;      // ax = num_of_sandwiches
        mov bx, sandwich_size;          // bx = sandwich_size
        cmp bx, ten;
        je TenInches;                   // if sandwich_size = 10
        cmp bx, twelve;
        je TwelveInches;                // if sandwich_size = 12


    TenInches:
        imul ax, ten_inches_price;      // ax = num_of_sandwiches * ten_inches_price
        mov sandwich_total, ax;         // sandwich_total = num_of_sandwiches * ten_inches_price



    TwelveInches:
        imul ax, twelve_inch_price;   // ax = = num_of_sandwiches * twelve_inches_price
        mov sandwich_total, ax;         // sandwich_total = num_of_sandwiches * twelve_inches_price

        add ax, drink_total;            // ax = drink_total
        add ax, sandwich_total;         // ax = drink_total + sandwich_total
        mov total, ax;                  // total = drink_total + sandwich_total


        dec number_of_customers;                    // counter--
        jnz forLoop;

    exitLoop:
        call display_total;

    }
}