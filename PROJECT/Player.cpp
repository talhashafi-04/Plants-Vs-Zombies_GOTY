#include "Player.h"

Player::Player(string n="", int score=0, int level=1)
{
	name = n;
	this->level = level;
	kills = score;
}

Player::~Player()
{
}

void Player::setLevel(int l)
{
	level = l;
}

string Player::getName()
{
	return name;
}

int Player::getLevel()
{
	return level;
}

void Player::setcurrentLevel(int l)
{
	currentLevel = l;
}

int Player::getcurrentLevel()
{
	return currentLevel;
}

void Player::setName(string n)
{
	name = n;
}

int Player::getKills()
{
	return kills;
}
void Player::setKills(int k)
{
	kills = k;
}



void Player::displayOnTerminal()
{

	cout << "Name: "  << getName() << endl;
	cout << "Kills: " << getKills() << endl;
	cout << "Level: " << getLevel() << endl;
}

