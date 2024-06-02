#include "Bullet.h"



Bullet::Bullet()
{
	type = "Bullet";
	damage = 0;

}

float Bullet::getDamage()
{
	return damage;
}

void Bullet :: draw(RenderWindow & window )
{

	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}

void Bullet::move(float)
{
	position.x += dx;
	position.y += dy;
}

void Bullet::update(float time, float speed)
{
}


bool Bullet::isExist()
{
	if (!(position.x <= 1100 && position.y <= 600))
		isAlive = false;

	return isAlive;
}

