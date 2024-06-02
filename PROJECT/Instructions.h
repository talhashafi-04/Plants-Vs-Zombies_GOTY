#pragma once
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


using namespace std;
class Instructions :   public Screen
{
	bool BackToMainMenu;
	Texture texture;
	Sprite sprite;
public:
	Instructions();
	~Instructions();
	bool getBackToMainMenuI();
	void setBackToMainMenuI(bool);
	void draw(RenderWindow&);
	void update();
	void handleInput(RenderWindow&);
};
