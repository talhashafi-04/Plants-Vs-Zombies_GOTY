#include "FlyingZombie.h"

FlyingZombie::FlyingZombie() {
	name = "FlyingZombie";
	dx = -1;
	dy = 0;
	setHealth(4);
	setDamage(2);
	if (!texture.loadFromFile("Assets\\Zombies\\Ballon Zombie\\ballon zombie (1).png"))
	{
		cout << "Error loading Zombie.png" << endl;

	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	timer = 0;
	totalIntervals = 42;
}

void FlyingZombie::setPosition (float x, float y) {
	
	position.x = x ;
	position.y = y - 80;
}

void FlyingZombie::action(float x) {
	timer += (10*x);
	if (timer > totalIntervals)
	{
		timer = 0;
	}

	move();
	animate(state);
}

void FlyingZombie::animate(string state ) {
	
	string path;

	if (state == "Moving")
	{
		 path = "Assets\\Zombies\\Ballon Zombie\\ballon zombie (" + to_string((int)((timer * 41.0 / totalIntervals )) + 1) + ").png";
	}


	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

void FlyingZombie::move() {
	this->position.x += dx;
	this->position.y += dy;

	/*if (position.x < 0) {
		dx = 0.2;
	}
	if (position.x > 1000) {
		dx = -0.2;
	}*/

	if (position.y < 0) {
		dy = 0.1;
	}
	if (position.y > 600) {
		dy = -0.1;
	}
}

void FlyingZombie::draw(RenderWindow& window) {
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}



FlyingZombie:: ~FlyingZombie() {

}