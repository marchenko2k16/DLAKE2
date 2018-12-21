#pragma once
#include "VisibleObject.h"
class Enemy :
	public VisibleObject
{
public:
	void move(float _dirX, float _dirY, float _dTime) override;
	void update(float _dirX, float _dirY, float _dTime) override;
	Enemy(Sprite* _sprite, float _currentX, float _currentY, float _speed);
	~Enemy();
};

