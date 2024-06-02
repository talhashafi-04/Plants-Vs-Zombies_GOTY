#include "Intro.h"




Intro::Intro()
{
	texture.loadFromFile("Assets/Intro/ezgif-frame-001.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);


	buffer.loadFromFile("Assets/Sounds/intro.ogg");
	sound.setBuffer(buffer);
	sound.play();
}


void Intro::draw(RenderWindow& window)
{
	string f = to_string(frame);
	if (frame < 10)
		f = "00" + f;
	else if (frame < 100)
		f = "0" + f;
	else
		f = f;

	texture.loadFromFile("Assets/Intro/ezgif-frame-" + f + ".png");
	window.draw(sprite);
}

void Intro::update()
{
	if (clock.getElapsedTime().asMilliseconds() < 40)
	{
		return;
	}
	clock.restart();



	if (frame <= 170)
		frame++;

	else
	{
		has_ended = true;
	}


}


Intro :: ~Intro()
{
}

bool Intro::handleInput(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return true;
		}
		/*if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Space && has_ended)
			{
				return true;
			}
			else if (event.key.code == Keyboard::Escape)
			{
				return true;
			}

		}*/

		if (event.type == Event::MouseButtonPressed)
		{
			return true;
		}

	}
	return false;
}