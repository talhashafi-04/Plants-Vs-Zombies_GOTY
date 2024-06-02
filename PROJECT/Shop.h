
#pragma once
#include <SFML/Graphics.hpp>
#include "Card.h"
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class Shop
{
	Card* listOfCards [9] ;
	Card* selectedPlant;

	int sun;
	int level;
	

public:
	Shop(int level);

	void draw(RenderWindow & window);
	//void update();
	void selectPlant(string plantName);
	void selectPlant(float , float );
	void setSun(int sun);
	int  getSun();
	bool isPurchasable();
	void purchase();
	string getSelectedPlant();
	void incrementSun(int);


};


