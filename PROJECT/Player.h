#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace sf;



class Player
{	
	string name;
	int level;
	int kills;
	int currentLevel;
public:
	Player(string,int,int);
	string getName();
	~Player();
	void setcurrentLevel(int);
	int getcurrentLevel();
	int getLevel();
	int getKills();
	void setName(string);
	void setLevel(int);
	void setKills(int);
	void displayOnTerminal();
};


