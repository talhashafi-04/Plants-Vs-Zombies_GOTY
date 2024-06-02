#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Zombie.h"
class FootballZombie :public Zombie {

	float destination_y;
	int probablity;
	int magicNumber;
public:
	bool is_Moving_vertical = false;
	FootballZombie();
	void move();
	void action(float) override;
	void animate(string)override;
	void draw(RenderWindow & ) override;

	~FootballZombie();

};

