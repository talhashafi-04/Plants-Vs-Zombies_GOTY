#include "MovingObject.h"




void MovingObject::setVelocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

float MovingObject::getdx()
{
	return dx;
}

float MovingObject::getdy()
{
	return dy;
}


string MovingObject::getType()
{
	return type;
}