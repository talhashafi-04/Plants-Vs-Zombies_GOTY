#pragma once
#ifndef Game_h
#define Game_h
#include "Level.h"
#include "Player.h"
#include "MainMenu.h"
#include "SelectLevel.h"
#include "Instructions.h"
#include "ScoreBoard.h"
#include "PlayerArray.h"




class Game
{

	//Screens

	MainMenu mainMenu;
	SelectLevel selectLevel;
	Instructions instructions;
	ScoreBoard scoreBoard;


	//ScoreBoard scoreBoard;
	bool levelEnded = false;
	int levelNumber;
	Level* level;

	Player * currentPLayer;
public:

	void setCheckForLogout(bool);
	bool checkForLogout();
	void handleScreen(RenderWindow& window);
	void loadLevel();
	

	void update(float deltaTime);
	void draw(RenderWindow& window);
	void takeInput(RenderWindow& );

	Game(Player *& );
	~Game();

	/*void startGame();
	void exitgame();
	void saveGame();
	void showPlayers(); */

};



#endif 



