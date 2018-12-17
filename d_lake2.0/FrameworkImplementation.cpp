#include "FrameworkImplementation.h"

Player* FrameworkImplementation::staticPlayer;

/*
	---SOME NOTES
	---ENEMY.PNG IS SPRITE SIZE IS X, BUT THE VISUAL SIZE OF PICTURE IS LIKE X - N, CAUSE OF ALPHA CHANEL
	---ALL AROUND THE ENEMY PIC, SO TO COUNT COLLISION THE RADIS SHOULD BE COUNTED BASED NOT ONLY ON ENEMY.PNG SIZE(X/Y).
	---BUT ALSO WE SHOULD SUBSTRUCT SOME N VALUE, TO MAKE VISUAL COLLISIONS MORE REALISTIC
*/
void FrameworkImplementation::collisionDetection()///TODO - AABB 
{
	//IN THIS CASE TRY TO COMPARE RAD
	//float enemyRadius, bulletRadius, playerRadius;
	//enemyRadius = sqrt(pow(enemySpriteX / 2.0, 2) + pow(enemySpriteY / 2.0, 2));
	//bulletRadius = sqrt(pow(bulletSpriteX / 2.0, 2) + pow(bulletSpriteY / 2.0, 2));;
	//playerRadius = sqrt(pow(playerSpriteX /2.0, 2) + pow(playerSpriteY/2.0, 2));

	//player - enemy
	for (int i = 1; i <= enemiesNum; i++)
	{
		float betweenPlayerEnemy = sqrt(
			pow(staticPlayer->currentPosX - gameObjects.at(i)->currentPosX, 2) +
			pow(staticPlayer->currentPosY - gameObjects.at(i)->currentPosY, 2)
		);//for debug

		if ( (playerSpriteX/2 + enemySpriteX/2)  >= betweenPlayerEnemy)
		{
			staticPlayer->State = Player::DEAD;
		}
	}
	//enemy - enemy
	for (int i = 1; i < enemiesNum; i++)
	{
		for (int j = i; j < enemiesNum; j++)
		{
			float betweenEnemyEnemy = sqrt(
				pow(gameObjects.at(i)->currentPosX - gameObjects.at(j + 1)->currentPosX, 2) +
				pow(gameObjects.at(i)->currentPosY - gameObjects.at(j + 1)->currentPosY, 2)
			);//for debug

			if (enemySpriteX >= betweenEnemyEnemy)
				{
				}
			}
	}
	//bullet - enemy
	for (int i = 1; i <= enemiesNum; i++)
	{
		for (int j = enemiesNum + 1; j <= (enemiesNum + bulletsInGame); j++)
		{
			float betweenBulletEnemy = sqrt(
				pow(gameObjects.at(i)->currentPosX - gameObjects.at(j)->currentPosX, 2) +
				pow(gameObjects.at(i)->currentPosY - gameObjects.at(j)->currentPosY, 2)
			);//for debug
			if ( (bulletSpriteY / 2.0 + enemySpriteY / 2.0) >= betweenBulletEnemy)
			{
				delete_object(i, j);
				--enemiesNum;
				--bulletsInGame;
			}
		}
	}
}
void FrameworkImplementation::create_bullet()
{
	bulletsInGame += 1;
	gameObjects.push_back(new Bullet(createSprite("bullet.png"), mouseX, mouseY));
	gameObjects.at(gameObjects.size() - 1)->spriteSizeX = bulletSpriteX;
	gameObjects.at(gameObjects.size() - 1)->spriteSizeY = bulletSpriteY;
	gameObjects.at(gameObjects.size() - 1)->currentPosX = staticPlayer->currentPosX;
	gameObjects.at(gameObjects.size() - 1)->currentPosY = staticPlayer->currentPosY;
}

void FrameworkImplementation::delete_object(int first_index, int second_index)
{
	destroySprite(gameObjects.at(first_index)->sprite);
	destroySprite(gameObjects.at(second_index)->sprite);
	
	gameObjects.erase(gameObjects.begin() + first_index);
	gameObjects.erase(gameObjects.begin() + (second_index - 1));
}

void FrameworkImplementation::PreInit(int & width, int & height, bool & fullscreen)
{
	width = frameWidth;
	height = frameHeight;
	fullscreen = false;
}

