#include "stdafx.h"
#include "Player.h"

using namespace std;

string playerName;
int playerLevel, statPoints, strength, maxHealth, currentHealth, dexterity, experience, toNextLevel;

Player::Player()
{
	playerLevel = 1;
	strength = 1;
	maxHealth = 10;
	currentHealth = maxHealth;
	dexterity = 5;
	experience = 0;
	toNextLevel = 100;
	statPoints = 0;
}

	

Player::~Player()
{
}
