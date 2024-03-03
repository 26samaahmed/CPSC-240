// Practice-Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int total, medium_total, blue_total, i;

int all_shirts[4][4] = { 10, 20, 30, 40,
                         20, 10, 40, 30,
                         5, 15, 20, 25,
                         30, 25, 20, 15 };

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
    __asm {
        // Calculate total of tshirts
        mov eax, 0;                 // eax = 0
        mov i, 0;                   // i = 0
        lea esi, [all_shirts];      // esi = [all_shirts]
    forLoop:
        cmp i, 16;                  // compare i and 16
        Je done;                    // if i == 16, jumpt to done
        add eax, [esi];             // eax += all_shirts[][]
        inc i;                      // ++i
        add esi, 4;                 // to go to the next index, add 4 so easi += 4
        Jmp forLoop;
    done:
        mov total, eax;             // total = eax
        call displayTshirtsTotal;


        // Calculate total of Medium tshirts [result is 70]
        mov eax, 0;                 // eax = 0
        mov i, 1;                   // i = 1
        lea esi, [all_shirts + 4];  // esi = [all_shirts + 4]
    forLoop2:
        cmp i, 14;                  // compare i and 14
        Je done2;                   // if i == 14, jump to done2
        add eax, [esi];             // eax += all_shirts[]
        inc i;                      // ++i
        add esi, 16;                // go to the next index so esi += 16
        Jmp forLoop2;
   done2:
        mov medium_total, eax;      // medium_total = eax
        call displayMediumShirts;


        // Calculate total of blue tshirts [result is 65]
        mov eax, 0;                 // eax = 0
        mov i, 8;                   // i = 8 so that it starts from row 3
        lea esi, [all_shirts + 32]; // esi = [all_shirts + 32]  which is the adress of the value row 3 column 
    forLoop3:
        cmp i, 12;                  // compare i and 12, where 12 is the index of the last number in row 3
        Je done3;                   // if i == 12, jumpt to done2
        add eax, [esi];             // eax += all_shirts[]
        inc i;                      // ++i
        add esi, 4;                 // go to the next index so esi += 4
        Jmp forLoop3;
    done3:
        mov blue_total, eax;        // blue_total = eax
        call displayBlueShirts;
    }

    return 0;
}
