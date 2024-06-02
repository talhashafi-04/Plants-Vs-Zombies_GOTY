#pragma 
#ifndef BeginnersGarden_h
#define BeginnersGarden_h
#include "Level.h"
#include "LawnMower.h"
class BeginnersGarden : public Level
{
	
public:
	BeginnersGarden(int level);
	void draw(RenderWindow& window);
	void takeInput(RenderWindow& windowzz);
	void update(float)override;
	void SpawnZombies();
	void loadLawnMowers()override;

	

};


#endif // !BeginnersGarden_h