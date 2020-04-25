#include "Bullet.h"
#include <Windows.h>
using namespace std;



Bullet::Bullet()
{
	bulletGraphic = '|';
}

Bullet::~Bullet()
{
}



void Bullet::startLaser(int x, int y, int _travelUpwords)
{
	travelUpwords = (_travelUpwords) ? -1:1 ;
	coord.setPositionX(x);
	coord.setPositionY(y);
	drawLaser();
	isAlive = true;
}

void Bullet::eraseLaser() const
{	
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";
}

void Bullet::drawLaser() const
{	
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << bulletGraphic;
}

void Bullet::updateBullet()
{
	
	if (isOnAlien())
	{
		isAlive = false;
		BulletManager::bulletManager->destroyBullets(this);
	}
	else if (isOnShip())
	{
		if (Round::round->getHealth() < 1) 
		{

			int C = 523, D = 698, F = 527, E = 665;

			Beep(C, 382); Beep(C, 382); Beep(D, 340); Beep(C, 382); Beep(F, 286); Beep(E, 304);
			Round::round->ship.isDead = true;

			BulletManager::bulletManager->distroyAllBullet();
		 }

		else
		{
			BulletManager::bulletManager->destroyBullets(this);
	       // Ship::drawShip
			Round::round->reduceHealth();
		}

	   
	}
	else
	{
		moveLaser();
	}

	//Check if there is an alien
		//use ETManager::etManager->getET(x,y)  and check if its null
		//if it is not null, then we need to tell the ETManager that it has died & pass the reference we got in step above
		//then destroy this laser by calling the BulletManager and pass "this" reference
	//else
		//Move the laser foward


}

void Bullet::moveLaser()
{	
	eraseLaser();

	if (coord.getPositionY()>8 && coord.getPositionY()<33)//If still in bounds
	{
		coord.setPositionY(coord.getPositionY()+travelUpwords);
		
		drawLaser();
	}
	else  //outta bounds
	{
		isAlive = false;
		BulletManager::bulletManager->destroyBullets(this);
		
	}
}

void Bullet::killLaser()
{
	eraseLaser();
	isAlive = false;
}

bool Bullet::isOnAlien()
{
	Extraterrestrial*  et= ETManager::etManager->getET(coord.getPositionX(), coord.getPositionY());
	if (et != nullptr) 
	{
		ETManager::etManager->destroy(et);
		return true;
	}
	return false;
}


bool Bullet::isOnShip()
{
	if (Round::round->ship.coord.getPositionX() == coord.getPositionX() && Round::round->ship.coord.getPositionY() == coord.getPositionY())
	{
		//ETManager::etManager->setRandomCoord();

		return true;
	}
	return false;
}


