#pragma once
#ifndef  Header_h
#define  Header_h

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;


void draw_Box(RenderWindow& window , Texture & texture , Sprite & sprite )
{
	RectangleShape rectangle(Vector2f(texture.getSize().x, texture.getSize().y));
	rectangle.setFillColor(Color::Transparent);
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(Color::	Red);
	rectangle.setPosition(sprite.getPosition().x , sprite.getPosition().y);
	window.draw(rectangle);
}

#endif // ! Header_h
