#pragma once
#include "Bullet.h"



class Explosion : public Bullet
{
	
	float ExplosionTimer;
	int  totalExplosionTime;
	float ExplodingRadius;
public:
	Explosion(float);
	
	~Explosion();
	void update(float , float )override ;
	void move(float)override;
	void draw(RenderWindow &) override;
	float GetExplosionRadius();


};



