#include "SimpleZombie.h"
#include "Header.h"
SimpleZombie::SimpleZombie() {
	
	totalIntervals = 12 ;
	timer = 0;
	dx = -1 ;
	dy = 0;

	setHealth(4);
	setDamage(2);

	if (!texture.loadFromFile("Assets\\Zombies\\NormalZombie\\Moving\\Zombie_0.png"))
	{
		cout << "Error loading Zombie.png" << endl;

	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}



void SimpleZombie:: action(float x) {
	
	Zombie ::action(x);
	x *= 5;

	
	//MOVE

	if (isFrozen)
	{

		this->position.x += dx / 3.0;
		this->position.y += dy / 3.0 ;
	}
	else
	{
		if (state == "Moving")
		{
			this->position.x += dx;
			this->position.y += dy;
		}

	}


	
	
	animate(state);
}


void SimpleZombie::animate(string state)
{

	string path;
		if (state == "Moving" && health > 2 )
			path = "Assets\\Zombies\\NormalZombie\\Moving\\Zombie_" + to_string((int)((timer * 13.0 / 12))) + ".png";
		else if (state == "Moving" && health <= 2)
			path = "Assets\\Zombies\\NormalZombie\\ZombieLostHead\\ZombieLostHead_" + to_string((int)((timer * 18.0 / 12))) + ".png";
		else if (state == "Attacking" && health > 2)
			path = "Assets\\Zombies\\NormalZombie\\Attacking\\ZombieAttack_"+ to_string((int)((timer * 21.0 / 12))) +".png";
		else if (state == "Attacking" && health <= 2)
			path = "Assets\\Zombies\\NormalZombie\\ZombieLostHeadAttack\\ZombieLostHeadAttack_" + to_string((int)((timer * 11.0 / 12))) + ".png";

		else if (state == "Burning" )
			path = "Assets\\Zombies\\NormalZombie\\BoomDie\\BoomDie_" + to_string((int)((burntTimer * 13.0 / 10))) + ".png";

		if (!isWithoutHead && health == 2 )
		{
			isWithoutHead = true;
			LostHeadPosition = position;
			LostHeadPosition.y -= 40;
			LostHeadPosition.x += 50 ;
			headTimer = 0; 

		}

		if (isWithoutHead)
		{
			string path = "Assets\\Zombies\\NormalZombie\\ZombieHead\\ZombieHead_" + to_string((int)(( headTimer * 12.0 / 20 ))) + ".png"; 
			headtexture.loadFromFile(path);

		}


	if (!texture.loadFromFile(path))
	{
		cout << "Error loading Zombie.png" << endl;

	}

	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);
}


void SimpleZombie::draw(sf::RenderWindow& window) {

	Zombie :: draw(window);

	if (isWithoutHead)
	{
		headSprite.setTexture(headtexture);
		headSprite.setPosition(LostHeadPosition.x, LostHeadPosition.y);
		window.draw(headSprite);
	}
	
}
SimpleZombie:: ~SimpleZombie() {

}



