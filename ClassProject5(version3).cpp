// ClassProject5(version3).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int userInput;
int sum = 0;
int numberOfDigits = 0;

int main()
{
	cout << "Please enter an integer" << endl;
	cin >> userInput;
	cout << endl;

	if (userInput < 0) {
		userInput *= -1;
	}

	int userInputCalc = userInput;

	do {
		numberOfDigits++;
		userInputCalc /= 10;
	} while (userInputCalc > 0);

	for (int i = 0; i < numberOfDigits; i++) {
		int digit = userInput % 10;
		userInput = (userInput - digit) / 10;
		cout << digit << " ";
		sum += digit;
	}

	cout << endl << endl << sum << endl << endl;

	system("pause");
	return 0;
}