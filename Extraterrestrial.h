#pragma once
//#ifndef EXTRATERRESTRIAL_H
//#define EXTRATERRESTRIAL_H

#include "Coord.h"
#include "Round.h"

class Extraterrestrial
{
protected:
	int extraterrestrialType;	//identifier for type
	int extraterrestrialValue;  //how many points it is worth
	int timeTillFire;			//when they should fire
	int cooldown = 9;			//Should be setup by the invidual child
	int timeTillMove;           // when they should move
	int resetMove =210 ;
	int intvTillFireBullet;
	int intUpdateBullet =150;
public:
   //static Extraterrestrial* extraterrestrical;
	Coord coord;
	//Round round;
	bool isAlive;
	Extraterrestrial(int,int);
	virtual void update();
	void eraseExtraterrestrial() const;
	void drawExtraterrestrial() const;
	void checkDeath();
	int addPoints() ;
	 void die();
	 void fireBullet();

protected:
	virtual void move();
	virtual void fire();

};

//#endif




