#include "PeaShooter.h"
#include <iostream>
using namespace sf;
#include <SFML/Graphics.hpp>
#include "Pea.h"

PeaShooter::PeaShooter() 
{
	cost = 100;
	health = 500;
	damage = 10;

	bulletInterval = 4;
	bulletTimer = 0;
	
	
	

	if (!texture.loadFromFile("Assets\\Plants\\Peashooter\\Peashooter_0.png"))
	{
		cout << "Error loading Peashooter.png" << endl;

	}
	sprite.setTexture(texture);
	

}

void PeaShooter::shoot(float deltaTime , MovingObjectArr* movingObjectArr) {
	
		bulletTimer += deltaTime;
		if (bulletTimer >= bulletInterval) {
			bulletTimer = 0;
			
			Pea* bullet = new Pea();
			bullet->setPosition(position.x + 50 , position.y );
			movingObjectArr->push_back(bullet);
		}
}



PeaShooter::~PeaShooter()
{
	
}


void PeaShooter :: draw(RenderWindow& window) {

	string path = "Assets\\Plants\\Peashooter\\Peashooter_" + to_string((int)(bulletTimer * (12.0 / 4.0))) + ".png";
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);


	window.draw(sprite);
	
}