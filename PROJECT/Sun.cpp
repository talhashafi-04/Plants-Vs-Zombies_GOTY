#include "Sun.h"
#include <string>
#include <iostream>
using namespace std;


Sun::Sun()
{
	name = "Sun";
	type = "Sun";
	isFalling = false;
	isSelecting = false;
	isAlive = true;
	dx = 0;
	dy = 0;
	texture.loadFromFile("Assets\\Plants\\Sun\\Sun_0.png");
	sprite.setTexture(texture);
	sprite.setScale(0.8, 0.8);
	sunTimer = 0;
	sunInterval = 10;
}

Sun::~Sun()
{
}

void Sun::draw(RenderWindow & window)
{
	
	if (this -> isAlive)
	{
		string path = "Assets\\Plants\\Sun\\Sun_" + to_string((int)(sunTimer * 21.0 / 10)) + ".png";
		texture.loadFromFile(path);
		sprite.setTexture(texture);



		sprite.setPosition(position.x, position.y);
		window.draw(sprite);
	}
	
}


void Sun::move(float time)
{
	sunTimer += time;
	if (sunTimer >= sunInterval)
	{

		sunTimer = 0;
	}

	if (isFalling)
	{	
		position.y += dy ;      
		if ( position.y >= FallingPosition.y)
		{
			isFalling = false;
		}
	}

	if(isSelecting)
	{
		position.x += dx;
		position.y += dy;
		

		if(position.x <= 112 && position.y <= 27)
		{
			isSelecting = false;
		}
	}	
}


void Sun::setFallingPosition(float x, float y)
{
	
	isSelecting = false;
	isFalling = true;
	dx = 0;
	dy = 0.5;
	FallingPosition.x = x;
	FallingPosition.y = y;
	position.x = x;
	position.y = 0;

}

void Sun::setSelecting()
{
	
	isSelecting = true;
	isFalling = false;

	//112 27
	dx = (112 - position.x) / 100;
	dy = (27 - position.y) / 100;

	

}


void Sun::update(float x, float y)
{
	if (x > position.x && x < position.x + 150 && y > position.y && y < position.y + 150)
	{
		isSelecting = true;
		isFalling = false;
		setSelecting();
	}
	
}

