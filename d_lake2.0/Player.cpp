#include "Player.h"



void Player::move(float _dirX, float _dirY, float _dTime)
{
	currentPosX += _dirX;
	currentPosY += _dirY;
}

void Player::update(float _dirX, float _dirY, float _dTime)
{
	move(_dirX, _dirY, _dTime);
}

Player::Player(Sprite* _sprite, float _currentX, float _currentY, float _speed) :
	VisibleObject(_sprite, _currentX, _currentY, _speed)
{
	Player::State = ALIVE;
}


Player::~Player()
{
}
