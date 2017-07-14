// ProgrammingExcercise13-2ChristianPoynter.cpp : Defines the entry point for the console application.
// Same as Programming Excercise 13-1 except overloads are nonmembers of the class rectangleType

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void displayMenuOptions();

class rectangleType
{
public:
	rectangleType();

	void setDimension(double l, double w);
	double getLength() const;
	double getwidth() const;
	double area() const;
	double perimeter() const;
	void print() const;

	// Overloads the operators
	rectangleType operator + (const rectangleType&) const;
	rectangleType operator * (const rectangleType&) const;
	rectangleType operator - (const rectangleType&) const;

	bool operator == (const rectangleType&) const;
	bool operator != (const rectangleType&) const;
	bool operator <= (const rectangleType&) const;
	bool operator < (const rectangleType&) const;
	bool operator >= (const rectangleType&) const;
	bool operator > (const rectangleType&) const;

	rectangleType(double l, double w);

private:
	double length;
	double width;
};

int main()
{
	bool loopContinue = true;
	double tempLength, tempWidth;
	string userInput;

	cout << "This program will initalize and let you perform operations on two rectangles" << endl << endl
		<< "Please enter the length of rectangle 1: ";
	cin >> tempLength;
	cout << "Please enter the width of rectangle 1: ";
	cin >> tempWidth;
	rectangleType rectangle1(tempLength, tempWidth);
	cout << "Thank you, first rectangle initalized" << endl << endl;

	cout << "Please enter the length of rectangle 2: ";
	cin >> tempLength;
	cout << "Please enter the width of rectangle 2: ";
	cin >> tempWidth;
	rectangleType rectangle2(tempLength, tempWidth);
	cout << "Thank you, second rectangle initalized" << endl << endl;

	displayMenuOptions();

	while (loopContinue == true)
	{
		cout << "what would you like to do?" << endl;
		cin >> userInput;

		if (userInput == "view" || userInput == "print" || userInput == "display")
		{
			cout << "Which rectangle would you like to view?" << endl;
			cin >> userInput;
			if (userInput == "1" || userInput == "rectangle 1" || userInput == "Rectangle 1")
			{
				cout << endl << "Rectangle 1:" << endl;
				rectangle1.print();
			}
			else if (userInput == "2" || userInput == "rectangle 2" || userInput == "Rectangle 2")
			{
				cout << endl << "Rectangle 2:" << endl;
				rectangle2.print();
			}
			else if (userInput == "both" || userInput == "Both" || userInput == "1 and 2")
			{
				cout << endl << "Rectangle 1:" << endl;
				rectangle1.print();
				cout << endl << "Rectangle 2:" << endl;
				rectangle2.print();
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "change" || userInput == "reset" || userInput == "modify")
		{
			cout << "which rectangle would you like to change? (1 or 2)" << endl;
			cin >> userInput;
			if (userInput == "1")
			{
				cout << "what is the new lenght you'd like to store in rectangle 1?" << endl;
				cin >> tempLength;
				cout << "what is the new width you'd like to store in rectangle 1?" << endl;
				cin >> tempWidth;
				rectangle1.setDimension(tempLength, tempWidth);
				cout << "thank you, values for rectangle 1 modified" << endl << endl;
			}
			else if (userInput == "2")
			{
				cout << "what is the new lenght you'd like to store in rectangle 2?" << endl;
				cin >> tempLength;
				cout << "what is the new width you'd like to store in rectangle 2?" << endl;
				cin >> tempWidth;
				rectangle2.setDimension(tempLength, tempWidth);
				cout << "thank you, values for rectangle 2 modified" << endl << endl;
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "add" || userInput == "+" || userInput == "addition")
		{
			cout << "Which rectangle would you like to hold the final value? (1 or 2)" << endl;
			cin >> userInput;
			if (userInput == "1" || userInput == "one")
			{
				rectangle1 = rectangle1 + rectangle2;

				cout << "New values for rectangle 1:" << endl;
				rectangle1.print();
			}
			else if (userInput == "2" || userInput == "two")
			{
				rectangle2 = rectangle1 + rectangle2;

				cout << "New values for rectangle 2:" << endl;
				rectangle2.print();
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "subtract" || userInput == "-" || userInput == "subtraction")
		{
			cout << "Which rectangle would you like to be subtracted from? (1 or 2)" << endl;
			cin >> userInput;
			if (userInput == "1" || userInput == "one")
			{
				rectangle1 = rectangle1 - rectangle2;

				cout << "New values for rectangle 1:" << endl;
				rectangle1.print();
			}
			else if (userInput == "2" || userInput == "two")
			{
				rectangle2 = rectangle2 - rectangle1;

				cout << "New values for rectangle 2:" << endl;
				rectangle2.print();
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "multiply" || userInput == "*" || userInput == "multiplication")
		{
			cout << "Which rectangle would you like to hold the final value? (1 or 2)" << endl;
			cin >> userInput;
			if (userInput == "1" || userInput == "one")
			{
				rectangle1 = rectangle1 * rectangle2;

				cout << "New values for rectangle 1:" << endl;
				rectangle1.print();
			}
			else if (userInput == "2" || userInput == "two")
			{
				rectangle2 = rectangle1 * rectangle2;

				cout << "New values for rectangle 2:" << endl;
				rectangle2.print();
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "compare" || userInput == "==" || userInput == "comparison")
		{
			cout << "Which operator would you like to use to compare rectangles 1 and 2?" << endl;
			cin >> userInput;
			if (userInput == "==" || userInput == "!=")
			{
				if (rectangle1 == rectangle2)
				{
					cout << "The two rectangles are equal" << endl << endl;
				}
				else if (rectangle1 != rectangle2)
				{
					cout << "The two rectangles are not equal" << endl << endl;
				}
			}
			else if (userInput == ">=")
			{
				if (rectangle1 >= rectangle2)
				{
					cout << "rectangle 1 is greater than or equal to rectangle 2" << endl << endl;
				}
				else
				{
					cout << "rectangle 1 is not greater than or equal to rectangle 2" << endl << endl;
				}
			}
			else if (userInput == ">")
			{
				if (rectangle1 > rectangle2)
				{
					cout << "rectangle 1 is greater than rectangle 2" << endl << endl;
				}
				else
				{
					cout << "rectangle 1 is not greater than rectangle 2" << endl << endl;
				}
			}
			else if (userInput == "<=")
			{
				if (rectangle1 <= rectangle2)
				{
					cout << "rectangle 1 is less than or equal to rectangle 2" << endl << endl;
				}
				else
				{
					cout << "rectangle 1 is not less than or equal to rectangle 2" << endl << endl;
				}
			}
			else if (userInput == "<")
			{
				if (rectangle1 > rectangle2)
				{
					cout << "rectangle 1 is less than rectangle 2" << endl << endl;
				}
				else
				{
					cout << "rectangle 1 is not less than rectangle 2" << endl << endl;
				}
			}
			else
			{
				cout << "not a valid input" << endl << endl;
			}
		}

		if (userInput == "help" || userInput == "commands" || userInput == "menu")
		{
			displayMenuOptions();
		}

		if (userInput == "quit" || userInput == "q" || userInput == "exit")
		{
			loopContinue = false;
			break;
		}
	}

	return 0;
}

void rectangleType::setDimension(double l, double w)
{
	if (l >= 0)
	{
		length = l;
	}
	else
	{
		length = 0;
	}

	if (w >= 0)
	{
		width = w;
	}
	else
	{
		width = 0;
	}
}

double rectangleType::getLength() const
{
	return length;
}

double rectangleType::getwidth() const
{
	return width;
}

double rectangleType::area() const
{
	return length * width;
}

double rectangleType::perimeter() const
{
	return 2 * (length + width);
}

void rectangleType::print() const
{
	cout << "Length: " << length << "; Width: " << width << endl
		<< "Area: " << area() << "; Perimeter: " << perimeter() << endl;
}

rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}

rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

rectangleType rectangleType::operator+ (const rectangleType& rectangle) const
{
	rectangleType tempRect;
	tempRect.length = length + rectangle.length;
	tempRect.width = width + rectangle.width;

	return tempRect;
}

rectangleType rectangleType::operator* (const rectangleType& rectangle) const
{
	rectangleType tempRect;
	tempRect.length = length * rectangle.length;
	tempRect.width = width * rectangle.width;

	return tempRect;
}

rectangleType rectangleType::operator- (const rectangleType& rectangle) const
{
	rectangleType tempRect;
	if (tempRect.length - rectangle.length >= 0 && tempRect.width - rectangle.width >= 0)
	{
		tempRect.length = length - rectangle.length;
		tempRect.width = width - rectangle.width;
	}
	else
	{
		cout << "New values not set: Cannot perform this operation, output will be less than zero!" << endl;
	}

	return tempRect;
}

bool rectangleType::operator== (const rectangleType& rectangle) const
{
	return (area() == rectangle.area());
}

bool rectangleType::operator!= (const rectangleType& rectangle) const
{
	return (area() != rectangle.area());
}

bool rectangleType::operator<= (const rectangleType& rectangle) const
{
	return (area() <= rectangle.area());
}

bool rectangleType::operator< (const rectangleType& rectangle) const
{
	return (area() < rectangle.area());
}

bool rectangleType::operator>= (const rectangleType& rectangle) const
{
	return (area() >= rectangle.area());
}

bool rectangleType::operator> (const rectangleType& rectangle) const
{
	return (area() > rectangle.area());
}

void displayMenuOptions()
{
	cout << "Menu options:" << endl
		<< "\"help\", \"commands\", or \"menu\"          - displays this list" << endl
		<< "\"view\", \"print\", or \"display\"          - view the information of one or both rectangles" << endl
		<< "\"change\", \"reset\", or \"modify\"          - change the dimensions of a rectangle of your choice" << endl
		<< "\"add\", \"+\", or \"addition\"              - add two rectangles together" << endl
		<< "\"multiply\", \"*\", or \"multiplication\"   - multiply two rectangles by one another" << endl
		<< "\"subtract\", \"-\", or \"subtraction\"      - subtract one rectangle by another" << endl
		<< "\"compare\", \"==\", or \"comparison\"       - compare two rectangles" << endl
		<< "\"quit\", \"q\", or \"exit\"                 - exits the program" << endl << endl;
}