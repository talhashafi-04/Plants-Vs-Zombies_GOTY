#include "Instructions.h"

void Instructions::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Instructions::update()
{
}

bool Instructions::getBackToMainMenuI()
{
	return BackToMainMenu;
}

void Instructions::setBackToMainMenuI(bool value)
{
	BackToMainMenu = value;
}

void Instructions::handleInput(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		if (!texture.loadFromFile("Assets\\Background\\instructions.png"))
		{
			cout << "Error loading ScoreBoard.png" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window.clear();
		if (event.type == Event::Closed)
			window.close();
		if (mousePos.x > 399 && mousePos.x < 600 && mousePos.y>498 && mousePos.y < 540) {
			if (!texture.loadFromFile("Assets\\Background\\instructions_hover.png"))
			{
				cout << "Error loading ScoreBoard.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 399 && mousePos.x < 600 && mousePos.y>498 && mousePos.y < 540) {
				this->setBackToMainMenuI(true);
				cout << "Back to Main Menu" << endl;
				break;
			}
		}
		
		draw(window);
		window.display();

	}
}

Instructions::Instructions()
{
	BackToMainMenu = false;
	if (!texture.loadFromFile("Assets/Background/instructions.png"))
	{
		cout << "Error loading Instructions.png" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

Instructions::~Instructions()
{
}

