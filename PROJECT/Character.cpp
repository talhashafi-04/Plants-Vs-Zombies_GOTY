#include "Character.h"



String Character::getName() {
	return name;
}

void Character::setName(String n) {
	name = n;
}


bool Character::isExist()
{
	return health > 0 * GameObject::isExist();
}

int Character::getHealth()
{
	return health;
}

void Character::setHealth(int health)
{
	this->health = health;
}

int Character::getDamage()
{
	return damage;
}

void Character::setDamage(int damage)
{
	this->damage = damage;
}

