// question2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int score, average;
int total_scores = 0;
int counter = 0;
void askData() {
	cout << "Enter your score (-1) to stop: ";
}
void readData() {
	cin >> score;
}

int main() {
	__asm {
	forLoop:
		call askData;			// ask the user to input the numbers
		call readData;			// read the users input
		cmp score, -1;			// compare score and -1
		je exitLoop;			// if score = -1, exit loop

		mov eax, score;			// eax = score
		add total_scores, eax;		// total += eax where eax = score
		inc counter;			// ++counter
		jmp forLoop;			// jump to for loop
	exitLoop:
		mov eax, total_scores;		// eax = total scores
		cdq;
		idiv counter;			// eax = total_scores / counter
		mov average, eax;		// average = total_scores / counter
	}
	cout << "Your average is: " << average << endl;
	return 0;
}
