#pragma once
#include "MovingObject.h"


class LawnMower : public MovingObject
{


	bool isMoving = false;
	Texture movingTexture;
	Sprite movingSprite;
	float animationTimer = 0;

public :

	LawnMower();
	void update(float, float)override;

	void draw(RenderWindow&)override;
	void move(float)override;
	void setIsMoving (bool);
	bool getIsMoving();


	~LawnMower();

};
