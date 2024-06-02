#pragma once
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "FlyingZombie.h"
#include "DolphinRiderZombie.h"


#include <iostream>
#include <string>

class ZombieFactory {
private:
	ZombieFactory(); 
	static ZombieFactory* instance; 

public:
	static ZombieFactory* getInstance(); 
	Zombie* createZombie(std::string zombieName);
	~ZombieFactory(); 
};
