#include "SunFlower.h"
#include "Sun.h"



void SunFlower::action(float deltaTime , MovingObjectArr* movingObjectArr )
{
	sunTimer += deltaTime;
	if (sunTimer >= 10)
	{
		sunTimer = 0;
		generateSun(movingObjectArr);
		
	}
}

SunFlower::SunFlower()
{
	name = "SunFlower";
	health = 10;
	isAlive = true;
	sunTimer = 0;
	sunInterval = 24 ;
	texture.loadFromFile("Assets\\Plants\\SunFlower\\SunFlower_0.png");
	sprite.setTexture(texture);
	cost = 50;
	position.x = 0;
	position.y = 0;
	cout << "SunFlower created" << endl;
}

void SunFlower::generateSun(MovingObjectArr* movingObjectArray)
{
	MovingObject* sun = new Sun();
	int x_rand = rand() % 5;
	int y_rand = rand() % 5;
	sun->setPosition(sprite.getPosition().x +  x_rand * 10 , sprite.getPosition().y + x_rand * 5);
	movingObjectArray->push_back(sun);

}

void SunFlower::draw(sf::RenderWindow& window)
{
	string path = "Assets\\Plants\\SunFlower\\SunFlower_" + to_string((int)(sunTimer * 17/ 10.0)) + ".png";

	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}

SunFlower::~SunFlower()
{
	cout << "SunFlower destroyed" << endl;
}
