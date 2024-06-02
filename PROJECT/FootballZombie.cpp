#include "FootballZombie.h"

FootballZombie::FootballZombie() {

	name = "FootballZombie";
	magicNumber = rand() %  6 ;
	probablity = 20  ; 
	this->totalIntervals = 12;
	this->timer = 0;
	dx = -1 ;
	dy = 0;
	is_Moving_vertical = false;
	setHealth(8);
	setDamage(4);
	if (!texture.loadFromFile("Assets\\Zombies\\FootballZombie\\footbll (1).png"))
	{
		cout << "Error loading Zombie.png" << endl;

	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(0.8, 0.8);
}

void FootballZombie::animate(string) {
	string path = "Assets\\Zombies\\FootballZombie\\footbll (" + to_string((int)((timer * 29.0 / 12))+1) + ").png";
	if (!is_Moving_vertical)
	{
		texture.loadFromFile(path);
		sprite.setTexture(texture);
	}

}
void FootballZombie::action(float x)
{
	Zombie::action(x/2);
	x *= 5;

	//MOVE

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

	move();
	animate(state);


}

void FootballZombie::move() {
	
	
	if (this->is_Moving_vertical)
	{

		if (dy < 0)
		{
			if (position.y < destination_y)
			{
				dy = 0;
				is_Moving_vertical = false;
				dx = -0.4;
			}
		}
		else if (dy  > 0 )
		{
			if (position.y > destination_y)
			{
				dy = 0;
				is_Moving_vertical = false;
				dx = -0.4;
			}

		}
		else
		{
			is_Moving_vertical = false;
		}
	}
	else
	{
		if (rand() % 100 <= probablity )
		{
			if (position.y > 150 && position.y < 450)
			{
				if (rand() % 2)
				{
					dy = 0.5;
					destination_y = position.y + 100;
				}
				else
				{
					dy = -0.5;
					destination_y = position.y - 100;
				}
			}
			else if (position.y <= 150)
			{
				dy = 0.5;
				destination_y = position.y + 100;

			}
			else
			{
				dy = -0.5;
				destination_y = position.y - 100;
			}
			
			dx = 0;
			is_Moving_vertical = true;
		}
		else
		{
			dx = -0.4;
			dy = 0;
			is_Moving_vertical = false;
		}

	}
}

void FootballZombie::draw(RenderWindow& window) {
	Zombie::draw(window);
}



FootballZombie:: ~FootballZombie() {

}