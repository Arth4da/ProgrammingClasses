// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Player.h"
using namespace std;

bool gameOver = false;
void displayCommands();
int adventureCount;
string answer;

class Inventory {
	int potion, superPotion, grandPotion;
	int weapon;
};

class Weapon {
	float damage;
};

class Enemy {
	float enemyHealth, enemyStrength;
	float enemyAttack() {};
};

void intro(Player& yourHero);

int main()
{
	Player hero;
	intro(hero);

	while (gameOver == false) 
	{
		string playerInput;
		cin >> playerInput;
		if (!cin.fail()) 
		{
			if (playerInput == "/commands") 
			{
				displayCommands();
			}
			else if (playerInput == "/quit") 
			{
				cout << "Are you sure you want to quit?" << endl;
				cin >> answer;
				if (answer == "Y" || answer == "YES" || answer == "Yes" || answer == "yes" || answer == "y") 
				{
					gameOver = true;
					break;
				}
			}
			else if (playerInput == "/stats") 
			{
				hero.displayInfo();
			}
			else if (playerInput == "/rest") 
			{
				hero.currentHealth = hero.maxHealth;
				cout << "Health fully restored!" << endl << endl;
			}
			else if (playerInput == "/debugLevelUp")
			{
				hero.levelUp();
			}
			else if (playerInput == "/spendPoints")
			{
				hero.spendPoints();
			}
			else if (playerInput == "/debugTakeDamage") 
			{
				cout << "How much damage?" << endl;
				int debugDmg;
				cin >> debugDmg;
				hero.takeDamage(debugDmg);
				cout << endl;
			} 
			else 
			{
				cout << endl;
			}
		}
	}

	cout << endl << endl;
	system("pause");
    return 0;
}

void displayCommands() {
	cout << "---Command List---" << endl << "/stats" << endl 
		<< "/adventure" << endl << "/rest" << endl << "/item" << endl << "/attack" << endl
		<< "/commands" << endl << "/quit" <<endl << endl;
};

void intro(Player& yourHero) {
	cout << "---Adventure Quest Or Whatever---" << endl << "   ---2017 edition---" << endl << endl
		<< "Welcome Hero! Please enter your name" << endl << "My name is: ";
	char inputName[26];
	std::cin.getline(inputName, 25);
	yourHero.setName(inputName);
	cout << endl << endl << "Great Hero " << yourHero.playerName << "," << endl
		<< "You alone can save this generic mideval fantasy world!"
		<< endl << endl << "The evil demon king DFLKJSFKL has taken over this land" << endl
		<< "And with the power of having no vowels in his name has enslaved it's noble people"
		<< endl
		<< "Defeat monsters, explore, and level up so that you can defeat him!" << endl;

	cout << endl << "would you like to display your info now?" << endl << endl;
	cin >> answer;
	if (answer == "Y" || answer == "YES" || answer == "Yes" || answer == "yes" || answer == "y") {
		yourHero.displayInfo();
	}

	cout << endl << endl << "Okay, let's begin your adventure" << endl
		<< "For a list of commands, type in \"/commands\"" << endl
		<< "If you already know how to play, feel free to jump in!" << endl << endl;
}