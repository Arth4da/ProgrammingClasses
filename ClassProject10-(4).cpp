// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class romanType {

public: 
	romanType();

	int number;
	string romanNumeral;

	void setInt();
	void setRomanNumeral();
	void displayInt();
	void displayRomanNumeral();
	void convertToInt();
	void convertToRomanNumeral();
};

romanType::romanType() {}

int main()
{
	romanType numberObj;
	bool exit = false;
	string userInput;
	int userIntInput;

	cout << "This program converts integer numbers to roman numerals and vice versa" << endl
		<< "Would you like to (1) input an integer?" << endl
		<< "or (2) input a roman numeral?" << endl << endl;
	cin >> userInput;

	if (userInput == "1") {
		numberObj.setInt();
		numberObj.convertToRomanNumeral();
	}
	else 
	{
		numberObj.setRomanNumeral();
		numberObj.convertToInt();
	}

	while (exit == false)
	{
		cout << "Would you like to (1) output the current number as an integer" << endl
			<< "                  (2) output the current number as a roman numeral" << endl
			<< "                  (3) enter a new integer" << endl
			<< "                  (4) enter a new roman numeral" << endl
			<< "               or (5) exit the program" << endl << endl;

		cin >> userInput;

		if (userInput == "1") 
		{
			numberObj.displayInt();
		} 
		else if (userInput == "2")
		{
			numberObj.displayRomanNumeral();
		}
		else if (userInput == "3")
		{
			numberObj.setInt();
			numberObj.convertToRomanNumeral();
		}
		else if (userInput == "4")	
		{
			numberObj.setRomanNumeral();
			numberObj.convertToInt();
		}
		else if (userInput == "5")
		{
			exit = true;
			break;
		}
	}

	return 0;
}

void romanType::setInt()
{
	cout << "What integer value do you wish to store?" << endl;
	cin >> number;
	cout << "integer input received!" << endl << endl;
};

void romanType::setRomanNumeral()
{
	cout << "What roman numeral value do you wish to store?" << endl;
	cin >> romanNumeral;
	cout << "roman numeral input received!" << endl << endl;
}

void romanType::displayInt()
{
	cout << endl << "The current number in integer format is: " << number << endl << endl;
}

void romanType::displayRomanNumeral()
{
	cout << endl << "The current number " << number << " in roman numeral format is: " << romanNumeral << endl << endl;
}

void romanType::convertToInt() {

	number = 0;
	for (int i = 0; i < romanNumeral.length(); i++) {
		if (romanNumeral.at(i) == 'M')
		{
			number += 1000;
		}
		else if (romanNumeral.at(i) == 'D')
		{
			number += 500;
		}
		else if (romanNumeral.at(i) == 'C')
		{
			if (romanNumeral.at(i + 1) == 'M') 
			{
				i++;
				number += 900;
			}
			else
			{
				number += 100;
			}
		}
		else if (romanNumeral.at(i) == 'L')
		{
			number += 50;
		}
		else if (romanNumeral.at(i) == 'X')
		{
			if (romanNumeral.at(i + 1) = 'C')
			{
				i++;
				number += 90;
			}
			else if (romanNumeral.at(i + 1) = 'L')
			{
				i++;
				number += 40;
			}
			else
			{
				number += 10;
			}
		}
		else if (romanNumeral.at(i) == 'V')
		{
			number += 5;
		}
		else if (romanNumeral.at(i) == 'I')
		{
			if (romanNumeral.at(i + 1) == 'X')
			{
				i++;
				number += 9;
			}
			else if (romanNumeral.at(i + 1) == 'V')
			{
				i++;
				number += 4;
			}
			else
			{
				number += 1;
			}
		}
	}
}

void  romanType::convertToRomanNumeral() {
	string romanNumeralTemp = "                         ";
	int i = 0;
	int numberTemp = number;
	while (numberTemp > 0)
	{
		if (numberTemp - 1000 >= 0)
		{
			romanNumeralTemp.at(i) = 'M';
			numberTemp -= 1000;
		}
		else if (numberTemp - 900 >= 0)
		{
			romanNumeralTemp.at(i) = 'C';
			i++;
			romanNumeralTemp.at(i) = 'M';
			numberTemp -= 900;
		}
		else if (numberTemp - 500 >= 0)
		{
			romanNumeralTemp.at(i) = 'D';
			numberTemp -= 500;
		}
		else if (numberTemp - 400 >= 0)
		{
			romanNumeralTemp.at(i) = 'C';
			i++;
			romanNumeralTemp.at(i) = 'D';
			numberTemp -= 400;
		}
		else if (numberTemp - 100 >= 0)
		{
			romanNumeralTemp.at(i) = 'C';
			numberTemp -= 100;
		}
		else if (numberTemp - 90 >= 0)
		{
			romanNumeralTemp.at(i) = 'X';
			i++;
			romanNumeralTemp.at(i) = 'C';
			numberTemp -= 90;
		}
		else if (numberTemp - 50 >= 0)
		{
			romanNumeralTemp.at(i) = 'L';
			numberTemp -= 50;
		}
		else if (numberTemp - 40 >= 0)
		{
			romanNumeralTemp.at(i) = 'X';
			i++;
			romanNumeralTemp.at(i) = 'L';
			numberTemp -= 40;
		}
		else if (numberTemp - 10 >= 0)
		{
			romanNumeralTemp.at(i) = 'X';
			numberTemp -= 10;
		}
		else if (numberTemp - 9 >= 0)
		{
			romanNumeralTemp.at(i) = 'I';
			i++;
			romanNumeralTemp.at(i) = 'X';
			numberTemp -= 9;
		}
		else if (numberTemp - 5 >= 0)
		{

			romanNumeralTemp.at(i) = 'V';
			numberTemp -= 5;
		}
		else if (numberTemp == 4) {

			romanNumeralTemp.at(i) = 'I';
			i++;
			romanNumeralTemp.at(i) = 'V';
			numberTemp -= 4;
		}
		else if (numberTemp - 1 >= 0)
		{
			romanNumeralTemp.at(i) = 'I';
			numberTemp -= 1;
		}
		i++;
	}

	// this removes all white space from the romanNumeralTemp string and assigns the modified value to romanNumeral
	int length = romanNumeralTemp.length();

	for (int i = 0; i < length; i++)
	{
		if (romanNumeralTemp[i] == ' ')
		{
			romanNumeralTemp.erase(i, 1);
			length--;
			i--;
		}
	}
	romanNumeral = romanNumeralTemp;
}