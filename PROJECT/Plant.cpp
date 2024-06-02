#include "Plant.h"


int Plant::getCost()
{
	return cost;
}

void Plant::setCost(int cost)
{
	this->cost = cost;
}

Plant::~Plant()
{
}

void Plant::draw(RenderWindow& window)
{
	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);



	{
		RectangleShape rectangle(Vector2f(texture.getSize().x, texture.getSize().y));
		rectangle.setFillColor(Color::Transparent);
		rectangle.setOutlineThickness(3);
		rectangle.setOutlineColor(Color::Red);
		rectangle.setPosition(sprite.getPosition().x, sprite.getPosition().y);
		window.draw(rectangle);
	}



	window.draw(sprite);
}
