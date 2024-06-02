#include "Game.h"
#include "BeginnersGarden.h"
#include "ZombieOutskirts.h"
#include "SunflowerFields.h"
#include "Zombie.h"
#include <iostream>
using namespace std;



Game::Game( Player *& cplayer ):selectLevel(cplayer)
{

	currentPLayer = cplayer;
	
}





Game :: ~Game()
{
	delete level;
}


void Game::loadLevel()
{
	levelNumber = selectLevel.getLevel();
	currentPLayer->setcurrentLevel(levelNumber);

	if (level != nullptr)
	{
		delete level;
	}


	if (levelNumber == 1) {
		this->level = new BeginnersGarden(1);
	}
	else if (levelNumber == 2) {
		this->level = new ZombieOutskirts(2);
	}
	else if (levelNumber == 3) {
		this->level = new SunflowerFields(3);
	}
	else {
		cout << "Invalid Level" << endl;

	}
}




void Game::update(float deltaTime)
{
	if (levelEnded == false)
	{
		level->update(deltaTime);

		if (level->getIsEnd())
		{
			levelEnded = true;
			currentPLayer ->setKills(currentPLayer->getKills() + Zombie:: killCount );
			Zombie :: killCount = 0 ;

			if (level->getIsWon())
			{
				if (currentPLayer->getLevel() < 3 && currentPLayer->getLevel() <= levelNumber )
				{
					currentPLayer->setLevel(currentPLayer->getLevel() + 1);

				}
				cout << "Level Completed" << endl;
				cout << "Current Level: " << currentPLayer->getLevel() << endl;
				cout << "Current Player: " << currentPLayer->getName() << endl;
				cout << "Kills: " << currentPLayer->getKills() << endl;
				cout << "--------------------------------" << endl;
				cout << endl;
			}
			else
			{
				cout << "Level Lost" << endl;
				cout << "Current Level: " << currentPLayer->getLevel() << endl;
				cout << "Current Player: " << currentPLayer->getName() << endl;
				cout << "Kills: " << currentPLayer->getKills() << endl;
				cout << "--------------------------------" << endl;
				cout << endl;
			}


		}
	}
	
}

void Game::draw(RenderWindow& window)
{
	if(levelEnded == false)
	level->draw(window);
	else
	{
		handleScreen(window);
		levelEnded = false;
		loadLevel();
	}

}


void Game::takeInput(RenderWindow& window )
{
	level->takeInput(window );
}




void Game::handleScreen(RenderWindow& window)
{
	while (!mainMenu.getWantsToStartGame() && !mainMenu.get_islogout())
	{

		mainMenu.handleInput(window);
		window.clear();
		mainMenu.draw(window);
		window.display();
		while (mainMenu.getOpenInstructions()) {
			instructions.handleInput(window);
			window.clear();
			instructions.draw(window);
			window.display();
			if (instructions.getBackToMainMenuI())
			{
				mainMenu.setOpenInstructions(false);
				instructions.setBackToMainMenuI(false);
			}
		}
		while (mainMenu.getOpenScoreBoard()) {
			scoreBoard.loadScoreBoard(window);
			scoreBoard.handleInput(window);
			window.clear();
			scoreBoard.draw(window);
			window.display();
			if (scoreBoard.getBackToMainMenu())
			{
				mainMenu.setOpenScoreBoard(false);
				scoreBoard.setBackToMainMenu(false);
			}
		}
		while (mainMenu.getOpenSelectLevel()) {
			selectLevel.handleInput(window);
			window.clear();
			selectLevel.draw(window);
			window.display();
			if (selectLevel.getStartGame())
			{
				mainMenu.setWantsToStartGame(true);
				break;
			}
		}
	}
	mainMenu.setWantsToStartGame(false);
	mainMenu.setOpenInstructions(false);
	mainMenu.setOpenScoreBoard(false);
	selectLevel.setStartGame(false);
	mainMenu.setOpenSelectLevel(false);
	scoreBoard.setBackToMainMenu(false);

	instructions.setBackToMainMenuI(false);
	

}


bool Game::checkForLogout()
{
	return mainMenu.get_islogout();
}



void Game::setCheckForLogout(bool b)
{
	mainMenu.setCheckForLogout(b);
}
