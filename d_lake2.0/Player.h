#pragma once
#include "VisibleObject.h"
#include "Gun.h"

class Player :
	public VisibleObject
{
public:
	void move(float _dirX, float _dirY) override;
	void update(float _dirX, float _dirY) override;
	Player(Sprite* _sprite, float _currentX, float _currentY);
	~Player();
};

