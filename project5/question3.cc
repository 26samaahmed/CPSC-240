// Practice-Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int i, total, medium_total = 0;
// the first [3] is for colors so this includes
// arr[3][0][0], arr[3][1][0],arr[3][2][0], arr[3][0][1, arr[3][0][0]

// the second [3] is for sizes
// the [2] is for the type of sleeve

void displayShirtTotal() {
    cout << "Total number of all shirts = " << total << endl;
}

void displayMediumTotal() {
    cout << "Total number of medium size shirts = " << medium_total << endl;
}

int main()
{
    // lea [load effective address] referse to getting the address
    // esi holds the source index
    __asm {
        // Calculate total for all shirts [171]
        mov eax, 0;             // eax = 0
        mov i, 0;               // i = 0
        lea esi, [arr];         // esi = [arr]
    forLoop:
        cmp i, 18;              // compare i and 18
        Je done;                // If i == 18, jump to done
        add eax, [esi];         // eax += arr[][][]
        inc i;                  // ++i
        add esi, 4;             // esi += 4
        Jmp forLoop;        
    done:
        mov total, eax;         // total = eax
        call displayShirtTotal;

        // Calculate total for medium shirts [57]
        mov eax, 0;             // eax = 0
        mov i, 1;               // i = 1
        lea esi, [arr + 4];     // esi = [arr + 4]
    forLoop2:
        cmp i, 17;              // compare i and 17
        Je done2;               // If i == 17, jump to done2
        add eax, [esi];         // eax += arr[][][]
        inc i;                  // ++i
        add esi, 12;            // esi += 12
        Jmp forLoop2;
    done2:
        mov medium_total, eax;  // medium_total = eax
        call displayMediumTotal;

        // Calculate total for short sleeve shirts [45]
        mov eax, 0;             // eax = 0
        mov i, 0;               // i = 0
        lea esi, [arr];         // esi = [arr]
    forLoop3:
        cmp i, 9;               // compare i and 9
        Je done3;               // If i == 9, jump to done3
        add eax, [esi];         // eax += arr[][][]
        inc i;                  // ++i
        add esi, 4;             // esi += 4
        Jmp forLoop3;
    done3:
        mov medium_total, eax;  // medium_total = eax;
        call displayMediumTotal;


        // Calculate total for red shirts [39]

    }

    return 0;
}