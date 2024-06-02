#pragma once
#include "Character.h"
#include <string>

class Zombie : public Character
{
public :
	static int killCount;
protected:
	float dx;
	float dy;
	std::string state = "";
	bool isWithoutHead = false;
	int totalIntervals;
	float timer  ;
	bool isMoving;

	Point LostHeadPosition;
	Texture headtexture;
	Sprite  headSprite;
	float headTimer = 0 ;

	bool isFrozen = false;
	float isFrozenTimer;
	const int totalFrozenTime = 15;

	bool isDying = false;
	bool isBurnt = false;
	



public:
	Zombie();
	float getdx();
	float getdy();
	void setSpeed(float, float );
	void setState(std::string);
	std::string getState();
	void setIsMoving(bool);
	bool getIsMoving();
	void setBurnt();	
	bool setIsFrozen(bool);
	bool isCollidable() ;
	bool isExist() override ;
	virtual void draw(RenderWindow&) ;
	virtual void action(float) ;
	virtual void animate(string) = 0 ;
	void setGlow();
	float burntTimer = 0;
	virtual ~Zombie();

};

