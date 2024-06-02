#pragma once
#include "Plant.h"
class ShootingPlant : public Plant
{
	protected :
	float BulletSpeed;
	int bulletInterval;
	float bulletTimer ;

public:
	virtual void action(float, MovingObjectArr*);
	virtual void shoot(float , MovingObjectArr*) = 0;
	virtual ~ShootingPlant() ;

};




