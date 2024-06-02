#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Zombie.h"

using namespace std;
class SimpleZombie :public Zombie{

	
public:
	SimpleZombie();

	void action(float) override;
	void animate(string) override ;
	void draw(RenderWindow& window) override;

	~SimpleZombie();

};

