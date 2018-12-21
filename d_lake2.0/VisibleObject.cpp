#include "VisibleObject.h"


///ADD DELTA TIME AND USE SPEEDX
void VisibleObject::move(float _dirX, float _dirY, float _dTime)
{

}

VisibleObject::VisibleObject(Sprite* _sprite, float _currentX, float _currentY, float _speed) :
	sprite(_sprite),currentPosX (_currentX), currentPosY(_currentY), speed(_speed)
{
}

VisibleObject::~VisibleObject()
{
	delete sprite;
}
