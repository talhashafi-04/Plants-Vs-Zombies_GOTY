#pragma once
#include "Plant.h"
class Cactus : public Plant
{
	public:
	Cactus();
	void action(float deltaTime, MovingObjectArr*) override;
	void draw(RenderWindow&) override;
	void setPosition(float x, float y)override;
	~Cactus();
};


