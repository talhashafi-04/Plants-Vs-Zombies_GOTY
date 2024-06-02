#pragma once
#include "Screen.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;


class SelectLevel : public Screen
{
	Player*& currentPlayer;
	Texture texture;
	Sprite sprite;
	bool StartGame;
	int Level;
public:
	SelectLevel(Player*&);
	~SelectLevel();
	void draw(RenderWindow& window);
	void update();
	void handleInput(RenderWindow& window);
	void setStartGame(bool value);
	bool getStartGame();
	void setLevel(int value);
	int getLevel();
};

