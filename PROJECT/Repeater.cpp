#include "Repeater.h"
#include "Pea.h"
#include "MovingObjectArr.h"
#include "Bullet.h"
Repeater::Repeater()
{
	cost = 150;
	health = 10;
	damage = 10;

	bulletInterval = 4;
	bulletTimer = 0;

	bulletinterval_2 = 4;
	bulletTimer_2 = 0.7;
	
}

void Repeater::shoot(float dt, MovingObjectArr* movingObjectArray)
{
	bulletTimer += dt;
	bulletTimer_2 += dt;

	if (bulletTimer > bulletInterval)
	{
		Bullet* bullet = new Pea();
		bullet->setPosition(position.x + 50 , position.y);
		movingObjectArray->push_back(bullet);
		bulletTimer = 0;
	}

	if (bulletTimer_2 > bulletinterval_2)
	{
		Bullet* bullet = new Pea();
		bullet->setPosition(position.x + 50 , position.y);
		movingObjectArray->push_back(bullet);
		bulletTimer_2 = 0;

	}
}

void Repeater::draw(RenderWindow & window)
{
	string path = "Assets\\Plants\\RepeaterPea\\RepeaterPea_" + to_string(((int) (bulletTimer * 15 / 4 ))) + ".png";
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position.x  , position.y);
	window.draw(sprite);

	
}