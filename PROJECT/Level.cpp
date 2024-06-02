#include "Level.h"
#include "Sun.h"
#include "LawnMower.h"
Level::Level(int levelNumber) : shop(levelNumber), levelNumber(levelNumber), lawn(levelNumber)
{
	isEnd = false;
	livesRemaining = 3;
	isPaused = false;
	last_screen = 0; 
	pauseTexture.loadFromFile("Assets\\Background\\pauseButton.png");
	pauseSprite.setTexture(pauseTexture);
	pauseSprite.setPosition(1020 , 10 );
	pauseSprite.setScale(2, 2);

	pauseScreenTexture.loadFromFile("Assets\\Background\\pauseScreen.png");
	pauseScreenSprite.setTexture(pauseScreenTexture);
	pauseScreenSprite.setPosition(50 ,0);
	pauseScreenSprite.setScale(1 , 1 );
	
	lostTexture.loadFromFile("Assets\\Background\\lost_screen.png");
	lostSprite.setTexture(lostTexture);
	lostSprite.setPosition(0, 0);
	lostSprite.setOrigin (lostTexture.getSize().x/2, lostTexture.getSize().y /2);

	winTexture.loadFromFile("Assets\\Background\\win.png");
	winSprite.setTexture(winTexture);
	winSprite.setPosition(0, 0);
	winSprite.setOrigin(winTexture.getSize().x / 2, winTexture.getSize().y / 2);

	livesTexture.loadFromFile("Assets\\Background\\3lives.png");
	livesSprite.setTexture(livesTexture);
	livesSprite.setPosition(160 , -50 );
	livesSprite.setScale(0.3, 0.3);
}

void Level::drawPause(RenderWindow& window)
{
	window.draw(pauseSprite);
	window.draw(livesSprite);
	
	if (isPaused && !is_Lost && !is_Won )
	{
		RectangleShape pauseScreen(Vector2f(1200, 800));
		pauseScreen.setFillColor(Color(0, 0, 0, 150));
		window.draw(pauseScreen);
		window.draw(pauseScreenSprite);
	}

	if (is_Lost || is_Won)
	{
		Font font;
		font.loadFromFile("Assets\\fonts\\burbank.otf");
		Text text;
		text.setFont(font);
		text.setCharacterSize(50);
		text.setFillColor(Color::White);
		text.setPosition(550, 450);
		text.setString("Press Enter to Continue");
		window.draw(text);

	}
	if (is_Lost)
	{
		if (last_screen < 1)
		{
			last_screen += 0.01;
		}
		RectangleShape pauseScreen(Vector2f(1200, 800));
		pauseScreen.setFillColor(Color(0, 0, 0, 150));
		window.draw(pauseScreen);
		lostSprite.setScale(last_screen, last_screen);
		lostSprite.setPosition(550 , 300);
		window.draw(lostSprite);
	}
	else if (is_Won)
	{
		if (last_screen < 1)
		{
			last_screen += 0.01;
		}
		RectangleShape pauseScreen(Vector2f(1200, 800));
		pauseScreen.setFillColor(Color(0, 0, 0, 150));
		window.draw(pauseScreen);
		winSprite.setScale(last_screen, last_screen);
		winSprite.setPosition(550, 300);
		window.draw(winSprite);
	}






}
void Level::drawBackround(RenderWindow& window)
{
	backgroundSprite.setPosition(0, 0);
	
	window.draw(backgroundSprite);

	

}
void Level ::loadLawnMowers()
{
	for (int i = 0; i < 5; i++)
	{
		LawnMower* lawnMower = new LawnMower();
		lawnMower->setPosition(160, 70 + i * 100);
		lawn.movingObjectsArray.push_back(lawnMower);
	}
}

