#include "TakeName.h"

TakeName::TakeName(PlayerArray& pArr, Player*& cP) : playerarray(pArr), currentPlayer(cP)
{
	NameEntered = false;
	clickname = false;
	name = "";
	if (!texture.loadFromFile("Assets\\Background\\entername.png"))
	{
		cout << "Error loading EnterName.png" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	if (!font.loadFromFile("Assets/fonts/burbank.otf")) {
		std::cerr << "Error loading font!" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(36);
	text.setFillColor(sf::Color::Black);
	text.setPosition(384, 208);
	text.setString(name);
}



void TakeName::handleInput(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::TextEntered)
		{
				if (event.text.unicode < 128 && event.text.unicode != 8)
				{
					name += static_cast<char>(event.text.unicode);
					text.setString(name);
				}
				else if (event.text.unicode == 8 && name.size() > 0)
				{
					name.pop_back();
					text.setString(name);
				}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (!texture.loadFromFile("Assets\\Background\\entername.png"))
		{
			cout << "Error loading EnterName.png" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window.clear();

		

		if (mousePos.x > 367 && mousePos.x < 612 && mousePos.y>192 && mousePos.y < 263 && clickname == false) {
			if (!texture.loadFromFile("Assets\\Background\\entername_hover.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if ((mousePos.x > 367 && mousePos.x < 612 && mousePos.y>192 && mousePos.y < 263 && event.mouseButton.button == sf::Mouse::Left) || clickname == true) {
			clickname = true;
			if (!texture.loadFromFile("Assets\\Background\\entername_click.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (mousePos.x > 415 && mousePos.x < 583 && mousePos.y>409 && mousePos.y < 457) {
			if (!texture.loadFromFile("Assets\\Background\\entername_save.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 415 && mousePos.x < 583 && mousePos.y>409 && mousePos.y < 457) {
			
			uniqueName();
			NameEntered = true;
			break;
		}
		
		draw(window);
	}
}

void TakeName::uniqueName() // check if name is unique
{
	bool unique = true;
	for (int i = 0; i < playerarray.getSize(); i++)
	{
		if (name == playerarray.getPlayer(i)->getName())
		{
			currentPlayer = playerarray.getPlayer(i);
			unique = false;
			cout << "Welcome back " << currentPlayer->getName() << endl;
		}
	}
	if (unique)
	{
		currentPlayer = new Player(name, 0, 1);
		playerarray.addPlayer(name, 0, 1);
		playerarray.writeToFile();
		

	}

}

string TakeName::getName()
{
	return name;
}

Player* TakeName::getCurrentPlayer()
{
	return currentPlayer;
}

bool TakeName::getNameEntered()
{
	return NameEntered;
}
void TakeName::draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text);
}

void TakeName::update()
{
}



TakeName::~TakeName()
{
}


void TakeName::loop(RenderWindow& window)
{

	while (!getNameEntered()) {
		handleInput(window);
		window.clear();
		draw(window);
		window.display();
	}
}