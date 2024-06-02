#include "FrozenPeaShooter.h"


FrozenPeaShooter::FrozenPeaShooter()
{
	cost = 150;
	damage = 20;
	cost = 100;
	health = 1000;
	damage = 10;

	bulletInterval = 4;
	bulletTimer = 0;
	texture.loadFromFile("Assets\\Plants\\SnowPea\\SnowPea_0.png");
	sprite.setTexture(texture);
}

void FrozenPeaShooter::shoot(float deltaTime, MovingObjectArr* movingObjectArr)
{
	bulletTimer += deltaTime;
	if (bulletTimer >= bulletInterval) {
		bulletTimer = 0;

		Bullet* bullet = new FrozenPea();
		bullet->setPosition(position.x + 50, position.y);
		movingObjectArr->push_back(bullet);
	}
}


FrozenPeaShooter ::	~FrozenPeaShooter()
{
}

void FrozenPeaShooter::draw(sf::RenderWindow& window)
{

	string path = "Assets\\Plants\\SnowPea\\SnowPea_" + to_string((int)(bulletTimer *(15.0/4.0))) + ".png";
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position.x , position.y);
	window.draw(sprite);

}