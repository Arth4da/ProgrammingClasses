// Chapter 9 project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct studentType
{
	string studentFName = "";
	string studentLName = "";
	int testScore = 0;
	int topStudentNum;
	char grade;
};

studentType student[19];
string loopContinue = "yes";
string userInput;
int userIntInput;

void assignStudentInfo(struct studentType &student);
void assignGrade(int score, struct studentType &student);
void viewStudentInfo(struct studentType student);
void calculateTopStudent(struct studentType student);
void commandList();

int main()
{
	cout << "     Hello and welcome to the student score database" << endl
		 << "     This database can hold the scores of 20 students," << endl
		 << "     calculate their letter grades," << endl
		 << "     and display the information of the student with the highest test score" << endl << endl;

	commandList();

	while (loopContinue == "yes") 
	{
		cout << "Command: ";
		cin >> userInput;

		if (userInput == "help") {
			commandList();
		}

		if (userInput == "assignStudentInfo") {
			cout << "     Which student record would you like to assign values to? (#1 - 20)" << endl;
			cin >> userIntInput;
			if (userIntInput > 0 && userIntInput < 21)
			{
				assignStudentInfo(student[userIntInput - 1]);
			}
			else
			{
				cout << "     Not a valid student number" << endl;
			}
			cout << endl;
		}

		if (userInput == "viewStudentInfo") {
			cout << "     Which student record would you like to view? (#1 - 20)" << endl;
			cin >> userIntInput;
			if (userIntInput > 0 && userIntInput < 21)
			{
				viewStudentInfo(student[userIntInput - 1]);
			}
			else 
			{
				cout << "     Not a valid student number" << endl;
			}
			cout << endl;
		}

		if (userInput == "viewTopStudent")
		{
			calculateTopStudent();
		}

		if (userInput == "exit") {
			loopContinue = "no";
			break;
		}
	}

    return 0;
}

void assignStudentInfo(struct studentType &student)
{
	cout << "What is the students first name?" << endl;
	cin >> student.studentFName;
	cout << "What is the students last name?" << endl;
	cin >> student.studentLName;
	cout << "what is the students test score?" << endl;
	cin >> student.testScore;
	if (student.testScore > 100) {
		student.testScore = 100;
	}
	if (student.testScore < 0) {
		student.testScore = 0;
	}
	assignGrade(student.testScore, student);

	cout << endl << "     Thank you! " << student.studentFName << " " << student.studentLName
		<< " was added to the list" << endl;
}

void assignGrade(int score, struct studentType &student)
{
	if (score < 60) {
		student.grade = 'F';
	}
	if (score >= 60) {
		student.grade = 'D';
	}
	if (score >= 70) {
		student.grade = 'C';
	}
	if (score >= 80) {
		student.grade = 'B';
	}
	if (score >= 90) {
		student.grade = 'A';
	}
}

void viewStudentInfo(struct studentType student)
{
	cout << endl << "Information for " << student.studentFName << " " << student.studentLName << endl
		 << "     Test Score: " << student.testScore << "%"
		 << "     Grade: " << student.grade;
}

void calculateTopStudent()
{
	
}

void commandList()
{
	cout << "        ---Commands---   " << endl
		<< "     \"help\" - Displays this list" << endl
		<< "     \"assignStudentInfo\" - Assigns information to a student record of your choice" << endl
		<< "     \"viewStudentInfo\" - View information for a specific student" << endl
		<< "     \"viewTopStudent\" - Displays the student in the class with the highest grade" << endl
	    << "     \"exit\" - Exits the program" << endl << endl;
}