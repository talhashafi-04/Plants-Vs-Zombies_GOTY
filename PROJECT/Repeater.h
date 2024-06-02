#pragma once
#include "ShootingPlant.h"
#include "MovingObjectArr.h"


class Repeater : public ShootingPlant
{
	int bulletinterval_2;
	float bulletTimer_2;
public : 
	Repeater();
	void shoot(float, MovingObjectArr *)override;
	
	void draw(RenderWindow & )override;
	
};
