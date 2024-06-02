#pragma once
#include "Bullet.h"
class FrozenPea : public Bullet
{
public:
	FrozenPea();
	void move(float)override;
};

