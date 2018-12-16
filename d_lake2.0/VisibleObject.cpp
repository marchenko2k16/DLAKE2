#include "VisibleObject.h"


///ADD DELTA TIME AND USE SPEEDX
void VisibleObject::move(float _dirX, float _dirY)
{

}

VisibleObject::VisibleObject(Sprite* _sprite, float _currentX, float _currentY) : sprite(_sprite),currentPosX (_currentX), currentPosY(_currentY)
{
}

VisibleObject::~VisibleObject()
{
	delete sprite;
}
