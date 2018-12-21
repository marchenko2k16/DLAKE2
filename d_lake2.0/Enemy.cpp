#include "Enemy.h"


void Enemy::move(float _dirX, float _dirY, float _dTime)
{
	float vectorX, vectorY;
	vectorX = _dirX - currentPosX;
	vectorY = _dirY - currentPosY;
	float magnitude = sqrt(pow(vectorX, 2) + pow(vectorY, 2));
	currentPosX += (vectorX / magnitude) * speed * _dTime;
	currentPosY += (vectorY / magnitude) * speed * _dTime;
}

void Enemy::update(float _dirX, float _dirY, float _dTime)
{
	move(_dirX, _dirY, _dTime);
}

Enemy::Enemy(Sprite* _sprite, float _currentX, float _currentY, float _speed) : VisibleObject(_sprite, _currentX, _currentY, _speed)
{
}


Enemy::~Enemy()
{
}
