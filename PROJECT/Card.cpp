#include "Card.h"

Card::Card(string name, int cost, int coolDown, Point P, bool isUnlocked)
{
	position = P;
	this->name = name;
	this->cost = cost;
	this->coolDown = coolDown;
	this->isUnlocked = isUnlocked;
	texture.loadFromFile("Assets/Inventory-GameScreen/Cards/card_" + name + "_move.png");
	sprite.setTexture(texture);
	sprite.setScale(1, 0.8);
	if (name == "Shovel" || name == "Water")
	{
		sprite.setScale(0.7, 0.7);
		position.x += 10;
		position.y += 4;

	}
	/*else if (name == "Water")
	{

		sprite.setScale(0.5, 0.5);
		position.x += 10;
		position.y += 4;
	}*/
}


void Card::draw(RenderWindow& window, string slcted)
{
	if (name == slcted)
	{
		RectangleShape rectangle(Vector2f(64, 72));
		rectangle.setFillColor(Color::Transparent);
		rectangle.setOutlineThickness(3);
		rectangle.setOutlineColor(Color::Yellow);
		rectangle.setPosition(position.x, position.y);
		window.draw(rectangle);
	}

	Font font;
	font.loadFromFile("Assets/fonts/burbank.otf");
	Text text;
	text.setFont(font);
	text.setString(to_string(cost));
	text.setCharacterSize(16);

	text.setFillColor(Color::Black);
	text.setPosition(position.x + 20 , position.y + 52 );
	

	Texture lockedTexture;
	lockedTexture.loadFromFile("Assets/Inventory-GameScreen/Cards/lock.png");
	Sprite lockedSprite;
	lockedSprite.setTexture(lockedTexture);
	lockedSprite.setPosition(position.x, position.y );
	lockedSprite.setColor(Color(128, 128, 128, 150));
	lockedSprite.setScale( 1, 0.8);
	if (!isUnlocked)
	{	
		sprite.setColor(Color(170, 170, 170));
	}
	else
	{
		sprite.setColor(Color(255, 255, 255));
	}
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
	window.draw(text);
	if(!isUnlocked)
	window.draw(lockedSprite);
}

int Card::getCost()
{
	return cost;
}

int Card::getCoolDown()
{
	return coolDown;
}

string Card::getName()
{
	return name;
}