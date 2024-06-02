#ifndef Character_h
#define Character_h
#pragma once
#include "GameObject.h"
#include <string.h>

class Character : public GameObject
{
protected:
	int health;
	int damage;
public:
	String getName();
	void setName(String name);
	int getHealth();
	void setHealth(int health);
	int getDamage();
	void setDamage(int damage);
	bool isExist() override;
	
};



#endif // !Character_h


