#include "Wallnut.h"



void Wallnut::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	currentposition.x = 0;
	currentposition.y = y;
}

Wallnut::Wallnut()
{
	health = 4000;
	damage = 0;
	cost = 50;
	dx = 5 ;
	isMoving = true;
	rotate = 0;

	texture.loadFromFile("Assets\\Plants\\WallNut\\WallNut\\WallNut_0.png");
	sprite.setTexture(texture);

}

Wallnut :: ~Wallnut()
{
}

void Wallnut::draw(RenderWindow& window)
{

	string path = "Assets\\Plants\\WallNut\\WallNut\\WallNut_" + to_string((int)frameTimer * 15 / 4) + ".png";


	texture.loadFromFile(path);
	sprite.setTexture(texture);



	

	if (isMoving)
	{
		sprite.setPosition(currentposition.x + 40, currentposition.y + 50 );
	}
	else
	{
		sprite.setPosition(position.x + 40 , position.y + 50 );

	}
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setRotation(rotate);
	window.draw(sprite);
}


void Wallnut::action(float deltaTime, MovingObjectArr* zombies)
{

	frameTimer += deltaTime;
	if (frameTimer >= maxFrameTime)
	{
		frameTimer = 0;
	}



	if (isMoving)
	{
		rotate += 5 ;
		currentposition.x += dx;

		if (currentposition.x >= position.x)
		{
			isMoving = false;
		}
	}
	else
	{
		rotate = 0;
	}
}


