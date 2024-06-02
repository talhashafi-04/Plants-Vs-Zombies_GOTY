#include "SunflowerFields.h"
#include "Lawn.h"
#include "Pea.h"
#include <cstdlib>
#include <ctime>


SunflowerFields::SunflowerFields(int level) : Level(level)
{
	this->levelNumber = level;


	string path = "Assets/Level/bg" + to_string(level) + ".png";
	if (!backgroundTexture.loadFromFile(path))
	{
		cout << "Error loading background image for Level " << level << endl;

	}
	backgroundSprite.setTexture(backgroundTexture);

	this->SpawnZombies();
	this->loadLawnMowers();
}


void SunflowerFields::draw(RenderWindow& window)
{
	drawBackround(window);
	shop.draw(window);
	lawn.drawPlants(window);
	lawn.drawZombie(window);
	lawn.drawMovingObjects(window);
	drawPause(window);

}

void SunflowerFields::update(float deltaTime)
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



void ::SunflowerFields::takeInput(RenderWindow& window)
{
	Level::takeInput(window);
}





void SunflowerFields::SpawnZombies() {
	srand(time(0));
	string Z_Arr[] = { "SimpleZombie", "FootballZombie", "FlyingZombie", "DancingZombie", "DolphinRiderZombie" };
	for (int i = 0; i < 20; i++) {
		lawn.addZombie(1000 + i * 200, rand() % 5 * 100 + 45, Z_Arr[rand() % 5]);
	}
}







