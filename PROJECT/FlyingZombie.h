#pragma once
#include <iostream>
using namespace std;
#include "Zombie.h"
class FlyingZombie :   public Zombie
{
public:
	FlyingZombie();

	void action(float) override;
	void move();
	void draw(RenderWindow& window)override;
	void animate(string) override;
	void setPosition(float x, float y) override;
	~FlyingZombie();
};


