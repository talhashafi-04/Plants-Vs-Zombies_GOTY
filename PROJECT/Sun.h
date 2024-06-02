#pragma once
#include "MovingObject.h"
class Sun : public MovingObject
{
	Point FallingPosition;
	bool isFalling;
	bool isSelecting;
	int sunInterval = 24 ;
	float sunTimer = 0;
public:

	Sun();
	~Sun();
	void update(float , float )override;
	void draw(RenderWindow & )override ;
	void move(float)override;
	void setFallingPosition(float, float);
	void setSelecting();

	
};

