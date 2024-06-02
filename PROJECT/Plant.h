#pragma once 
#ifndef PLANT_H
#define PLANT_H
#include "Character.h"
#include "MovingObjectArr.h"
class Plant : public Character
{
protected:
	int cost;
public:

	int getCost();
	void setCost(int cost);
	virtual void draw(RenderWindow&) ;
	virtual void action(float, MovingObjectArr*) = 0 ;
	virtual ~Plant()  ;
};

#endif