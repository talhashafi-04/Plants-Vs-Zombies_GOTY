#pragma once
#include "Plant.h"
class CherryBomb : public Plant
{
	bool has_exploded = false;
	float exploding_radius;
	int time_to_explode;
	float time_exploding = 0;
	bool is_exploding = false;
public:
	CherryBomb();
	~CherryBomb();
	void draw(RenderWindow&)override;
	void action(float, MovingObjectArr* )override;
	bool isExist() override;
	
};

