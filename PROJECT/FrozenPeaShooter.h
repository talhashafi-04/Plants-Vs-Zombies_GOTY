#pragma once
#include "ShootingPlant.h"
#include "Bullet.h"
#include "FrozenPea.h"
class FrozenPeaShooter : public ShootingPlant
{	
public :
	FrozenPeaShooter();
	~FrozenPeaShooter();
	void shoot(float, MovingObjectArr*)override;
	void draw(RenderWindow&)override;

};


