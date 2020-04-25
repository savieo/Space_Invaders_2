#include "Ship.h"
#include "Bullet.h"
#include "Round.h"
#include <iostream>
#include<Windows.h>
using namespace std;

#define corXshipLeftLimit 40;
#define corXshipRightLimit 170;

void Ship::eraseShip() const
{	
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());//  put the cursor location 
	cout << " ";  // delete the ship
}

Ship::Ship()
{
	coord.setPositionX(105);
	coord.setPositionY(33);
	drawShip();
}

void Ship::drawShip() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << "^";
}


Ship::Ship(int _bulletType)
{
 BulletManager::bulletManager->bulletType = _bulletType;
	
}

void Ship::changePosition(char key)
{	
	int lx, rx;
	int leftLimit = corXshipLeftLimit;
	int rightLimit = corXshipRightLimit;
	eraseShip();


	switch(key)
	{
		case 'a':	 lx = coord.getPositionX() - 1;
					if (leftLimit < lx)
					{
						coord.setPositionX(lx);
					}
					else
					{
						Beep(1568, 200);
						checkHealth();
					
					}
					BulletManager::bulletManager->createBullet(coord.getPositionX(), 32, true, BulletManager::bulletManager->bulletType );
					
			        break;

		case 'd':	 rx = coord.getPositionX() + 1;
			         if (rightLimit > rx)
					 coord.setPositionX(rx);
					 else
					 {
						 Beep(1568, 200);
						 checkHealth();

					 }
					 BulletManager::bulletManager->createBullet(coord.getPositionX(), 32, true, BulletManager::bulletManager->bulletType );
					
					break;
		case 's':  
					BulletManager::bulletManager->createBullet( coord.getPositionX(), 32, true, BulletManager::bulletManager->bulletType );
					
					break;


	}


	drawShip();
}


void Ship::checkHealth() {

	if (Round::round->getHealth() < 1)
	{
		if ((BulletManager::bulletManager->bulletType) == 1)
		{
			BulletManager::bulletManager->distroyAllBullet();
		}
		else
		{
			BulletManager::bulletManager->distroyAllMissile();

		}

		Round::round->ship.isDead = true;
	}
	else
	{
		Round::round->reduceHealth();
	}
}











