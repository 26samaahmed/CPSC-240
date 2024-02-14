// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
char grade;
int count1;
void askData() {
    cout << "Enter a group of grades: ";
}

void getInput() {
    grade = cin.get();
}

void countNumber() {
    cout << "No. of " << grade << "'s = " << count1 << endl;
 }

int main()
{
    _asm {
        call askData;
        mov grade, 0;
    forLoop:
        call getInput;
        cmp grade, '\n';    // if the user hits enter then jump to exitLoop
        je exitLoop;        // exit the loop
        cmp grade, 'A';     // compare it to the ascii letter and see if it's greater than or equal
        jge display;        // if it is then call the display function to display the grade and count
    display:
        mov al, grade;
        inc count1;
        mov grade, al;
        call countNumber;
    jmp forLoop;        // continue the loop
     exitLoop:
    }

    return 0;
}