bool FrameworkImplementation::Init()
{
	previousTime = getTickCount() / 1000.0;
	std::cout << previousTime << "\n";
	playerDislocationX = 0;
	playerDislocationY = 0;
	bulletsInGame = 0;
	showCursor(false);
	{//sprite part
		reticleSprite = createSprite("circle.tga");
		///enemySprite = createSprite("enemy.png");
		///bulletSprite = createSprite("bullet.png");
		playerSprite = createSprite("avatar.jpg");

		getSpriteSize(reticleSprite, reticleSpriteX, reticleSpriteY);
		getSpriteSize(createSprite("bullet.png"), bulletSpriteX, bulletSpriteY);
		getSpriteSize(createSprite("enemy.png"), enemySpriteX, enemySpriteY);
		getSpriteSize(playerSprite, playerSpriteX, playerSpriteY);
	}
	{//player part
		staticPlayer = new Player(playerSprite, frameWidth/2.0, frameHeight/2.0);
		staticPlayer->spriteSizeX = playerSpriteX;
		staticPlayer->spriteSizeY = playerSpriteY;
		gameObjects.push_back(staticPlayer);
	}

	{//enemies part 
		std::default_random_engine randomizeX;
		randomizeX.seed(getTickCount());
		std::uniform_real_distribution<float> distributionX(0, frameWidth);
		
		std::default_random_engine randomizeY;
		randomizeY.seed(getTickCount() + 1);
		std::uniform_real_distribution<float> distributionY(0, frameHeight);

		for (int i = 0; i < enemiesNum; i++)
		{
			gameObjects.push_back(new Enemy(createSprite("enemy.png"), distributionX(randomizeX), distributionY(randomizeY)));
			gameObjects.at(i + 1)->spriteSizeX = enemySpriteX;
			gameObjects.at(i + 1)->spriteSizeY = enemySpriteY;
		}
	}
	return true;
}

void FrameworkImplementation::Close() {}
bool FrameworkImplementation::Tick()
{
	collisionDetection();
	if (staticPlayer->State == Player::DEAD)
	{
		return true;
	}
	float currentTime = getTickCount() / 1000.0;
	float deltaTime = currentTime - previousTime;
	//std::cout << deltaTime << "\n";
	//normalize * speed * deltatime
	drawTestBackground();

	for (auto element : gameObjects)
	{
		drawSprite(element->sprite, element->currentPosX - (element->spriteSizeX / 2.0),
			element->currentPosY - (element->spriteSizeY / 2.0));
	}
	//updating objects
	for (int i = 0 ; i < gameObjects.size(); i++)
	{
		if (i == 0) 
		{
			staticPlayer->update(playerDislocationX, playerDislocationY);
		}
		else if(i >0 && i <= enemiesNum)
		{
			gameObjects.at(i)->update(staticPlayer->currentPosX, staticPlayer->currentPosY);
		}
		else
		{//smth
			gameObjects.at(i)->update(playerDislocationX, playerDislocationY);
		}
	}
	//
	drawSprite(reticleSprite, mouseX - (reticleSpriteX / 2), mouseY - (reticleSpriteY / 2));
	//SET BACK TO 0 
	playerDislocationX = 0;
	playerDislocationY = 0;
	previousTime = currentTime;

	return false;
}
void FrameworkImplementation::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	mouseX = x;
	mouseY = y;
}

void FrameworkImplementation::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (isReleased != true)
	{
		create_bullet();
	}
}

void FrameworkImplementation::onKeyPressed(FRKey k)
{								
	switch (k)					
	{							
	case FRKey::DOWN:          	
		playerDislocationX = 0;
		playerDislocationY += 20;
		break;					
	case FRKey::UP:				
		playerDislocationX = 0;
		playerDislocationY -= 20;
		break;					
	case FRKey::LEFT:			
		playerDislocationX -= 20;
		playerDislocationY = 0;
		break;					
	case FRKey::RIGHT:			
		playerDislocationX += 20;
		playerDislocationY = 0;
		break;					
	}							
}								

void FrameworkImplementation::onKeyReleased(FRKey k)
{
}

FrameworkImplementation::FrameworkImplementation(int _enemiesNum, int _amoNum, int _width, int _height) :
	enemiesNum(_enemiesNum), amoNum(_amoNum), frameWidth(_width), frameHeight(_height)
{
	std::cout << "Framwork Implementation constructor called\n";
}


FrameworkImplementation::~FrameworkImplementation()
{
}
