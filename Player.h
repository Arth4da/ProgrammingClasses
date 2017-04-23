#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


class Player
{
public:
	string playerName;
	int playerLevel, statPoints, strength, maxHealth, currentHealth, dexterity, experience, toNextLevel;
	
	Player();
	~Player();
	void displayInfo() 
	{
		cout << "---Hero " << playerName << "---" << endl
			<< "Level " << playerLevel << endl << currentHealth << "/" << maxHealth << " HP" << endl 
			<< strength << " strength" << endl << dexterity << " dexterity"
			<< endl << "(" << experience << "/" << toNextLevel << ") exp" << endl << statPoints << " skill points"
			<< endl << endl;
	}
	void setName(string name)
	{
		playerName = name;
	}

	void levelUp() 
	{
		toNextLevel += toNextLevel * 1.33;
		playerLevel++;
		statPoints += 5;
		currentHealth = maxHealth;
		cout << "You gained a level!" << endl << endl;
	}

	void spendPoints() {
		cout << "Which stat do you want to increase?" << endl << endl << "(/health, /strength, or /dexterity)" << endl << endl;
		string levelInput;
		int pointNum;
		cin >> levelInput;
		if (levelInput == "/health") 
		{
			cout << "How many points do you wish to assign to health?" << endl << endl;
			cin >> pointNum;
			if (pointNum <= statPoints) 
			{
				maxHealth += pointNum;
				statPoints -= pointNum;
				cout << "Health has been increased to " << maxHealth << "!" << endl << endl;
			} 
			else 
			{
				cout << "Not enough skill points!" << endl << endl;
			}
		} 
		else if (levelInput == "/strength") 
		{
			cout << "How many points do you wish to assign to strength?" << endl << endl;
			cin >> pointNum;
			if (pointNum <= statPoints)
			{
				strength += pointNum;
				statPoints -= pointNum;
				cout << "Strength has been increased to " << strength << "!" << endl << endl;
			}
			else
			{
				cout << "Not enough skill points!" << endl << endl;
			}
		}
		else if (levelInput == "/dexterity") 
		{
			cout << "How many points do you wish to assign to dexterity?" << endl << endl;
			cin >> pointNum;
			if (pointNum <= statPoints)
			{
				dexterity += pointNum;
				statPoints -= pointNum;
				cout << "Dexterity has been increased to " << dexterity << "!" << endl << endl;
			}
			else
			{
				cout << "Not enough skill points!" << endl << endl;
			}
		}
		else 
		{
			cout << "input not recognized, please try again" << endl << endl;
		}
	}

	void takeDamage(int dmgAmt)
	{
		currentHealth -= dmgAmt;
	};

private:

	float attack(float weaponDamage) 
	{
		float totalDamage = strength + weaponDamage;
		return totalDamage;
	};

	float heal() {};
};

