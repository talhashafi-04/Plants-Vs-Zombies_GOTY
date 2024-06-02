#ifndef MovingObject_h
#define MovingObject_h

#pragma once
#include "GameObject.h"

class MovingObject :  public GameObject
{
protected :

	float dx;
	float dy;
	string type;
	
public :
	virtual void update (float,float) = 0;
	virtual void move(float) = 0;
	virtual void draw(RenderWindow & ) = 0;
	string getType();
	
	void setVelocity(float dx, float dy);
	float getdx();
	float getdy();




};

#endif // !MovingObject_h