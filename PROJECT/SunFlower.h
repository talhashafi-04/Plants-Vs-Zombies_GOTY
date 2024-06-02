#pragma once
#include "Plant.h" 

class SunFlower : public Plant
{
	float sunTimer;
	int sunInterval;

	public:
	SunFlower();
	void action(float , MovingObjectArr* )override; 
	void generateSun(MovingObjectArr*);
	void draw(RenderWindow & )override;
	~SunFlower();
};
