// Practice-Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int i, total, medium_total, red_total, short_total = 0;
// the first [3] is for colors
// the second [3] is for sizes
// the [2] is for the type of sleeve

void displayShirtTotal() {
    cout << "Total number of all shirts = " << total << endl;
}

void displayMediumTotal() {
    cout << "Total number of medium size shirts = " << medium_total << endl;
}

void displayRedTotal() {
    cout << "Total number of red shirts = " << red_total << endl;
}

void displayShortSleevesTotal() {
    cout << "Total number of short sleeve shirts = " << short_total << endl;
}

int main()
{
    // lea [load effective address] referse to getting the address
    // esi holds the source index
    __asm {
        // Calculate total for all shirts -> 171
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

        // Calculate total for medium shirts -> 57
        // arr[0][1][0] = 2, arr[1][1][0] = 5, arr[2][1][0] = 8, arr[0][1][1] = 11, arr[1][1][1] = 14, arr[2][1][1] = 17
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

        // Calculate total for short sleeve shirts -> 81
        //  1, 3, 5, 7, 9, 11, 13, 15, 17
        mov eax, 0;             // eax = 0
        mov i, 0;               // i = 0
        lea esi, [arr];         // esi = [arr]
    forLoop3:
        cmp i, 17;              // compare i and 17
        Je done3;               // If i == 17, jump to done3
        add eax, [esi];         // eax += arr[][][]
        inc i;                  // ++i
        add esi, 8;             // esi += 8
        Jmp forLoop3;
    done3:
        mov short_total, eax;  // short_total = eax;
        call displayShortSleevesTotal;


        // Calculate total for red shirts -> 21
        // 1, 2, 3, 4, 5, 6
        mov eax, 0;             // eax = 0
        mov i, 0;               // i = 0
        lea esi, [arr];         // esi = [arr]
    forLoop4:
        cmp i, 6;               // compare i and 6
        Je done4;               // If i == 6, jump to done4
        add eax, [esi];         // eax += arr[][][]
        inc i;                  // ++i
        add esi, 4;             // esi += 4
        Jmp forLoop4;
    done4:
        mov red_total, eax;     // red_total = eax;
        call displayRedTotal;
    }

    return 0;
}
