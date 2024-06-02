#ifndef Lawn_h
#define Lawn_h
#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "PlantFactory.h"
#include "PlantArr.h"
#include "MovingObjectArr.h"
#include "Zombie.h"
#include "ZombieArr.h"
#include "ZombieFactory.h"

using namespace sf;

class ZombieFactory;

class Lawn
{
private:
	int GRID_START_X ;
	int GRID_START_Y ;
	int BoxHieght;
	int BoxWidth;
	bool available [5][9];
	
	bool isLost;

	
public:

	MovingObjectArr movingObjectsArray;
	ZombieArr zombieArray;
	ZombieFactory* zombieFactory;
	PlantArr plantsArray;
	PlantFactory* plantFactory;



public:
	Lawn(int);
	int getboxHieght();
	int getboxWidth();

	int getGRID_START_X();
	int getGRID_START_Y();
	Point getGridPosition(float x, float y);

	PlantArr& getPlantsArray();
	
	bool isBoxAvailable(int x, int y);
	void setBoxAvailable(int x, int y, bool value);
	
	void addPlant(float x, float y, string type);   //e/////////Might need to change the type to string
	void updatePlants(float, MovingObjectArr*);
	void drawPlants(RenderWindow& window);


	void addZombie(float x, float y, string type);
	void updateZombie(float);
	
	void drawZombie(RenderWindow& window);


	void drawMovingObjects(RenderWindow& window);
	void updateMovingObjects(float);

	void selectSun(float x, float y); //Select Sun from screen

	void removeDead();
	bool removePlant(float x, float y);	
	bool waterPlant(float x, float y);

	void collisionBullet_Zombie();
	void collisionPlant_Zombie();


	bool checkWin();
	bool checkLost();
	~Lawn();


};


#endif // !Lawn_h






