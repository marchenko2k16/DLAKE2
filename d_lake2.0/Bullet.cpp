#include "Bullet.h"

void Bullet::normalize()
{
	float vectorX, vectorY;
	vectorX = directionX - currentPosX;
	vectorY = directionY - currentPosY;
	float magnitude = sqrt(pow(vectorX, 2) + pow(vectorY, 2));
	normX = (vectorX / magnitude);
	normY = (vectorY / magnitude);
	normalizedFlag = true;
}

void Bullet::move(float _dirX, float _dirY, float _dTime)//FOR FUTURE IF WILL DISLOC 
{
	currentPosX += normX;
	currentPosY += normY;
}

void Bullet::update(float _dislocX, float _dislocY, float _dTime)
{
	if (normalizedFlag != true)
	{
		normalize();
	}
	move(_dislocX, _dislocY, _dTime);
}

Bullet::Bullet(Sprite* _sprite, float _dirX, float _dirY, float _speed) : directionX(_dirX), directionY(_dirY)// : VisibleObject(_sprite, _currentX, _currentY)
{
	speed = _speed;
	sprite = _sprite;
}


Bullet::~Bullet()
{
}
