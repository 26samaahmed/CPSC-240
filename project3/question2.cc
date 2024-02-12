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
	cin >> score;
}

int main() {
	__asm {
		mov eax, 0;
	forLoop:
		call askData;
		cmp score, -1;		// compare score and -1
		je exitLoop;		// if score = -1, exit loop
		add eax, score;		// eax += score
		inc counter;		// ++counter
		jmp forLoop;		// jump to for loop
	exitLoop:
		mov total_scores, eax;		// total = eax
		

	}
	cout << "Total is " << total_scores << endl;
	cout << "Counter is " << counter << endl;
	//cout << "Your average is: " << average << endl;
	return 0;
}