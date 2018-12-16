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
	void move(float _dislocX, float _dislocY) override;
	void update(float _dislocX, float _dislocY) override;
	Bullet(Sprite* _sprite, float _dirX, float _dirY);
	~Bullet();
};

