#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Zombie.h"
#include "PlantArr.h"
#include "Lawn.h"


class Lawn; 
class PlantArr;
class GroundZombie;

class DancingZombie :public Zombie {

	static int  countSpecialAbility;
	static float specialAbilityTimer ;
	int totalSpecialAbilityTime = 10 ;
	Lawn* lawn;
public:
	DancingZombie();

	void getLawnRef(Lawn* lawn);
	void action(float) override;
	void move();
	void draw(RenderWindow& window);
	void animate(string);
	bool specialAction();

	~DancingZombie();

};




