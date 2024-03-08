// question3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

float num_of_drinks, num_of_sandwiches, sandwich_size, total, counter, drink_total, sandwich_total = 0;
char  drink_type;
float soda_price = 2.25;
float water_price = 1.75;
float ten_inches_price = 3.45;
float twelve_inch_price = 5.25;

void menu() {
    cout << setfill('-') << setw(10) << '-' << "7-11 Convenience Store" << setfill('-') << setw(10) << '-' << endl;

    cout << "Drinks\n";
    cout << "   Soda(S)" << setfill('.') << setw(18) << "$2.25\n";
    cout << "   Water(W)" << setfill('.') << setw(18) << "$1.75\n";

    cout << "Sandwiches\n";
    cout << "   10 inches" << setfill('.') << setw(18) << "$3.45\n";
    cout << "   12 inches" << setfill('.') << setw(18) << "$5.25\n";
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
    cout << fixed << showpoint << setprecision(2);
    cout << "           Your total bill = " << total << endl;
}

int main()
{
    __asm {
        call menu;
        call readInput;
        cmp drink_type, 'W';            // comparing the drink type to check if it's equal to 'W'
        Je Water;                       // If drink_type ='W', jump to Water

    TestWater:
        cmp drink_type, 'w';            // comparing the drink type to check if it's equal to 'w'
        Jne Soda;                       // If drink_type !='w', jump to Soda

    Water:
        fld num_of_drinks;              // st[0] = num_of_drinks
        fld water_price;                // st[0] = water_price, st[1] = num_of_drinks
        fmul;                           // st[0] = num_of_drinks * water_price
        fstp drink_total;               // drink_total = num_of_drinks * water_price
        Jmp Sandwich;                   // jump to Sandwich

    Soda:
        fld num_of_drinks;              // st[0] = num_of_drinks
        fld soda_price;                 // st[0] = soda_price, st[1] = num_of_drinks
        fmul;                           // st[0] = num_of_drinks * soda_price
        fstp drink_total;               // drink_total = num_of_drinks * soda_price

    Sandwich:
        cmp sandwich_size, 10;          // comparing the sandwich size and the number 10
        Je Ten;                         // if sandwich_size == 10, jump to Twelve

    Twelve:
        fld num_of_sandwiches;          // st[0] = num_of_sandwiches
        fld twelve_inch_price;          // st[0] = twelve_inch_price, st[1] = num_of_sandwiches
        fmul;                           // st[0] = twelve_inch_price * num_of_sandwiches
        fstp sandwich_total;            // sandwich_total =  = twelve_inch_price * num_of_sandwiches

    Ten:
        fld num_of_sandwiches;          // st[0] = num_of_sandwiches
        fld ten_inches_price;           // st[0] = num_of_sandwiches , st[1] = num_of_sandwiches
        fmul;                           // st[0] = num_of_sandwiches * num_of_sandwiches
        fstp sandwich_total;            // sandwich_total = = num_of_sandwiches * num_of_sandwiches

    Total:
        fld drink_total;                // st[0] = drink_total
        fld sandwich_total;             // st[0] = sanwich_total, st[1] = drink_total
        fadd;                           // st[0] = drink_total + sandwich_total
        fstp total;                     // total = drink_total + sandwich_total
        call display_total;
    }
    return 0;
}
