#include "GameObject.h"
#include <iostream>
using namespace std;


int GameObject::count = 0;

GameObject::GameObject() : maxFrame(1), isAlive(true), position{ 0,0 }, frame(0)
{
	count++;
}


bool GameObject::isExist()
{
	
	return isAlive ;
}

void GameObject::setisAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int GameObject::getCount()
{
	return count;
}

void GameObject::setPosition(Point  p)
{
	position.x = p.x;
	position.y = p.y;
}

void GameObject::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

string GameObject ::  getName()
{
	return name ;
}

Point GameObject::getPosition()
{
	return this -> position;

}



Texture GameObject::getTexture()
{
	return this->texture;
}

