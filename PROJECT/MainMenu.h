#pragma once
#include "Screen.h"
#include "ScoreBoard.h"
#include "Instructions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;	
using namespace sf;

class MainMenu :public Screen
{
	bool is_logout;
	bool OpenScoreBoard;
	bool OpenSelectLevel;
	bool OpenInstructions;
	Texture texture;
	Sprite sprite;
	bool WantsToStartGame;
public:
	MainMenu();
	~MainMenu();
	void setOpenSelectLevel(bool);
	bool getOpenSelectLevel();
	void setOpenInstructions(bool);
	bool getOpenInstructions();
	void setOpenScoreBoard(bool);
	bool getOpenScoreBoard();
	bool getWantsToStartGame();
	void setWantsToStartGame(bool);
	void draw(RenderWindow&);
	void update();
	void handleInput(RenderWindow&);
	bool get_islogout();
	void setCheckForLogout(bool);
};

