// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// question4.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
   _asm {
        call askData;       // ask user to enter the sentence
    forLoop:
        call readChar;
        cmp letter, '\n';   // if we reach a new line, it means we went through all the letters
        je exitLoop;
        cmp letter, 'Z';
        jle upperCase;
        cmp letter, 'a';
        jge lowerCase;

    lowerCase:
        cmp letter, 'z';
        jle Increment_L;
    upperCase:
        cmp letter, 'A';
        jge Increment_U;

    Increment_U:
        inc upperCaseCount;
        jmp forLoop;

    Increment_L:
        inc lowerCaseCount;
        jmp forLoop;

    exitLoop:
        call display;

    }
    return 0;
} 


