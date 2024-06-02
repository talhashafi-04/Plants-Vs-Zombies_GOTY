#include "ShootingPlant.h"



void ShootingPlant::action(float deltaTime , MovingObjectArr* movingObjectArr )
{
	shoot(deltaTime, movingObjectArr);
}

ShootingPlant::~ShootingPlant()
{
}