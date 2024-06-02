
#include "Lawn.h"
#include "LawnMower.h"
#include <cmath>
Lawn::Lawn(int level)
{
	plantFactory = PlantFactory::getInstance();
	zombieFactory = ZombieFactory::getInstance();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			available[i][j] = true;
		}
	}

	GRID_START_X = 255;
	GRID_START_Y = 75;
	BoxWidth = 80 ;
	BoxHieght = 100 ;

}



void Lawn::selectSun(float x, float y)
{
	for (int i = 0; i < movingObjectsArray.getSize(); i++)
	{

		if (movingObjectsArray.at(i) != nullptr)
		{
			if (movingObjectsArray.at(i)->getName() == "Sun")
				movingObjectsArray.at(i)->update(x, y);
		}

	}
}


void Lawn::updateZombie(float deltaTime) {

	for (int i = 0; i < zombieArray.getSize(); i++) 
	{
		if (zombieArray.at(i) != nullptr) 
		{
			zombieArray.at(i)->action(deltaTime);
			
		}
	}
}

void Lawn::drawMovingObjects(RenderWindow& window)
{
	for (int i = 0; i < movingObjectsArray.getSize(); i++)
	{
		
		if (movingObjectsArray.at(i) != nullptr)
		{
			movingObjectsArray.at(i)->draw(window);
		}
	}
}


void Lawn::addZombie(float x, float y, string type) {

	Zombie* zombie = zombieFactory->createZombie(type);

	
	if(zombie != NULL )
	{
		zombie->setPosition(x, y);
		if (zombie->getName() == "DancingZombie")
		{
			((DancingZombie*)zombie)->getLawnRef(this);
		}
		
		zombieArray.push_back(zombie);
	}
}


void Lawn::drawZombie(RenderWindow& window)
{
	for (int i = 0; i < zombieArray.getSize(); i++)
	{
		if (zombieArray.at(i) != nullptr)
		zombieArray.at(i)->draw(window);
	}
}
void Lawn::addPlant(float x, float y, string type )   ///////////Might need to change the type to string
{
	Plant* plant = 	plantFactory->createPlant(type);
	if(plant != nullptr)
	{
		plant->setPosition(x, y);
		plantsArray.push_back(plant);
	}
}

void Lawn::drawPlants(RenderWindow& window)
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		if (plantsArray.at(i) != nullptr)
		plantsArray.at(i)->draw(window);
	}
}

Point Lawn::getGridPosition(float x, float y) {
	Point p;
	float relativeX = x - GRID_START_X;
	float relativeY = y - GRID_START_Y;

	p.x = (int)((relativeX / BoxWidth));
	p.y = (int)((relativeY / BoxHieght));
	if (relativeX < 0 || relativeY < 0)
	{
		p.x = -1;
		p.y = -1;
		return p;
	}
	p.x = (int)((relativeX / BoxWidth));
	p.y = (int)((relativeY / BoxHieght));

	return p;
}

int Lawn::getboxHieght()
{
	return BoxHieght;
}

int Lawn::getboxWidth()
{
	return BoxWidth;
}



int Lawn::getGRID_START_Y()
{
	return GRID_START_Y;
}

int Lawn::getGRID_START_X()
{
	return GRID_START_X;
}

void Lawn ::setBoxAvailable(int x, int y, bool value)
{
	available[y][x] = value;
}

PlantArr& Lawn::getPlantsArray()
{
	return plantsArray;
}


bool Lawn::isBoxAvailable(int x, int y)
{
	return available[y][x];
}


void Lawn::updateMovingObjects(float deltaTime)
{
	for (int i = 0; i < movingObjectsArray.getSize(); i++)
		if(movingObjectsArray.at(i) != nullptr)
		movingObjectsArray.at(i)->move(deltaTime);
}

void Lawn::updatePlants (float time, MovingObjectArr* movingObjectsArray)
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		if(plantsArray.at(i) != nullptr)
		plantsArray.at(i)->action(time, movingObjectsArray);
	}
}


//
//void Lawn::drawMovingObjects(RenderWindow& window)
//{
//	for (int i = 0; i < movingObjectsArray.getSize(); i++)
//	{
//		movingObjectsArray.at(i)->draw(window);
//	}
//}
//




void Lawn::removeDead()
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		if(plantsArray.at(i) != nullptr)
		if (plantsArray.at(i)->getHealth() <= 0 || plantsArray.at(i)->isExist() == false)
		{
			Point p = plantsArray.at(i)->getPosition();
			Point P = getGridPosition(p.x, p.y);
			setBoxAvailable(P.x, P.y, true);

			plantsArray.erase(i);
			i--;
		}
	}
	for (int i = 0; i < zombieArray.getSize(); i++)
	{
		if(zombieArray.at(i) != nullptr)
		if (zombieArray.at(i)->getHealth() <= 0 || zombieArray.at(i)->isExist() == false)
		{
			if (zombieArray.at(i)->getHealth() <= 0 )
			{
				Zombie :: killCount++;
			}
			zombieArray.erase(i);
			i--;
		}
	}
	for (int i = 0; i < movingObjectsArray.getSize(); i++)
	{
		if(movingObjectsArray.at(i) != nullptr)
		if (movingObjectsArray.at(i)->isExist() == false)
		{
			movingObjectsArray.erase(i);
			i--;
		}
	}
}





bool Lawn::checkLost()
{
	for (int i = 0; i < zombieArray.getSize(); i++)
	{
		if (zombieArray.at(i) != nullptr)
		{
			if (zombieArray.at(i)->getPosition().x  <= 80)
			{
				zombieArray.erase(i);
				return true;
			}
		}
	}
	return false;
}

