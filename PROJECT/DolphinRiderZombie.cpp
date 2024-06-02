#include "DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie() {
	specialAbility = true;
	dx = -1;
	dy = 0;
	setHealth(6);
	setDamage(4);
	if (!texture.loadFromFile("Assets\\Zombies\\DolphinRiderZombie.png"))
	{
		cout << "Error loading Zombie.png" << endl;

	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(0.9, 0.9);
	sprite.setOrigin(-50, 0);
}

void DolphinRiderZombie::animate(string state) {


	string path;

	if (state == "Moving")
	{
		path = "Assets\\Zombies\\DolphinRiderZombie.png";
	}



}


void DolphinRiderZombie::action(float x) {
	timer += (10 * x);
	if (timer > totalIntervals)
	{
		timer = 0;
	}

	move();
	animate(state);
}

void DolphinRiderZombie::specialAction() {
	/*if (specialAbility ) {
		for (int i = 0; i < plantsArray.getSize(); i++) {
			if (plantsArray[i].getPosition().x > getPosition().x && plantsArray[i].getPosition().x < getPosition().x + 70 && plantArray[i].getPosition().y == getPosition().y) {
				dy = -0.1;
			}
		}
		
	}*/
}

void DolphinRiderZombie::move() {
	if (state == "Moving")
	{
		this->position.x += dx;
		this->position.y += dy;
	}

}

void DolphinRiderZombie::draw(RenderWindow& window) {
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}



DolphinRiderZombie:: ~DolphinRiderZombie() {

}