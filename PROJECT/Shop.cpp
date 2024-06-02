#include "Shop.h"




Shop::Shop(int level)
{
	this->level = level;
	sun = 1000;
	listOfCards[0] = new Card("SunFlower", 50, 5, Point(25, 25), true);
	listOfCards[1] = new Card("PeaShooter", 100, 5, Point(25, 105), true);
	listOfCards[2] = new Card("WallNut", 50, 5, Point(25, 185), level > 1); // level > 1 
	listOfCards[3] = new Card("CherryBomb", 150, 5, Point(25, 265), level > 1); //  level > 1
	listOfCards[4] = new Card("Cactus", 100, 5, Point(25, 345), level > 1);
	listOfCards[5] = new Card("Repeater", 200, 5, Point(25, 425), level > 2); // level > 1
	listOfCards[6] = new Card("FrozenPeaShooter", 175, 5, Point(25, 505), level > 2); // level > 2
	listOfCards[7] = new Card("Shovel", 0, 0, Point(90 , 115), true);
	listOfCards[8] = new Card("Water", 50, 5, Point(90 , 190), true);
	selectedPlant = nullptr;
}

void Shop::draw(RenderWindow & window)
{

	
	Sprite sunBankSprite;
	Texture sunBankTexture;

	sunBankTexture.loadFromFile("Assets\\Inventory-GameScreen\\SunBank.png");
	sunBankSprite.setTexture(sunBankTexture);
	sunBankSprite.setPosition(97, 22);

	window.draw(sunBankSprite);

	Texture shovelBanktexture;
	shovelBanktexture.loadFromFile("Assets\\Inventory-GameScreen\\ShovelBank.png");
	Sprite shovelBankSprite;
	shovelBankSprite.setTexture(shovelBanktexture);	
	shovelBankSprite.setPosition(97, 120);
	shovelBankSprite.setScale(1,1);
	window.draw(shovelBankSprite);

	shovelBankSprite.setPosition(97 , 195 );
	window.draw(shovelBankSprite);



	Font font;
	font.loadFromFile("Assets/fonts/burbank.otf");
	Text text;
	text.setFont(font);
	text.setString( to_string(sun));
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(115,80);
	window.draw(text);
	for (int i = 0; i < 9 ; i++)
	{
		string name = "";
		if (selectedPlant != nullptr)
			name = selectedPlant->getName();
			
		 listOfCards[i]->draw(window, name );
	}
}

//void Shop::update()
//{
//	for (int i = 0; i < noOfPlants; i++)
//	{
//		if (coolDown[i].getElapsedTime().asSeconds() > 5)
//		{
//			coolDown[i].restart();
//		}
//	}
//}

void Shop::selectPlant(string name)
{
	if (name == "none")
	{
		selectedPlant = nullptr;
	}
}

void Shop::incrementSun(int sun)
{
	this->sun += sun;
}

//void Shop::buyPlant(int index)
//{
//	if (sun >= 50 && coolDown[index].getElapsedTime().asSeconds() > 5)
//	{
//		sun -= 50;
//		coolDown[index].restart();
//	}
//}

void Shop::setSun(int sun)
{
	this->sun = sun;
}

int Shop::getSun()
{
	return sun;
}


string Shop::getSelectedPlant()
{
	return selectedPlant->getName();
}

bool Shop::isPurchasable()
{
	if (selectedPlant != nullptr && sun >= selectedPlant->getCost())
	{
		return true;
	}
	return false;
}



void Shop::purchase()
{
	sun -= selectedPlant->getCost();
}

void Shop::selectPlant(float x , float y  ) {

	Card * selectedPlant = nullptr;
	Point startingPosition(25, 25);

	if (x >= 25 && x <= 25 + 64)
	{
		if (y >= 25 && y <= 25 + 80 )
		{
			selectedPlant = listOfCards[0];
		}
		else if (y >= 105 && y <= 105 + 80)
		{
			selectedPlant = listOfCards[1];
		}
		else if (y >= 185 && y <= 185 + 80 && level > 1 )
		{
			selectedPlant = listOfCards[2];
		}
		else if (y >= 265 && y <= 265 + 80 && level > 1)
		{
			selectedPlant = listOfCards[3];
		}
		else if (y >= 345 && y <= 345 + 80 && level > 1)
		{
			selectedPlant = listOfCards[4];
		}
		else if (y >= 425 && y <= 425 + 80 && level > 2)
		{
			selectedPlant = listOfCards[5];
		}	
		else if (y >= 505 && y <= 505 + 80 && level > 2)
		{
			selectedPlant = listOfCards[6];
		}
		
		
		
	}
	if (y >= 125 && y <= 195 && x >= 110 && x <= 180)
	{
		selectedPlant = listOfCards[7];
	}
	else if (y >= 200 && y <= 270 && x >= 110 && x <= 280)
	{
		selectedPlant = listOfCards[8];
	}


	if (this->selectedPlant == selectedPlant)
	{
		this->selectedPlant = nullptr;
	}
	else
	{
		if (selectedPlant != nullptr)
		this->selectedPlant = selectedPlant;
	}
}