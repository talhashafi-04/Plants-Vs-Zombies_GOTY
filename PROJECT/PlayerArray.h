#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Player.h"
#include <string>
#include <fstream>
using namespace std;
using namespace sf;

class PlayerArray{
	Player** playerList;
	int size;
public:
	PlayerArray();
	~PlayerArray();
	Player** getPlayerList();
	void addPlayer(string, int, int);
	void deletePlayer(int);
	void sortPlayer();
	void displayPlayer();
	void writeToFile();
	void readFromFile();
	void displayOnTerminal();
	void updatePlayer(string, int, int);
	int getSize();
	Player* getPlayer(int);
};


