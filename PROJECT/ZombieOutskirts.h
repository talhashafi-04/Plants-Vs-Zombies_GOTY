#pragma 
#ifndef ZombieOutskirts_h
#define ZombieOutskirts_h
#include "Level.h"
class ZombieOutskirts : public Level
{
public:
	ZombieOutskirts(int level);
	void draw(RenderWindow& window);
	void takeInput(RenderWindow& windowzz);
	void update(float)override;
	void SpawnZombies();

	//void checkCollisions();
	//void checkWin();
	//void checkLose();
	//void takeInput(RenderWindow& window);

};


#endif // !BeginnersGarden_h