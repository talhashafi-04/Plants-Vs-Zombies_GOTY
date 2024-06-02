#include "ZombieOutskirts.h"
#include "Lawn.h"
#include "Pea.h"
#include <cstdlib>
#include <ctime>


ZombieOutskirts::ZombieOutskirts(int level) : Level(level)
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


void ZombieOutskirts::draw(RenderWindow& window)
{
	drawBackround(window);
	shop.draw(window);
	lawn.drawZombie(window);
	lawn.drawPlants(window);

	lawn.drawMovingObjects(window);
	drawPause(window);

}

void ZombieOutskirts::update(float deltaTime)
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



void ::ZombieOutskirts::takeInput(RenderWindow& window)
{
	Level ::  takeInput(window);
}





void ZombieOutskirts::SpawnZombies() {
	srand(time(0));
	string Z_Arr[] = { "SimpleZombie", "FootballZombie", "FlyingZombie", "DancingZombie", "DolphinRiderZombie"};
	for (int i = 0; i < 15; i++) {
		lawn.addZombie(1000 + i * 300, rand() % 5 * 100 + 20  , Z_Arr[rand () % 5]);
		
	}
}







