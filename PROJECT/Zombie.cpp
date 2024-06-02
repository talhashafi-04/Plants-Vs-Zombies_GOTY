#include "Zombie.h"

int Zombie::killCount = 0;



Zombie::Zombie() : totalFrozenTime(15)  {
	
	isMoving = true;
	isFrozenTimer = 0;
	isFrozen = false;
	totalIntervals = 0;
	timer = 0;
	state = "Moving";
	dx = 0;
	dy = 0;
}

float Zombie::getdx()
{
	return dx;
}
float Zombie::getdy()
{
	return dy;
}

void Zombie::setSpeed(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

Zombie::~Zombie()
{

}

void Zombie::draw(RenderWindow& window)
{		
	if (isExist())
	{

		sprite.setTexture(texture);
		sprite.setPosition(position.x, position.y);
		if (isFrozen)
		{
			sprite.setColor(Color(0, 0, 255, 255 ));
		}
		else
		{
			sprite.setColor(Color(255, 255, 255, 255));
		}


		window.draw(sprite);
	}
}


void Zombie::setState(std::string s)
{
	state = s;
}

std::string Zombie::getState()
{
	return state;
}

void Zombie::setIsMoving(bool b)
{
	isMoving = b;
}

bool Zombie::getIsMoving()
{
	return isMoving;
}

bool Zombie::setIsFrozen(bool isFrozen)
{
	this->isFrozen = isFrozen;
	return isFrozen;
}

void Zombie :: action(float x)
{


	timer += (x*5);
	if (timer > totalIntervals) {

		timer = 0;
	}
	if (isWithoutHead)
	{

		headTimer += (x * 15);
		if (headTimer > 20)
		{
			headTimer = 0;
			isWithoutHead = false;
		}

	}

	if (!isDying)
	{
		if (health <= 0)
		{
			isDying = true;
			headTimer = 0;
		}
	}

	if (isBurnt)
	{
		burntTimer += x;
		if (burntTimer > 10)
		{
			isAlive = false;
			isBurnt = false;
		}
	}


	if (isDying)
	{
		headTimer += x;	
		if (headTimer >= 10 )
		{
			isDying = false  ;
			
		}
	}
	isFrozenTimer += x;
	if (isFrozenTimer >= totalFrozenTime)
	{
		isFrozen = false;
		isFrozenTimer = 0;
	}
}



bool Zombie::isExist()
{

	if (health >= 0)
	{
		return true;

	}
	if (health < 0)
	{
		cout << isBurnt << endl;
		return  isBurnt ;

	}

}




void  Zombie::setBurnt()
{
	health = 0;
	isBurnt = true ;
	setState("Burning");
}

bool Zombie::isCollidable()
{
	if (health > 0)
	{
		return true;
	}
	else
		return true;

}