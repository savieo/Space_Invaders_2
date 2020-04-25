//#ifndef MISSILE_H
//#define MISSILE_H


#include "Coord.h"
#include "BulletManager.h"
#include "ETManager.h"
#include <iostream>
#include "Ship.h"
#include "Round.h"

class Missile
{
private:

public:
	//constants
	Missile();
	~Missile();
	char missileGraphic ;
	//const char sbullet = '*';
	int travelUpwords;
	bool isAlive;
	Coord coord;
	void startLaser(int, int, int);
	void eraseLaser() const;
	void drawLaser() const;
	void updateMissile();
	virtual void moveLaser();
	virtual void killLaser();
	bool isOnAlien();
	bool isOnShip();

};

//#endif