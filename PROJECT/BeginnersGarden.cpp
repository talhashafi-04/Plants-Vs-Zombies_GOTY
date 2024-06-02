#include "BeginnersGarden.h"
#include "Lawn.h"
#include "Pea.h"


BeginnersGarden::BeginnersGarden(int level) : Level(level)
{
	this->levelNumber = level;
	

	string path = "Assets/Level/" + to_string(level) + ".png";
	if (!backgroundTexture.loadFromFile(path))
	{
		cout << "Error loading background image for Level " << level << endl;

	}
	backgroundSprite.setTexture(backgroundTexture);

	this->SpawnZombies();
	this->loadLawnMowers();
}




void BeginnersGarden::draw(RenderWindow& window)
{
	drawBackround(window);
	shop.draw(window);
	lawn.drawPlants(window);
	lawn.drawZombie(window);
	lawn.drawMovingObjects(window);
	drawPause(window);
	

}

void BeginnersGarden::update(float deltaTime)
{
	
		if (!isPaused)
		{

			lawn.updateMovingObjects(deltaTime);
			lawn.updatePlants(deltaTime, &(lawn.movingObjectsArray));
			lawn.updateZombie(deltaTime);
			generateSun(deltaTime);
			addSuntoShop();


			lawn.removeDead();

			lawn.collisionBullet_Zombie();
			lawn.collisionPlant_Zombie();
			checkLoose();
			checkWin();
		}
	

}
	
void BeginnersGarden::loadLawnMowers()
{
	Level::loadLawnMowers();
}



void ::BeginnersGarden::takeInput(RenderWindow& window)
{
	Level :: takeInput(window);
}

			


			


void BeginnersGarden::SpawnZombies() {

	srand(time(0));
	for (int i = 0; i < 10; i++) 
	{
		lawn.addZombie(1000+i*300, rand()%5 * 100 + 20 , "SimpleZombie");
	}
}








