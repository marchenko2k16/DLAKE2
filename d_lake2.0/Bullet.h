#pragma once
#include "VisibleObject.h"
class Bullet :
	public VisibleObject
{
public:
	bool normalizedFlag = false;
	float directionX, directionY;
	float normX, normY;
	void normalize();
	void move(float _dirX, float _dirY, float _dTime) override;
	void update(float _dirX, float _dirY, float _dTime) override;
	Bullet(Sprite* _sprite, float _dirX, float _dirY, float _speed);
	~Bullet();
};

