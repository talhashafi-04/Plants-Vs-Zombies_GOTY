#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
using namespace sf;
#include <string>
#include <iostream>
using namespace std;

class Intro
{
	//adding sound
	SoundBuffer buffer;
	Sound sound;

	Texture texture;
	Sprite sprite;
	Clock clock;
	int frame = 1;
	bool has_ended = false;
	public:
	Intro();
	~Intro();
	void draw(RenderWindow & );
	void update();
	bool handleInput(RenderWindow & );
};
