#include "DancingZombie.h"

float DancingZombie::specialAbilityTimer = 0;
int DancingZombie::countSpecialAbility = 0;

DancingZombie::DancingZombie() {

	name = "DancingZombie";
	state = "Moving";
	dx = -1.2;
	dy = -1.2;
	setHealth(4);
	setDamage(3);
	if (!texture.loadFromFile("Assets\\Zombies\\dancer zombie\\dancer (1).png"))
	{
		cout << "Error loading Zombie.png" << endl;

	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(0.8, 0.8);
	timer = 0;
	totalIntervals = 14;
}

void DancingZombie::animate(string state ) {
	string path;
	if(state == "Moving")
	{ 
		path = "Assets\\Zombies\\dancer zombie\\dancer (" + to_string((int)((timer * 13.0 / 14 )) + 1) + ").png";
	}
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

void DancingZombie::action(float x) 
{
	timer += (10 * x);
	if (timer > totalFrozenTime )
	{
		timer = 0;
	}



	if (countSpecialAbility < 1)
	{
		specialAbilityTimer += 1;
		if (specialAbilityTimer > totalSpecialAbilityTime)
		{
			if (specialAction()==true) {
				specialAbilityTimer = 0;
				countSpecialAbility++;
			}
			

		}
	}
	animate(state);
	move();
}

void DancingZombie::move() {
	if (isFrozen)
	{
		this->position.x += dx / 2.0;
		this->position.y += dy / 2.0;
	}
	else
	{
		if (state == "Moving")
		{
			this->position.x += dx;
			this->position.y += dy;
		}
	}
	
	if (position.y < 0) {
		dy = +1.2;
	}
	if (position.y > 450) {
		dy = -1.2;
	}
	
	
}

void DancingZombie::draw(RenderWindow& window) {
	Zombie::draw(window);
}

bool DancingZombie::specialAction() {
	bool isPlant = false;
	if (position.x < 720)
	{
		for (int i = 0; i < lawn->getPlantsArray().getSize(); i++)
		{
			Point plantPos = lawn->getPlantsArray().at(i)->getPosition();
			if (plantPos.y/100 == position.y/100)
			{
				isPlant = true;
				return !isPlant;
			}
		}
		cout << position.x << " " << position.y << endl;
		lawn->addZombie(position.x-200,position.y, "DancingZombie");

		return !isPlant;
	}
}

DancingZombie:: ~DancingZombie() {

}


void DancingZombie:: getLawnRef(Lawn* lawn) {
	this->lawn = lawn;
}