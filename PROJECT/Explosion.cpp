#include "Explosion.h"



Explosion::Explosion(float radius) : ExplodingRadius(radius)
{
	type = "Explosion";
	name = "Explosion";
	texture.loadFromFile("Assets\\Explosion\\Explosion_1\\Explosion_1.png");

	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);
	sprite.setOrigin(170, 170);
	isAlive = true;
	damage = 0;
	ExplosionTimer = 0;
	totalExplosionTime = 10;

}

Explosion :: ~Explosion()
{
}

float Explosion::GetExplosionRadius()
{
	return ExplodingRadius;
}


void Explosion::move(float dt)
{
	ExplosionTimer += (dt*5);
	if (ExplosionTimer > totalExplosionTime)
	{
		isAlive = false;
	}

	
}


void Explosion::update(float deltaTime, float time)
{
	
}


void Explosion::draw(RenderWindow& window)
{
	texture.loadFromFile("Assets\\Explosion\\Explosion_1\\Explosion_" + to_string(((int)(ExplosionTimer * 10.0 / totalExplosionTime ))+1) + ".png");
	sprite.setTexture(texture);


	sprite.setPosition(position.x - 20, position.y);
	window.draw(sprite);
	


}