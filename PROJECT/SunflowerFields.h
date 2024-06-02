#pragma 
#ifndef SunflowerFields_h	
#define SunflowerFields_h	
#include "Level.h"
class SunflowerFields :  public Level
{
public:
	SunflowerFields(int level);
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