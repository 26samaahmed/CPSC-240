// project5_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[5] = { 9, 3, 22, 8, 1 };
int i, j = 0;

int main()
{
    cout << "Original array a: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << ' ';
    }
    __asm {
        mov eax, 0;         // eax = 0
        mov ebx, 0;         // ebx = 0
        mov i, 0;           // i = 0

    forLoop:
        lea esi, [arr];     // esi = [arr]
        cmp i, 4;           // comparing i and n - 1 where n is 5

        Je done;            // If i == 4, jmp done
        inc i;              // ++i since one of our values needs to be 1 index ahead
        mov j, 0;           // j = 0

    forLoop2:
        cmp j, 4;           // comparing j and n - 1 where n is 5
        Je forLoop;         // if the iteration for the inner loop is done, then go to the outer loop's next iteration
        mov eax, [esi];     // eax = arr[current index]
        mov ebx, [esi + 4]; // ebx = arr[current index + 1]
        cmp eax, ebx;       // comapre arr[current index] and arr[current index + 1]
        Jg swapped;         // if arr[current index] > arr[current index + 1], jump to swapped
        // If the current index is not bigger than the number after it then increment j and go to next iteration of loop
        add esi, 4;         // esi += 4
        inc j;              // ++j
        jmp forLoop2;

    swapped:
        xchg[esi], ebx;     // arr[current_index] = 3
        xchg[esi + 4], eax; // arr[current_index + 1] = 9
        add esi, 4;         // esi += 4
        inc j;              // ++j
        jmp forLoop2;
    done:

    }
    cout << "\nSorted array a: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << ' ';
    }

    cout << endl;
    return 0;
}
