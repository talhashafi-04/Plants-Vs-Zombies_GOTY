#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Screen
{
public:
	Screen();
	~Screen();
	virtual void draw(RenderWindow&) = 0;
	virtual void update() = 0;
	virtual void handleInput(RenderWindow&) = 0;
};

