#ifndef Bullet_h
#define Bullet_h

#pragma once
#include "MovingObject.h"


class Bullet : public MovingObject 
{
protected:
	
	float damage;
	
public :

	Bullet();		
	float getDamage();
	void draw(RenderWindow& ) override ;
	void move(float) override;
	void update(float, float)override;


	bool isExist() override;

};


#endif // !Bullet_h