bool Lawn::checkWin()
{

	for (int i = 0; i < zombieArray.getSize(); i++)
	{
		if (zombieArray.at(i) != nullptr )
		{
			return false;
		}
	}
	
	return true ;
}




void Lawn::collisionBullet_Zombie()
{
	for (int i = 0; i < movingObjectsArray.getSize(); i++)
	{
		for (int j = 0; j < zombieArray.getSize(); j++)
		{
			if (movingObjectsArray.at(i) != nullptr && zombieArray.at(j) != nullptr)
			{
				if (zombieArray.at(j)->getName() == "FlyingZombie")
				{
					continue;
				}

				Point M = movingObjectsArray.at(i)->getPosition();
				Point Z = zombieArray.at(j)->getPosition();

				if (movingObjectsArray.at(i)->getType() == "Bullet")
				{
					if (M.x >= Z.x + 50 && M.x <= Z.x + 150 && M.y >= Z.y && M.y <= Z.y + 110)
					{
						if (movingObjectsArray.at(i)->getName() == "Pea")
							zombieArray.at(j)->setHealth(zombieArray.at(j)->getHealth() - ((Bullet*)movingObjectsArray.at(i))->getDamage());
						else if (movingObjectsArray.at(i)->getName() == "FrozenPea")
						{
							zombieArray.at(j)->setHealth(zombieArray.at(j)->getHealth() - ((Bullet*)movingObjectsArray.at(i))->getDamage());
							zombieArray.at(j)->setIsFrozen(true);
						}
						movingObjectsArray.erase(i);
						i--;
					}
				}
				else if (movingObjectsArray.at(i)->getType() == "LawnMower")
				{
					if (M.x >= Z.x - 20 && M.x <= Z.x + 20 && M.y >= Z.y + 25 && M.y <= Z.y + 100)
					{
						cout << "LawnMower" << endl;
						if (!((LawnMower*)movingObjectsArray.at(i))->getIsMoving())
						{
							((LawnMower*)movingObjectsArray.at(i))->setIsMoving(true);
						}
						zombieArray.at(j)->setHealth(0);
					}
				}
				else if (movingObjectsArray.at(i)->getType() == "Explosion")
				{
					//Point Z(zombieArray.at(j)->getPosition().x + ( zombieArray.at(j)->getTexture().getSize().x /2 ), zombieArray.at(j)->getPosition().y + (zombieArray.at(j)->getTexture().getSize().y / 2));
					//Point M(movingObjectsArray.at(i)->getPosition().x + ((movingObjectsArray.at(i)->getTexture().getSize().x) / 2.0), movingObjectsArray.at(i)->getPosition().y + ((movingObjectsArray.at(i)->getTexture().getSize().y) / 2.0 ));

					float radius  = sqrt(pow(M.x - Z.x, 2) + pow(M.y - Z.y, 2));
					if (radius < 200)
					{
						zombieArray.at(j)->setBurnt();
					}	
				}
			}
		}
	}
}


void Lawn::collisionPlant_Zombie()
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		for (int j = 0; j < zombieArray.getSize(); j++)
		{
			if(plantsArray.at(i) != nullptr && zombieArray.at(j) != nullptr)
			{
				if (plantsArray.at(i)->isExist() && zombieArray.at(j)->isExist())
				{
					if (zombieArray.at(j)->getName() == "FlyingZombie" && plantsArray.at(i)->getName() != "Cactus")
					{
						continue;
					}

					Point P = plantsArray.at(i)->getPosition();
					Point Z = zombieArray.at(j)->getPosition();
					if (P.x >= Z.x + 10  && P.x <= Z.x + 160 && P.y >= Z.y-10 && P.y <= Z.y + 150)
					{
						if (zombieArray.at(j)->getName() == "FlyingZombie" && plantsArray.at(i)->getName() == "Cactus")
						{
							zombieArray.at(j)->setHealth(0);
							continue;
						}
						zombieArray.at(j)->setState("Attacking");
						plantsArray.at(i)->setHealth(plantsArray.at(i)->getHealth() - zombieArray.at(j)->getDamage());

						if (plantsArray.at(i)->getHealth() <= 0)
						{
							plantsArray.erase(i);
							i--;
							zombieArray.at(j)->setState("Moving");
						}
					}
					else
					{
						zombieArray.at(j)->setState("Moving");
					}

					
				}
			}
		}
	}
}

Lawn :: ~Lawn()
{
	
}	






bool Lawn::removePlant(float x, float y)
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		int  x_ = getGridPosition(plantsArray.at(i)->getPosition().x, plantsArray.at(i)->getPosition().y).x;
		int  y_ = getGridPosition(plantsArray.at(i)->getPosition().x, plantsArray.at(i)->getPosition().y).y;
		

		if (x_ == x && y_ == y)
		{
			cout << "Removing Plant" << endl;
			plantsArray.erase(i);
			setBoxAvailable(x, y, true);
			return 1;
		
		}
	}
	return 0;
}


bool Lawn::waterPlant(float x, float y)
{
	for (int i = 0; i < plantsArray.getSize(); i++)
	{
		int  x_ = getGridPosition(plantsArray.at(i)->getPosition().x, plantsArray.at(i)->getPosition().y).x;
		int  y_ = getGridPosition(plantsArray.at(i)->getPosition().x, plantsArray.at(i)->getPosition().y).y;


		if (x_ == x && y_ == y)
		{
			cout << "Watering Plant" << endl;
			plantsArray.at(i)->setHealth(plantsArray.at(i)->getHealth() + 1000);
			return 1;
		}
	}
	return 0;
}