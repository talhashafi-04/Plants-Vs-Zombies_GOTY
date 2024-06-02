#pragma once
#ifndef Card_h
#define	Card_h
#include <iostream>
#include <string>
#include "Point.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Card
{
private:
	
	Point position;
	string name;
	int cost;
	int coolDown;
	bool isUnlocked;
	Texture texture;
	Sprite sprite;

public:
	
	
	Card(string name, int cost, int coolDown , Point P , bool isUnlocked );
	//bool isAvailable();
	void draw(RenderWindow& window, string slected);
	
	int getCost();
	int getCoolDown();
	string getName();
	//~Card();

};


#endif // !Card_h


