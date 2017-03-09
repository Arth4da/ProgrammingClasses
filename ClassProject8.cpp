// ClassProject8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool custom;
bool display;

string students[10]{"Johnson", "Aniston", "Cooper", "Gupta", "Blair", "Clark", "Kennedy", "Bronson", 
					"Sunny", "Smith"};
string studentsCustom[10];

float testScores[10][5]{ {85, 83, 77, 91, 76}, {80, 90, 95, 93, 48}, {78, 81, 11, 90, 73}, {92, 83, 30, 69, 87},
	{23, 45, 96, 38, 59}, {60, 85, 45, 39, 67}, {77, 31, 52, 74, 83}, {93, 94, 89, 77, 97}, {79, 85, 28, 93, 82},
	{85, 72, 49, 75, 63} };
float testScoresCustom[10][5];
float grades[10];
float gradesCustom[];
float average;

void readCustomStudentsAndGrades();
void averageScoreAndGrade(float scores[10][5]);
void displayOption();
void outputResults(string name[10]);
void infoDisplay(string names[10], float scores[10][5]);
void classAverage(float scores [10][5]);

int main()
{
	cout << "This program will give you the test scores and grades of a class" << endl
		<< "Would you like to input your own student data or use the data on file?" << endl
		<< "(Enter 0 to input custom data, or anything else to use the default data)" << endl;

	string input;
	cin >> input;

	if (input == "0") {

		displayOption();
		readCustomStudentsAndGrades();
		averageScoreAndGrade(testScoresCustom);
		outputResults(studentsCustom);

		if (display == true) {
			infoDisplay(studentsCustom, testScoresCustom);
			classAverage(testScoresCustom);
		}

	}
	else {
		displayOption();
		averageScoreAndGrade(testScores);
		outputResults(students);

		if (display == true) {
			 infoDisplay(students, testScores);
			 classAverage(testScores);
		}
	}

	cout << endl << endl;
	system("pause");
    return 0;
}

void averageScoreAndGrade(float scores[10][5]) {
	float sum;
	for (int i = 0; i < 10; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += scores[i][j];
		}
		grades[i] = sum / 5;
	}
}

void outputResults(string name[10]) {
	cout << "(Student Name - Average Test Score/Grade in Class)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   " << name[i] << " - " << grades[i] << "%" 
			<< endl;
	}
	cout << endl;
}

void readCustomStudentsAndGrades() {
	cout << "Please enter the names of students 1 through 10" << endl << endl;

	for (int i = 0; i < 10; i++) {
		cout << "Student " << i + 1 << ": ";
		cin >> studentsCustom[i];
	}
	cout << endl;

	cout << "Please enter the 5 test scores of each student" << endl << endl;

	for (int i = 0; i < 10; i++) {
		cout << "   " << studentsCustom[i] << endl << "   ";
		for (int j = 0; j < 5; j++) {
			cout << "Test " << j + 1 << ": ";
			cin >> testScoresCustom[i][j];
			cout << "   ";
		}
		cout << endl;
	}
}

void classAverage(float scores[10][5]) {
	float classAverage = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++){
			classAverage += scores[i][j];
		}
	}
	
	classAverage = classAverage / 50;
	cout << "   The class average is " << classAverage << "%" << endl;
}

void infoDisplay(string names[10], float scores[10][5]) {
	cout << "(Student Records)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   " << names[i] << endl << "      ";
		for (int j = 0; j < 5; j++) {
			cout << "Test " << j + 1 << ": " << scores[i][j] << "%;  ";
		}
		cout << endl;
	}
	cout << endl;
}

void displayOption() {
	cout << "Would you like to see a readout of all the student information on file and class average as well?"
		<< endl;

	string input2;
	cin >> input2;

	if (input2 == "yes" || input2 == "Yes" || input2 == "y" || input2 == "Y") {
		display = true;
	}
	else {
		display = false;
	}
	cout << endl;
}