#include "LawnMower.h"




LawnMower::LawnMower()
{
	texture.loadFromFile("Assets/LawnMower/unactivated.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 100, 100));
	sprite.setPosition(0, 0);
	movingTexture.loadFromFile("Assets/LawnMower/activated.png");
	movingSprite.setTexture(movingTexture);
	movingSprite.setPosition(0, 0);
	dx = 6 ;
	dy = 0;
	type = "LawnMower";
	name = "LawnMower";
}

void LawnMower::update(float x, float y)
{
	position.x = x;
	position.y = y;
}

void LawnMower::draw(RenderWindow& window)
{
	if (isMoving)
	{
		movingSprite.setPosition(position.x, position.y);
		int currentFrame = (int)(animationTimer * 14 / 4);
		movingSprite.setTextureRect(IntRect(3 - currentFrame / 6, currentFrame % 6, 100, 100));
		window.draw(movingSprite);
	}
	else
	{
		sprite.setPosition(position.x, position.y);
		window.draw(sprite);
	}

}


void LawnMower::move(float deltaTime)
{

	animationTimer += deltaTime;
	if (animationTimer >= 4)
	{
		animationTimer = 0;
	}

	if (isMoving)
	{
		position.x += dx;

	}
}

LawnMower::~LawnMower()
{
}


void LawnMower::setIsMoving(bool isMoving)
{
	this->isMoving = isMoving;
}


bool LawnMower::getIsMoving()
{
	return isMoving;cout << "LawnMower.cpp" << endl;
}


