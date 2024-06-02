#ifndef PeaShooter_h
#define PeaShooter_h

#pragma once
#include "ShootingPlant.h"

#include <iostream> 
using namespace std;
class PeaShooter :public ShootingPlant
{


public:
	PeaShooter();
	virtual void shoot( float deltaTime , MovingObjectArr* );
	~PeaShooter();
	void draw(RenderWindow & );

};


#endif // !PeaShooter_h