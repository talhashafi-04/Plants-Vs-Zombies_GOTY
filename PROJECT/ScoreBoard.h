#pragma once
#include "Screen.h"
#include "Player.h"
#include "PlayerArray.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace sf;

class ScoreBoard :public Screen
{
	Font font;
	Text text[3];
	Texture texture;
	Sprite sprite;
	bool BackToMainMenu;

public:
	ScoreBoard();
	~ScoreBoard();
	void loadScoreBoard(RenderWindow&);
	bool getBackToMainMenu();
	void setBackToMainMenu(bool);
	void draw(RenderWindow&);
	void update();
	void handleInput(RenderWindow&);
};

