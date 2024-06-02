#pragma once

#include "Screen.h"
#include "Player.h"
#include "PlayerArray.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace sf;


class TakeName : public Screen
{
	Font font;
	Text text;
	string name;

	PlayerArray& playerarray;
	bool NameEntered;
	bool clickname;
	Texture texture;
	Sprite sprite;
	Player*& currentPlayer;

public:
	TakeName(PlayerArray&, Player*&);
	~TakeName();
	void loop(RenderWindow&);
	Player* getCurrentPlayer();
	string getName();
	bool getNameEntered();
	void uniqueName();
	void draw(RenderWindow&);
	void update();
	void handleInput(RenderWindow&);
};

