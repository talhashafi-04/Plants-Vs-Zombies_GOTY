#include "ScoreBoard.h"

void ScoreBoard::draw(RenderWindow& window)
{
	window.clear();
	window.draw(sprite);
	for (int i = 0; i < 3; i++)
		window.draw(text[i]);
}

void ScoreBoard::update()
{
}

bool ScoreBoard::getBackToMainMenu()
{
	return BackToMainMenu;
}

void ScoreBoard::setBackToMainMenu(bool value)
{
	BackToMainMenu = value;
}

void ScoreBoard::loadScoreBoard(RenderWindow& window) {
	PlayerArray playerArray;
	playerArray.readFromFile();
	playerArray.sortPlayer();
	for (int i = 0; i < 3; i++) {
		text[i].setFont(font);
		text[i].setCharacterSize(30);
		text[i].setFillColor(Color::Black);
		text[i].setPosition(330, 255 + i * 50);
		text[i].setString("");
	}
	for (int i = 0;playerArray.getSize()>=3? i < 3: i<playerArray.getSize(); i++) {
		if (playerArray.getPlayer(i) != nullptr)
			text[i].setString(playerArray.getPlayer(i)->getName() + " " + to_string(playerArray.getPlayer(i)->getKills()));
	}

	draw(window);
}

void ScoreBoard::handleInput(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		if (!texture.loadFromFile("Assets\\Background\\scoreboard.png"))
		{
			cout << "Error loading ScoreBoard.png" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window.clear();
		if (event.type == Event::Closed )
			window.close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 399 && mousePos.x < 600 && mousePos.y>498 && mousePos.y < 540 ) {
				this->setBackToMainMenu(true);
				cout << "Back to Main Menu" << endl;
				break;
			}
		}
		if (mousePos.x > 399 && mousePos.x < 600 && mousePos.y>498 && mousePos.y < 540) {
			if (!texture.loadFromFile("Assets\\Background\\scoreboard_hover.png"))
			{
				cout << "Error loading ScoreBoard.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		draw(window);
		window.display();

	}
}

ScoreBoard::ScoreBoard()
{
	BackToMainMenu = false;
	if (!texture.loadFromFile("Assets\\Background\\scoreboard.png"))
	{
		cout << "Error loading ScoreBoard.png" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	if (!font.loadFromFile("Assets\\fonts\\Samdan.ttf"))
	{
		cout << "Error loading font" << endl;
	}
}

ScoreBoard::~ScoreBoard()
{
}

