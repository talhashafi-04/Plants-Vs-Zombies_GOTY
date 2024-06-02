#include "Cactus.h"

Cactus::Cactus()
{
	name = "Cactus";
	cost = 100;
	health = 1000;
	texture.loadFromFile("Assets/Plants/Cactus.png");
	sprite.setTexture(texture);
	sprite.setScale(0.2,0.2);
	sprite.setOrigin(0,180 );
}



void Cactus::action(float deltaTime , MovingObjectArr*)
{
}

void Cactus::draw(RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}


void Cactus::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}


Cactus::~Cactus()
{
}