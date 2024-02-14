// question3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


char letter;
int upperCaseCount = 0;
int lowerCaseCount = 0;
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
        call askData;       // ask user to enter the sentence
    forLoop:                // forLoop label
        call readChar;      // Reading character by character from letter
        cmp letter, ' ';    // compare letter to ' '
        je forLoop;         // Jump back to for loop label so we can ignore the spaces
        cmp letter, '.';    // if we reach a period, then we reached the end of the sentence so exit loop
        je exitLoop;
        cmp letter, 'Z';    // compare the current letter with 'Z'
        jle upperCase;      // if letter <= 'Z' then jump to upperCase
        cmp letter, 'a';    // compare the current letter with 'a'
        jge lowerCase;      // if letter >= 'a' then jump to lowerCase

    lowerCase:
        cmp letter, 'z';    // compare the current letter with 'z'
        jle Increment_L;    // if letter <= 'z' then this means its a lower case letter so we jump to Increment_L
    upperCase:
        cmp letter, 'A';    // compare the current letter with 'A'
        jge Increment_U;    // if letter >= 'A' then this means its a upper case letter so we jump to Increment_U

    Increment_U:
        inc upperCaseCount; // increase the count for upper case letters
        jmp forLoop;        // jump to for loop

    Increment_L:
        inc lowerCaseCount; // increase the count for lower case letters
        jmp forLoop;        // jump to for loop

    exitLoop:
        call display;       // call the display function to print results

    }
    return 0;
}
