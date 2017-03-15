// OOP 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Contact {
private: 
	string firstName;
	string lastName;
	string address;
	string phoneNumber;
	int ID;

};

int main()
{
	Contact jShelton("Josh", "Shelton", "Brent's Basement", "816-289-9910", 1);

	system("pause");
    return 0;
}

