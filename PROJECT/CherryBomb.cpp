#include "CherryBomb.h"
#include "Explosion.h"


CherryBomb::CherryBomb()
{
	this->time_to_explode = 2;
	this->cost = 150;
	this->health = 1000;
	this->exploding_radius = 100;
	this->name = "CherryBomb";
	this-> isAlive = true;
	this->is_exploding = false;
	this->texture.loadFromFile("Assets\\Plants\\CherryBomb\\CherryBomb_0.png");
	this->sprite.setTexture(this->texture);

}

 
void CherryBomb::draw(RenderWindow& window)
{
	if (isAlive)
	{

		{

			string path = "Assets\\Plants\\CherryBomb\\CherryBomb_" + to_string((((int)(this->time_exploding * 6 / 3)))) + ".png";
			this->texture.loadFromFile(path);
			this->sprite.setTexture(this->texture);
		}

		sprite.setPosition(position.x - 20, position.y);

		

		window.draw(this->sprite);
	}
}


CherryBomb :: ~CherryBomb()
{
}

bool CherryBomb::isExist()
{
	return isAlive;
}


void CherryBomb::action(float deltaTime, MovingObjectArr* movingObjectArr)
{
	if(!has_exploded)
	if (is_exploding == false)
	{
		time_exploding += deltaTime;
		if (this->time_exploding > this->time_to_explode)
		{
			is_exploding = true;

			time_exploding = 0;

		}
	}

	if (is_exploding)
	{
		Explosion* explosion = new Explosion(exploding_radius);
		explosion->setPosition(position.x,position.y);
		movingObjectArr->push_back(explosion);
			

		is_exploding = false;
		has_exploded = true;
		isAlive = false;
	}
	

}


