#ifndef BULLET_H
#define BULLET_H

#include "Coord.h"
#include "BulletManager.h"
#include "ETManager.h"
#include <iostream>
#include "Ship.h"
#include "Round.h"

class Bullet
{
private:
	 
public:
	//constants
	Bullet();
	~Bullet();
	char bulletGraphic = '|';
	int travelUpwords;
	bool isAlive;
	Coord coord;
	void startLaser(int, int , int );
	void eraseLaser() const;
	void drawLaser() const;
	void updateBullet( );
	virtual void moveLaser();
	virtual void killLaser();
	bool isOnAlien();
	bool isOnShip();

};

#endif