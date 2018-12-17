#pragma once
#include "Framework.h"//implement

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
#include <random>


class FrameworkImplementation :
	public Framework
{
private:
	float previousTime;
	//SPRITE INFO. SHOULD NOT APPEAR IN THIS CLASS, I GUESS
	Sprite* reticleSprite;
	//because when delete sprite we will delete this sprite for all objs
	//Sprite* enemySprite;
	//Sprite* bulletSprite;
	Sprite* playerSprite;

	int reticleSpriteX, reticleSpriteY;
	int bulletSpriteX, bulletSpriteY;
	int enemySpriteX, enemySpriteY;
	int playerSpriteX, playerSpriteY;

	//SET WHEN CONSTUCTOR CALLS
	int enemiesNum;
	int amoNum;//set to player later
	int bulletsInGame;

	int frameHeight;
	int frameWidth;

	int mapSizeX;
	int mapSizeY;
	//RESET WHEN 
	int playerDislocationX;
	int playerDislocationY;
	//
	std::vector<VisibleObject*> gameObjects;

	static Player* staticPlayer;
	int mouseX, mouseY;
public:
	void collisionDetection();
	void create_bullet();
	void delete_object(int first_index, int second_index);
	virtual void PreInit(int& width, int& height, bool& fullscreen);
	virtual bool Init();
	virtual void Close();
	virtual bool Tick();
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);
	FrameworkImplementation(int _enemiesNum, int _amoNum, int _width, int _height);
	~FrameworkImplementation();
};

