#include "MainMenu.h"


void MainMenu::draw(RenderWindow& window)
{
	Font font; 
	if (!font.loadFromFile("Assets\\Fonts\\burbank.otf"))
	{
		cout << "Error loading font" << endl;
	}
	Text text;
	text.setFont(font);
	text.setString("Press Esc to Logout");
	text.setCharacterSize(50);
	text.setFillColor(Color::Black);
	text.setPosition(20 , 20 );
	window.draw(sprite);
	window.draw(text);
}

void MainMenu::update()
{
}

void MainMenu::setOpenInstructions(bool value)
{
	OpenInstructions = value;
}

void MainMenu::setOpenScoreBoard(bool value)
{
	OpenScoreBoard = value;
}

void MainMenu::setOpenSelectLevel(bool value)
{
	OpenSelectLevel = value;
}

bool MainMenu::getOpenInstructions()
{
	return OpenInstructions;
}

bool MainMenu::getWantsToStartGame()
{
	return WantsToStartGame;
}
void MainMenu::setWantsToStartGame(bool value)
{
	WantsToStartGame = value;
}

bool MainMenu::getOpenScoreBoard()
{
	return OpenScoreBoard;
}

bool MainMenu::getOpenSelectLevel()
{
	return OpenSelectLevel;
}

void MainMenu::handleInput(RenderWindow& window)
{


	Event event;
	
	while (window.pollEvent(event))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (!texture.loadFromFile("Assets\\Background\\mm.png"))
		{
			cout << "Error loading MainMenu.png" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window.clear();


		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape )
			{
				is_logout = true; 

			}

		}
		if (event.type == Event::Closed || (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 593 && mousePos.x < 890 && mousePos.y>451 && mousePos.y < 507))
			window.close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 627 && mousePos.x < 856 && mousePos.y>226 && mousePos.y < 300 ) {
				OpenSelectLevel = true;
				cout << "SelectLevel" << endl;
			}
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 627 && mousePos.x < 856 && mousePos.y>383 && mousePos.y < 440) {
				OpenScoreBoard = true;
				cout << "ScoreBoardtrue" << endl;
			}
			if (event.mouseButton.button == sf::Mouse::Left && mousePos.x > 627 && mousePos.x < 856 && mousePos.y>315 && mousePos.y < 372) {
				OpenInstructions = true;
				cout << "Instructions" << endl;
			}
		}
		if (mousePos.x > 627 && mousePos.x < 856 && mousePos.y>226 && mousePos.y < 300) {
			if (!texture.loadFromFile("Assets\\Background\\mm_SelectLevel.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (mousePos.x > 627 && mousePos.x < 856 && mousePos.y>315 && mousePos.y < 372) {
			if (!texture.loadFromFile("Assets\\Background\\mm_Instructions.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (mousePos.x > 627 && mousePos.x < 856 && mousePos.y>383 && mousePos.y < 440) {
			if (!texture.loadFromFile("Assets\\Background\\mm_HighScore.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}
		if (mousePos.x > 593 && mousePos.x < 890 && mousePos.y>451 && mousePos.y < 507) {
			if (!texture.loadFromFile("Assets\\Background\\mm_Exit.png"))
			{
				cout << "Error loading MainMenu.png" << endl;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
		}


		draw(window);
	}
}


MainMenu::MainMenu()
{
	is_logout = false;
	WantsToStartGame = false;
	OpenSelectLevel = false;
	OpenInstructions = false;
	OpenScoreBoard = false;


	if (!texture.loadFromFile("Assets\\Background\\entername.png"))
	{
		cout << "Error loading EnterName.png" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	
}

bool MainMenu::get_islogout()
{
	return is_logout;
}
MainMenu::~MainMenu()
{
}




void MainMenu::setCheckForLogout(bool b)
{
	is_logout = b;
}