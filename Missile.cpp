#include "Missile.h"
#include <Windows.h>
Missile::Missile()
{
	missileGraphic = '*';
}

Missile::~Missile()
{
}

void Missile::startLaser(int x, int y, int _travelUpwords)
{

	travelUpwords = (_travelUpwords) ? -1 : 1;
	coord.setPositionX(x);
	coord.setPositionY(y);
	drawLaser();
	isAlive = true;
}

void Missile::eraseLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
}

void Missile::drawLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << missileGraphic;
}

void Missile::updateMissile()
{
	if (isOnAlien())
	{
		isAlive = false;
		BulletManager::bulletManager->destroyMissile(this);
	}
	else if (isOnShip())
	{
		
		int C = 523, D = 698, F = 527, E = 665;

		Beep(C, 382); Beep(C, 382); Beep(D, 340); Beep(C, 382); Beep(F, 286); Beep(E, 304);
			Round::round->ship.isDead = true;

			BulletManager::bulletManager->distroyAllMissile();

		
	}
	else
	{
		Missile::moveLaser();
	}

}

void Missile::moveLaser()
{
	Missile::eraseLaser();

	if (coord.getPositionY() > 8 && coord.getPositionY() < 33)//If still in bounds
	{
		coord.setPositionY(coord.getPositionY() + travelUpwords);

		Missile::drawLaser();
	}
	else  //outta bounds
	{
		isAlive = false;
		BulletManager::bulletManager->destroyMissile(this);

	}
}

void Missile::killLaser()
{
	Missile::eraseLaser();
	isAlive = false;
}

bool Missile::isOnAlien()
{
	Extraterrestrial*  et = ETManager::etManager->getET(coord.getPositionX(), coord.getPositionY());
	if (et != nullptr)
	{
		ETManager::etManager->destroy(et);
		return true;
	}
	return false;
}

bool Missile::isOnShip()
{
	if (Round::round->ship.coord.getPositionX() == coord.getPositionX() && Round::round->ship.coord.getPositionY() == coord.getPositionY())
	{
		//ETManager::etManager->setRandomCoord();	
			return true;
	}
	return false;
}


