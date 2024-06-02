#include "SelectLevel.h"

SelectLevel::SelectLevel(Player*& cp):currentPlayer(cp)
{
	StartGame = false;
	Level = 0;
	if (!texture.loadFromFile("Assets\\Background\\selectlevel.png"))
	{
		cout << "Error loading SelectLevel.png" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

void SelectLevel::setStartGame(bool value)
{
	StartGame = value;
}

bool SelectLevel::getStartGame()
{
	return StartGame;
}

void SelectLevel::setLevel(int value)
{
	Level = value;
}

int SelectLevel::getLevel()
{
	return Level;
}

SelectLevel::~SelectLevel()
{
}

void SelectLevel::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void SelectLevel::update()
{
}

void SelectLevel::handleInput( RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		if (event.type == Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed) 
		{
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 340 && mousePos.x < 670 && mousePos.y>200 && mousePos.y < 280)
			{
				this->setStartGame(true);
				currentPlayer->setcurrentLevel(1);
				this->setLevel(1);
				if (!texture.loadFromFile("Assets\\Background\\selectlevel1.png"))
				{
					cout << "Error loading 1.png" << endl;
				}
				sprite.setTexture(texture);
				sprite.setPosition(0, 0);
				window.clear();
				draw(window);
				break;

			}
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 340 && mousePos.x < 670 && mousePos.y>305 && mousePos.y < 390 && currentPlayer->getLevel()>= 2) {
				this->setStartGame(true);
				currentPlayer->setcurrentLevel(2);
				this->setLevel(2);
				currentPlayer->displayOnTerminal();
				if (!texture.loadFromFile("Assets\\Background\\selectlevel2.png"))
				{
					cout << "Error loading 2.png" << endl;
				}
				sprite.setTexture(texture);
				sprite.setPosition(0, 0);
				window.clear();
				draw(window);
				break;
			}
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 340 && mousePos.x < 670 && mousePos.y>413 && mousePos.y < 500 && currentPlayer->getLevel() >= 3) {
				this->setStartGame(true);
				this->setLevel(3);
				currentPlayer->setcurrentLevel(3);
				if (!texture.loadFromFile("Assets\\Background\\selectlevel3.png"))
				{
					cout << "Error loading 3.png" << endl;
				}
				sprite.setTexture(texture);
				sprite.setPosition(0, 0);
				window.clear();
				draw(window);
				break;
			}
		}


		if (mousePos.x > 340 && mousePos.x < 670 && mousePos.y>200 && mousePos.y < 280 && currentPlayer->getLevel() >= 2) {
			if (!texture.loadFromFile("Assets\\Background\\selectlevel1.png"))
			{
				cout << "Error loading 1.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
			window.clear();
			draw(window);
			break;

		}
		else if (mousePos.x > 340 && mousePos.x < 670 && mousePos.y>305 && mousePos.y < 390) {
			if (!texture.loadFromFile("Assets\\Background\\selectlevel2.png"))
			{
				cout << "Error loading 2.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
			window.clear();
			draw(window);
			break;
		}
		else if ( mousePos.x > 340 && mousePos.x < 670 && mousePos.y>413 && mousePos.y < 500) {
			if (!texture.loadFromFile("Assets\\Background\\selectlevel3.png"))
			{
				cout << "Error loading 3.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
			window.clear();
			draw(window);
			break;
		}
	}
}