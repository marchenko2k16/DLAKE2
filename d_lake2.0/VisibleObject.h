#pragma once
#include"Framework.h"
#include <cmath>
#include <iostream>

class VisibleObject
{
private:
public:
	//use with delta time only
	float speed;
	
	Sprite* sprite;
	float  currentPosX;
	float  currentPosY;
	
	int spriteSizeX;
	int spriteSizeY;

	virtual void move(float _dirX, float _dirY, float _dTime) = 0;
	virtual void update(float _dirX, float _dirY, float _dTime) = 0;//move / shoot / 
	VisibleObject() = default;
	VisibleObject(Sprite* _sprite, float _currentX, float _currentY, float _speed);
	~VisibleObject();
};

