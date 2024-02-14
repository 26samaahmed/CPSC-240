// question4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


char letter;
int upperCaseCount, lowerCaseCount;
void askData() {
    cout << "Enter a sentence: ";
}

void readChar() {
    letter = cin.get();
}
void display() {

    cout << "No. of uppercase letters = " << upperCaseCount << endl;
    cout << "No. of lowercase letters = " << lowerCaseCount << endl;
}

int main() {
    __asm {
        mov letter, 0;      // letter = 0
        call askData;       // ask user to enter the sentence
    forLoop:
        call readChar;
        cmp letter, '\n';   // if we reach a new line, it means we went through all the letters
        je exitLoop;
        cmp letter, 'a';    // compare the current letter to the decimal number for the character a (using the ASCII table)
        jge lowerCase;
        cmp letter, 'Z';
        jle upperCase;
    lowerCase:
        inc lowerCaseCount;

    upperCase:
        inc upperCaseCount;

        jmp forLoop;


    exitLoop:
        call display;

    }
    return 0;
} // lower case count works but upper doesn't
