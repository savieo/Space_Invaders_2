#include "Round.h"
#include "BulletManager.h"
#include "ETManager.h"
#include <conio.h>
#include <ctype.h>
#include "Bullet.h"
#include <thread>
#include <windows.h>
#include "UIKit.h"

#define iBullet 1

Round* Round::round = nullptr;

Round::Round(int difficulty) 
{
	Round::difficulty = difficulty >= 1 && difficulty <= 3 ? difficulty : 1;
	Round::score = 0;
	Round::HighScore = 0;
	Round::health = 5;
	isWon = false;
	BulletManager::CreateBulletManager();
	ETManager::CreateEtManager();
	//Ship::Ship(1);
}

void Round::CreateRound(int difficulty, int bulletType)
{
	
	round = new Round(difficulty);
	Ship::Ship(bulletType);
}

Round::~Round()
{
	BulletManager::DestroyBulletManager();
	ETManager::DestroyEtManager();
}

char  Round::startRound() 
{
	
	resetRound();
	char choice;
	while (!ship.isDead)
	{
		
		ETManager:: etManager->update() ;

		if (_kbhit())
		{
			char d = _getch();
			if (d == 'p') 
			{
				_getch();
			}
			else 
			{
			       ship.changePosition(d);
			}
		}
	
		if (BulletManager::bulletManager->bulletType == iBullet)
		{
			BulletManager::bulletManager->updateBullets();
		}
		else
		{
			BulletManager::bulletManager->UpdateMissiles();
		}
		
		
		displayUpdateScore();
		ETManager:: etManager->isWon();
		//sleep
		Sleep(100);
	}
	system("cls");
	
	if (getHighScore() != 0) 
	{		
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYou New High score is  : " << getHighScore();	
	}
	else
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYou  score is  : " << getScore();

	}
	cout << endl;
	if (isWon == true)
	{
		cout << "\t\t\t\t\t\t\t\t\t\tCongratulations.. you won!!" << endl;
	}
	else
	{
	cout << "\t\t\t\t\t\t\t\t\t\t GAME OVER ! " << endl;
	}
	
	x:cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress (c) to contine or (e) to exit :";
		
	cin >> choice;
	cin.clear();
	cin.ignore(256, '\n');
	cout << endl;
	if (choice == 'c') {

		return choice;
	}
	else if (choice == 'e')
	{
		exit(1);
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t\tInvalid input try again...!"<< endl;
		Sleep(3000);
		system("cls");
		goto x;
	}
	//THIS REPLACES THE MAIN FUNCTION
	//Should loop
	//Should call bulletManager and ETManager::CreateManager
	//should update them
	//should update player
	//Should have a pause	
}


void Round::updateScore(int _score) 
{
	score += _score;
}


int Round::getScore() 
{
	return score;
}

void Round::displayUpdateScore() 
{
	UIKit::gotoXY(20, 2);

	cout << "\t\t\t\t\t\t\tYour Score is: " << to_string(Round::round->getScore());
	cout << "\t\t\t Your current Health is :" << to_string(Round::round->getHealth());
	cout << "\n\t\t\t\t\t\t\t\t\t\t To Pause: Press P         To Countine: Press Any Key " << endl;
	cout << "\n\t\t\t\t\t\t\t\t To Move left: Press A    To Move Right: Press D   TO Fire Bullet : Press S" << endl;
}

int Round::getHealth() 
{
	return health;
}

void Round::reduceHealth()
{
	health--;
}
int Round::getHighScore()
{
	return HighScore;
}
void Round::setHighScore(int _score)
{
	 HighScore=score;
}


void Round::resetRound() {

	Round::score = 0;
	Round::health = 5;
	isWon = false;
	ETManager::etManager->ticks = 0;
	ETManager::etManager->nextSpawnTick = 0;
	ship.isDead = false;
}