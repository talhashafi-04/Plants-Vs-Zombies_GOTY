#pragma once
#include "Plant.h"
class Wallnut : public Plant
{
	float dx;
	bool isMoving;
	float rotate;
	int maxRotate;

	Point currentposition;
public:
	Wallnut();
	~Wallnut();

	void draw(RenderWindow& ) override;
	void action(float, MovingObjectArr*)override;
	void setPosition(float, float)override;
	float frameTimer = 0;
	int maxFrameTime = 4;
};
