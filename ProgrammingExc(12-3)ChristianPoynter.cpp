// ProgrammingExc(12-3)ChristianPoynter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class electionType
{
public:
	electionType::electionType();

	string *cantidateName;
	double *votesReceived, totalVotes;
	float *votePercent;
	int *rank;
	bool *unsorted;
	int totalCantidates;

	void initializeArrays(int size);
	void arrayInput();
	void calculateVotePercent();
	void calculateRank();
	void outputResults();
};

int main()
{
	electionType currentElection;
	int userIntInput;

	cout << "					---ELECTION SIMULATOR 2017---" << endl << endl 
		<< "	---This program will input data about a local election and output the results---" << endl << endl << endl
		<< "	Please enter the number of participants in the current election" << endl << endl 
		<< "	participants: ";
	cin >> userIntInput;
	cout << endl;

	currentElection.initializeArrays(userIntInput);
	currentElection.arrayInput();
	currentElection.calculateVotePercent();
	currentElection.calculateRank();
	currentElection.outputResults();

	system("pause");
    return 0;
}

electionType::electionType() {}

void electionType::initializeArrays(int size)
{
	cantidateName = new string[size];
	votesReceived = new double[size];
	votePercent = new float[size];
	rank = new int[size];
	unsorted = new bool[size];
	totalCantidates = size;
}

void electionType::arrayInput()
{
	for (int i = 0; i < totalCantidates; i++) {
		cout << "What is the name of cantidate #" << i + 1 << "?" << endl;
		getline(cin >> ws, cantidateName[i]);							// ws ignores prior whitespace so that getline() will work properly
		cout << "And how many votes did " << cantidateName[i] << " receive?" << endl;
		cin >> votesReceived[i];
		cout << endl << "	-Input for cantidate #" << i + 1 << " taken-" << endl << endl;
		unsorted[i] = true;
	}

	cout << endl << "	--Thank you! All cantidate information processed--" << endl << endl << endl;
}

void electionType::calculateVotePercent()
{
	totalVotes = 0;

	for (int i = 0; i < totalCantidates; i++)
	{
		totalVotes += votesReceived[i];
	}

	// debug cout to check that loop worked properly
	// cout << "Total votes cast in this eleciton - " << totalVotes << endl;

	for (int i = 0; i < totalCantidates; i++)
	{
		votePercent[i] = (votesReceived[i] / totalVotes) * 100;

		//debug cout for votePercent calculation and assigment
		// cout << cantidateName[i] << ": " << votePercent[i] << "%" << endl;
	}

}

// This function calculates rank by running two nested for loops inside of a larger for loop
// The uppermost loop holds the value that will ultimately be assigned as a rank, hence it being base 1
// with every iteration that this top loop runs, the loops inside of it calculate the largest percentage remaining,
// then find the array index which correspond to this largest percent so that highest remaining rank can be assigned to that index.
// Upon completion, a flag at the index that was just assigned is tripped so that the algorithm will ignore it on the next pass.
// This enables the same algorithm to now calculate the next highest rank by setting the currentLargestPercent variable back to 0
// and repeating the process with the remaining indicies which have not been assigned a rank yet

void electionType::calculateRank()
{
	float currentLargestPercent;

	for (int i = 1; i <= totalCantidates; i++)
	{
		currentLargestPercent = 0;

		for (int j = 0; j < totalCantidates; j++)
		{
			if (votePercent[j] >= currentLargestPercent && unsorted[j] == true)
			{
				currentLargestPercent = votePercent[j];
			}
		}

		// cout << "Current Largest Percent: " << currentLargestPercent << "%" << endl;

		for (int j = 0; j < totalCantidates; j++)
		{
			if (votePercent[j] >= currentLargestPercent && unsorted[j] == true)
			{ 
				rank[j] = i;
				unsorted[j] = false;
			}
		}
	}

	// debug output to check rank assignment
	// for (int i = 0; i < totalCantidates; i++)
	// {
	//  	cout << cantidateName[i] << ": #" << rank[i] << endl;
	// }
}

void electionType::outputResults()
{
	cout << "					---Results---" << endl << endl;

	for (int i = 1; i <= totalCantidates; i++)
	{
		for (int j = 0; j < totalCantidates; j++)
		{
			if (rank[j] == i) 
			{
				cout << "		Cantidate #" << i << ": " << cantidateName[j] << endl
					<< "		Votes Received: " << votesReceived[j] << endl
					<< "		Percentage of Total Votes: " << votePercent[j] << "%" << endl << endl;
			}
		}
	}
	cout << "		Total Votes Cast: " << totalVotes << endl << endl << endl;
}