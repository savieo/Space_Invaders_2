#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include <iostream>
#include "Coord.h"
using namespace std;

class Bullet; //foward declaration

class Missile;

class BulletManager
{
public:
	int bulletType;
	static BulletManager* bulletManager;
	static void CreateBulletManager();
	static void DestroyBulletManager();
	Coord coord;
	BulletManager();
	const int maxBullets = 500;
	const int maxMissiles = 500;
	int test = 0;
	int checkAvailableBulletIndex();
    Bullet* bulletArr[500];
	Missile* missileArr[500];
	void updateBullets();
	void destroyBullets(Bullet*);
	void distroyAllBullet();
	void createBullet(int X,int Y ,int upwrds ,int bulletType);
	void destroyMissile(Missile*);
	void distroyAllMissile();
	int checkAvailableMissileIndex();
	void UpdateMissiles();
private:
};
#endif