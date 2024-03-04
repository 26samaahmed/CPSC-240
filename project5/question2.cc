// project5_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//using namespace std;

int arr[5] = { 9, 3, 22, 8, 1 };
int i , j= 0;
void displayOriginalArray() {
    std::cout << "Original array a: ";
    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void displaySortedArray() {
    std::cout << j << ' ';
}

int main()
{
    std::cout << "Sorted array a :";
    __asm {
        call displayOriginalArray;
        mov eax, 0;
        mov i, 0;
        mov j, 0;
        
    forLoop:
        lea esi, [arr];
        cmp i, 4;   // comparing i and n - 1 where n is 5
        Je done;
        inc i;
        mov j, 0;
    forLoop2:
        cmp j, 4;   // comparing j and n - 1 where n is 5
        Je forLoop; // if the ietration for the inner loop is done, then go to the outer loop's next iteration
        mov eax, [esi];     // eax = 9
        mov ebx, [esi +4]; // ebx = 3
        cmp eax, ebx;   // comapre 9 and 3
        Jg xchg;    // if 9 > 3, jump t exchange

    xchg:
        xchg[esi], ebx; // arr[0] = 3
        xchg[esi + 4], eax; // arr[1] = 9
        add esi, 4;
        inc j;
        call displaySortedArray;
        jmp fLoop1;
    }
    return 0;
}
