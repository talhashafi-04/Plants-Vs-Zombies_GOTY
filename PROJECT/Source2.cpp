#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
#include "MainMenu.h"
#include "SelectLevel.h"
#include "TakeName.h"
#include "ScoreBoard.h"
#include "Instructions.h"
#include "Level.h"
#include "Player.h"
#include "Intro.h"

using namespace sf;
using namespace std;

const int resolutionX = 1100;
const int resolutionY = 600;

const int zoom = 1;


int main()
{
	/////////////////////////////////////////
	/////////////////////////////////////////
	////////////Rendering window/////////////
	/////////////////////////////////////////
	/////////////////////////////////////////

	sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Plants Vs Zombies", Style::Default | sf::Style::Close);
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	int windowPositionX = (desktopMode.width - resolutionX * zoom) / 2;
	int windowPositionY = (desktopMode.height - resolutionY * zoom) / 2;
	window.setPosition(sf::Vector2i(windowPositionX, windowPositionY - 50));


	//Game icon
	Image icon;
	if (!icon.loadFromFile("Assets/Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	//Intro
	 {

			Intro intro;
			while (window.isOpen())
			{
				intro.update();
				window.clear();
				intro.draw(window);
				window.display();
				if (intro.handleInput(window))
				{
					break;
				}
			}


		}
		





	Player* currentPlayer;
	PlayerArray playerarrayMain;

	while(1)
	{
		
		playerarrayMain.readFromFile();
		playerarrayMain.sortPlayer();
		playerarrayMain.displayOnTerminal();
		TakeName takeName(playerarrayMain, currentPlayer);
		takeName.loop(window);

		//Sound
		
		SoundBuffer MainmenuSoundBuffer;
		MainmenuSoundBuffer.loadFromFile("Assets/Sounds/OOP music assets/06. Main Music 00.mp3");
		Sound MainmenuSound;
		MainmenuSound.setBuffer(MainmenuSoundBuffer);
		MainmenuSound.play();



		Player* currentplayer = takeName.getCurrentPlayer();
		currentPlayer->displayOnTerminal();



		////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////
		///////////////////   GAME LOOP   //////////////////////
		////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////

		Clock clock;
		Game game(currentplayer);
		game.handleScreen(window);
		game.loadLevel();
		while (window.isOpen())
		{
			if (game.checkForLogout())
			{
				game.setCheckForLogout(false);
				break;
			}
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			time = time / 800;

			game.takeInput(window);
			game.update(time);
			window.clear();
			game.draw(window);
			window.display();
		}

		playerarrayMain.updatePlayer(currentPlayer->getName(), currentPlayer->getKills(), currentPlayer->getLevel());
		playerarrayMain.writeToFile();
	}
	
	
	return 0;

}














