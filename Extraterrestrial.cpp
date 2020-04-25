#include "Extraterrestrial.h"
#include <stdlib.h>
#include<iostream>
#include "Round.h"
#include "ETManager.h"
#include <windows.h>
#include "BulletManager.h"
#include "Coord.h"
using namespace std;

//Extraterrestrial* Extraterrestrial:: extraterrestrical=nullptr;

Extraterrestrial::Extraterrestrial(int type,int value)
{
	extraterrestrialType=type;
	extraterrestrialValue=value;
	timeTillFire = cooldown;
	timeTillMove = resetMove;
	intvTillFireBullet = intUpdateBullet;
	coord.setPositionX(rand() % 100+60);
	coord.setPositionY(rand() % 11+ 9);
	isAlive = true;
//Just spawned, so should draw it
	drawExtraterrestrial();

}

void Extraterrestrial::move()
{
	int xPos, yPos;

	//In here should be the basic move logic (You need to add it)
//Undraw where it was, and move it to where it needs to go
//If there is an alien there, we should not be able to move there.
//If there is a laser there, it should kill us.
	timeTillMove = resetMove;
	
	for (int i = 0; i < ETManager::etManager->MAX_ET; i++)
	{
		if (ETManager::etManager->etArr[i] != nullptr)
		{
			ETManager::etManager->etArr[i]->eraseExtraterrestrial();
			g:xPos = rand() % 100 + 60;
			  yPos = rand() % 11 + 9;

			for (int j = 0;  j< ETManager::etManager->MAX_ET; j++) 
			{
				if(ETManager::etManager->etArr[j]!=nullptr)
				{
					if (ETManager::etManager->etArr[j]->coord.getPositionX() == xPos && ETManager::etManager->etArr[j]->coord.getPositionY() == yPos)
					{
						goto g;
					}
				}
				
				
			}
			//#f   check for laser present at that location
			//for (int k = 0; k < BulletManager::bulletManager->maxBullets; k++)
			
			ETManager::etManager->etArr[i]->coord.setPositionX(xPos);
			ETManager::etManager->etArr[i]->coord.setPositionY(yPos);
			ETManager::etManager->etArr[i]->drawExtraterrestrial();
		}
	}
}

void Extraterrestrial::fire()
{
	timeTillFire = cooldown;
	drawExtraterrestrial();


}

void Extraterrestrial::update()
{
	//Any logic in here needed, timers, etc
	timeTillFire--;
	timeTillMove--;
	intvTillFireBullet--;
	if (timeTillFire < 0)
		fire();
	if(timeTillMove < 0)
		move();	
	if (intvTillFireBullet < 0)
		fireBullet();


}



void Extraterrestrial::eraseExtraterrestrial() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";	
}

void Extraterrestrial::drawExtraterrestrial() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << "@";
}



void Extraterrestrial::checkDeath()
{
	//if(???)   the tile we are going on has a laser (Check the board, or check bullet manager) 
	//Round::etManager->destroy(this);


}

 int  Extraterrestrial::addPoints()  
{
	 
	 //round.updateScore(extraterrestrialValue);
	 return extraterrestrialValue;
}

void Extraterrestrial::die() //This is called by the manager
{
	eraseExtraterrestrial();
	Beep(1568, 200);
	Round::round->updateScore(extraterrestrialValue);
	
	
	//erase extraterrestial because it has died
}

void Extraterrestrial::fireBullet()
{
		
	int xPos, yPos;
	intvTillFireBullet = intUpdateBullet;

	for (int i = 0; i < ETManager::etManager->MAX_ET; i++)
	{
		if (ETManager::etManager->etArr[i]!=nullptr)
		{
			xPos = ETManager::etManager->etArr[i]->coord.getPositionX();
			yPos = ETManager::etManager->etArr[i]->coord.getPositionY();
			BulletManager::bulletManager->createBullet( xPos, yPos+1, false, BulletManager::bulletManager->bulletType);

		}	
	}
	
}

