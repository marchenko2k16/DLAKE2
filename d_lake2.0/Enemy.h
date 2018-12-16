#pragma once
#include "VisibleObject.h"
class Enemy :
	public VisibleObject
{
public:
	void move(float _dirX, float _dirY) override;
	void update(float _dirX, float _dirY) override;
	Enemy(Sprite* _sprite, float _currentX, float _currentY);
	~Enemy();
};

