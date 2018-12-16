#include "Bullet.h"

void Bullet::normalize()
{
	float vectorX, vectorY;
	vectorX = directionX - currentPosX;
	vectorY = directionY - currentPosY;
	float magnitude = sqrt(pow(vectorX, 2) + pow(vectorY, 2));
	normX = vectorX / magnitude;
	normY = vectorY / magnitude;
	normalizedFlag = true;
}

void Bullet::move(float _dislocX, float _dislocY)//FOR FUTURE IF WILL DISLOC 
{
	currentPosX += normX;
	currentPosY += normY;
}

void Bullet::update(float _dislocX, float _dislocY)
{
	if (normalizedFlag != true)
	{
		normalize();
	}
	move(_dislocX, _dislocY);
}

Bullet::Bullet(Sprite* _sprite, float _dirX, float _dirY) : directionX(_dirX), directionY(_dirY)// : VisibleObject(_sprite, _currentX, _currentY)
{
	sprite = _sprite;
}


Bullet::~Bullet()
{
}
