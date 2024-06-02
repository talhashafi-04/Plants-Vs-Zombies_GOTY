#ifndef PlantFactory_h
#define PlantFactory_h
#pragma once
#include "Plant.h"
#include "PeaShooter.h"
#include "SunFlower.h"
#include "FrozenPeaShooter.h"
#include "Repeater.h"
#include "CherryBomb.h"
#include "Wallnut.h"
#include "Cactus.h"
//#include "TorchWood.h"

#include <iostream>
#include <string>

class PlantFactory
{
	PlantFactory();
	static PlantFactory* instance;
public:
	static PlantFactory* getInstance();
	Plant* createPlant(std::string plantName);
	~PlantFactory();
};



#endif // !PlantFactory_h