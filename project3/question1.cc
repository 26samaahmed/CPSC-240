// project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

short number_of_customers, num_of_drinks, num_of_sandwiches, sandwich_size, total, counter, drink_total, sandwich_total;
char  drink_type;
char water = 'w';
char soda = 's';
short soda_price = 2;
short water_price = 1;
short ten_inches_price = 3;
short twelve_inch_price = 5;


void askData() {
    cout << "Enter the number of customers: ";
    cin >> number_of_customers;
}

void readData() {
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

    cout << setfill('-') << setw(10) << '-' << "7-11 Convenience Store" << setfill('-') << setw(10) << '-' << endl;

    cout << "Drinks\n";
    cout << "   Soda(S)" << setfill('.') << setw(18) << "$2\n";
    cout << "   Water(W)" << setfill('.') << setw(18) << "$1\n";

    cout << "Sandwiches\n";
    cout << "   10 inches" << setfill('.') << setw(18) << "$3\n";
    cout << "   12 inches" << setfill('.') << setw(18) << "$5\n";



    __asm{

        call askData;                   // Ask the user how many customers there are
        mov i = 1;                      // i = 1
    forLoop:
        cmp i, number_of_customers;     // compare i and the number of customers
        Jnle exitLoop;                  // if i !<= number_of_customers, jump to exit loop
        // if i <= number_of_customers, call the read_data function
        call readData;
        // do the calculations here
        mov ax, num_of_drinks;          // ax = num_of_drinks
        mov ah, drink_type;             // ah = drink_type
        cmp ah, water;                  // comparing the drink type to check if it's equal to w
        Je Water;                       // If ah ='w', jump to Water


        cmp ah, soda;                   // comparing the drink type to check if it's equal to s
        Je Soda;                        // If ah ='s', jump to Soda


    Water:
        imul ax, water_price;           // ax = num_of_drinks * water_price
        mov drink_total, ax;            // drink_total = num_of_drinks * water_price

    Soda:
        imul ax, soda_price;            // ax = num_of_drinks * soda_price
        mov drink_total, ax;            // drink_total = num_of_drinks * soda_price
        
        
        inc i;                          // i++


    }



}
