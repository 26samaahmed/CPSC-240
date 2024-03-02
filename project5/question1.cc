// Practice-Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int total, medium_total, blue_total, i;
int all_shirts[4][4] = { 10, 20, 30, 40, 
                  20, 10, 40, 30, 
                  5, 15, 20, 25, 
                  30, 25, 20, 15 };

int medium_shirts[4] = { 20, 10, 15, 25 };

void displayTshirtsTotal() {
    cout << "Total Number of all shirts: " << total << endl;
}

void displayMediumShirts() {
    cout << "Total number of medium shirts: " << medium_total << endl;
}

void displayBlueShirts() {
    cout << "Total Number of blue shirts: " << blue_total << endl;
}
int main()
{
    // lea [load effective address] referse to getting the address
    // esi holds the source index
    __asm{
        // Calculate total of tshirts
        mov eax, 0;                 // eax = 0
        mov i, 0;                   // i = 0
        lea esi, [all_shirts];      // esi = [all_shirts]
    forLoop:
        cmp i, 16;                  // compare i and 16
        Je done;                    // if i == 9, jumpt to done2
        add eax, [esi];             // eax += all_shirts[][]
        inc i;                      // ++i
        add esi, 4;                 // to go to the next index, add 4 so easi += 4
        Jmp forLoop;
    done:
        mov total, eax;             // total = eax
        call displayTshirtsTotal;   


        // Calculate total of Medium tshirts
        mov eax, 0;                 // eax = 0
        mov i, 0;                   // i = 0
        lea esi, [medium_shirts];   // esi = [medium_shirts]



        // Calculate total of blue tshirts
    }
    return 0;
}