void Level :: addSuntoShop()
{
	for (int i = 0; i < lawn.movingObjectsArray.getSize(); i++)
	{
		if (lawn.movingObjectsArray.at(i)->getName() == "Sun")
		{
			if(lawn.movingObjectsArray.at(i)->isExist() == true)
			if (lawn.movingObjectsArray.at(i)->getPosition().x >= 110 && lawn.movingObjectsArray.at(i)->getPosition().x <= 114 && lawn.movingObjectsArray.at(i)->getPosition().y >= 25 && lawn.movingObjectsArray.at(i)->getPosition().y <= 29)
			{
				
				lawn.movingObjectsArray.at(i)->setisAlive(false);
				shop.incrementSun(25);
			}
		}
	}
}




void Level::takeInput(RenderWindow& window)
{

	Event event;

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed)
		{

			if (event.mouseButton.button == Mouse::Left)
			{
				Vector2i position = Mouse::getPosition(window);
				Point p = lawn.getGridPosition(position.x, position.y);

				if (!isPaused)
				{

					if (p.x >= 0 && p.x < 9 && p.y >= 0 && p.y < 5)
					{
						if (shop.isPurchasable() &&( shop.getSelectedPlant() == "Shovel" || shop.getSelectedPlant() == "Water"))
						{
							if (shop.getSelectedPlant() == "Shovel")
							{
								if (lawn.removePlant(p.x, p.y))
								{
																		shop.purchase();
									shop.selectPlant("none");
								}
								
								lawn.setBoxAvailable(p.x, p.y, true);
							}
							else if (shop.getSelectedPlant() == "Water")
							{
								if (lawn.waterPlant(p.x, p.y))
								{
									shop.purchase();
									shop.selectPlant("none");
								}
								
							}
						}
						else if (shop.isPurchasable() && lawn.isBoxAvailable(p.x, p.y))
						{

							lawn.addPlant(lawn.getGRID_START_X() + p.x * lawn.getboxWidth(), lawn.getGRID_START_Y() + p.y * lawn.getboxHieght(), shop.getSelectedPlant());
							lawn.setBoxAvailable(p.x, p.y, false);
							shop.purchase();
							shop.selectPlant("none");
						}



					}
					shop.selectPlant(position.x, position.y);


					lawn.selectSun(position.x, position.y);
				}


				if (position.x >= 1035 && position.x <= 1085 && position.y >= 25 && position.y <= 75)
				{
					isPaused = true;
				}
				if (isPaused && position.x >= 400 && position.x <= 680 && position.y >= 435 && position.y <= 475)
				{
					isPaused = false;
				}


			}
			if (event.mouseButton.button == Mouse::Right)
			{
				Vector2i position = Mouse::getPosition(window);

				cout << "PIXEL : " << position.x << " " << position.y << endl;
				Point p = lawn.getGridPosition(position.x, position.y);
				cout << "GRID : " << p.x << " " << p.y << endl;
			}


		}
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Enter)
			{
				if (is_Lost || is_Won)
				{
					isEnd = true;
				}

			}
		}
	}

}




void Level::checkLoose()
{
	if (lawn.checkLost())
	{
		if ( livesRemaining <= 1 )
		{
			isPaused = true;
			is_Lost = true;
		}
		else
		{
			livesRemaining--;
			livesTexture.loadFromFile("Assets\\Background\\" + to_string(livesRemaining) + "lives.png");
			livesSprite.setTexture(livesTexture);
		}
		
	}
}

void Level::checkWin()
{
	if (lawn.checkWin())
	{
		isPaused = true;
		is_Won = true;
	}
}





void Level::generateSun(float dt)
{

	srand(time(0));
	sunTimer += dt;
	if (sunTimer >= sunIntervals)
	{
		int T = rand() % 30;
		sunIntervals = 15 + T;

		sunTimer = 0;
		int x = rand() % 9;
		int y = rand() % 5;

		Sun* sun = new Sun();
		sun->setFallingPosition(lawn.getGRID_START_X() + x * lawn.getboxWidth() + 10, lawn.getGRID_START_Y() + y * lawn.getboxHieght() + 40);
		lawn.movingObjectsArray.push_back(sun);
	}
}


bool Level::getIsEnd()
{
	return isEnd;
}


bool Level::getIsWon()
{
	return is_Won;
}

bool Level::getIsLost()
{
	return is_Lost;
}