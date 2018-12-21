#pragma once
#include "VisibleObject.h"
#include "Gun.h"

class Player :
	public VisibleObject
{
public:
	enum { ALIVE, DEAD } State;
	void move(float _dirX, float _dirY, float _dTime) override;
	void update(float _dirX, float _dirY, float _dTime) override;
	Player(Sprite* _sprite, float _currentX, float _currentY, float _speed);
	~Player();
};

