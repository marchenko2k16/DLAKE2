#include "Player.h"



void Player::move(float _dirX, float _dirY)
{
	currentPosX += _dirX;
	currentPosY += _dirY;
}

void Player::update(float _dirX, float _dirY)
{
	move(_dirX, _dirY);
}

Player::Player(Sprite* _sprite, float _currentX, float _currentY) : VisibleObject(_sprite, _currentX, _currentY)
{
}


Player::~Player()
{
}
