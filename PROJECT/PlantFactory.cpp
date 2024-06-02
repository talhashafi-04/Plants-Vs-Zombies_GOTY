#include "PlantFactory.h"


PlantFactory* PlantFactory::instance = nullptr;

PlantFactory* PlantFactory::getInstance()
{
	if (PlantFactory::instance == nullptr)
	{
		PlantFactory::instance = new PlantFactory();
	}
	return PlantFactory::instance;
}

PlantFactory::PlantFactory()
{

}

Plant* PlantFactory::createPlant(std::string plantName)
{
	if (plantName == "PeaShooter")
	{
		return new PeaShooter();
	}
	else if (plantName == "SunFlower")
	{
		return new SunFlower();
	}
	else if (plantName == "FrozenPeaShooter")
	{
		return new FrozenPeaShooter();
	}
	else if (plantName == "Repeater")
	{
		return new Repeater();
	}
	else if (plantName == "CherryBomb")
	{
		return new CherryBomb();
	}
	else if (plantName == "WallNut")
	{
		return new Wallnut();
	}
	else if (plantName == "Cactus")
	{
		return new Cactus() ;
	}
	else
	{
		return nullptr;
	}

	

}

PlantFactory::~PlantFactory()
{
	delete PlantFactory::instance;
}
