#pragma once
#include <iostream>
using namespace std;
#include "Zombie.h"
#include "Lawn.h"
class DolphinRiderZombie : public Zombie
{
	bool specialAbility;
public:

	DolphinRiderZombie();

	void action(float) override;
	void specialAction();
	void move();
	void draw(RenderWindow& window);
	void animate(string) override ;
	~DolphinRiderZombie();
};

