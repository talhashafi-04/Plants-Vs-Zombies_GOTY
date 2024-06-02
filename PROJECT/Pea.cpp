#include "Pea.h"

Pea::Pea()
{
	name = "Pea";
	this->damage = 1;
	this->count++;
	this->isAlive = true;
	this->position = { 0, 0 };
	this->dx = 2 ;
	this->dy = 0;
	this->texture.loadFromFile("Assets\\Bullets\\PeaNormal\\pea.png");
	this->sprite.setTexture(texture);


}

void Pea::move(float )
{
	this->position.x += this->dx;
	this->position.y += this->dy;

}


