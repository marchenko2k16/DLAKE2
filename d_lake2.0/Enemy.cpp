#include "Enemy.h"


void Enemy::move(float _dirX, float _dirY)
{
	float vectorX, vectorY;
	vectorX = _dirX - currentPosX;
	vectorY = _dirY - currentPosY;
	float magnitude = sqrt(pow(vectorX, 2) + pow(vectorY, 2));
	currentPosX += vectorX / magnitude;
	currentPosY += vectorY / magnitude;
}

void Enemy::update(float _dirX, float _dirY)
{
	move(_dirX, _dirY);
}

Enemy::Enemy(Sprite* _sprite, float _currentX, float _currentY) : VisibleObject(_sprite, _currentX, _currentY)
{
}


Enemy::~Enemy()
{
}
