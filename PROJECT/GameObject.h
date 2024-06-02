#ifndef GameObject_h
#define GameObject_h

#pragma once


#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <string>
using namespace std;
#include "Point.h"

class GameObject
{
protected:
	sf::Texture texture;

	sf::Sprite sprite;
	static int count;
	Point position;
	bool isAlive;
	int frame;
	int maxFrame;
	string name; 
	


public:
	
	GameObject();
	virtual bool isExist();
	void setisAlive(bool isAlive);
	void setPosition(Point);
	Point getPosition();
	virtual void setPosition(float x, float y);
	static int getCount();
	string getName();
	Texture getTexture();

};




#endif



