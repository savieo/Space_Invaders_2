#include "BulletManager.h"
#include "Bullet.h"
#include "ETManager.h"
#include "Ship.h"
#include "Missile.h"

BulletManager* BulletManager::bulletManager = nullptr;


void BulletManager::CreateBulletManager()
{
	bulletManager = new BulletManager();
}

void BulletManager::DestroyBulletManager()
{
	delete bulletManager;
}

BulletManager::BulletManager()
{
	for (int i = 0; i < maxBullets; i++)
		bulletArr[i] = nullptr;

	for (int i = 0; i < maxMissiles; i++)
		missileArr[i] = nullptr;
}

void BulletManager::updateBullets( )
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] != nullptr)
			bulletArr[i]->updateBullet();
	}
}

void BulletManager::UpdateMissiles() {

	for (int i = 0; i < maxMissiles; i++)
	{
		if (missileArr[i] != nullptr)
			missileArr[i]->updateMissile();
	}

}

void BulletManager::destroyBullets(Bullet * toDestroy)
{
	

	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] == toDestroy) //if they are both pointing to the same object
		{
			coord.gotoXY(bulletArr[i]->coord.getPositionX(), bulletArr[i]->coord.getPositionY());
			cout << " ";
			bulletArr[i] = nullptr;		
			delete bulletArr[i];
			break;
		}
	}

	//Do the excat same thing that ETManager does, go there and do the same here
	//The goal is to delete the memory from the array and free it from memory
	//and set the array index back to nullptr
	//should call the laser "KillLaser()"

}


void BulletManager::destroyMissile(Missile * toDestroy)
{


	for (int i = 0; i < maxMissiles; i++)
	{
		if (missileArr[i] == toDestroy) //if they are both pointing to the same object
		{
			coord.gotoXY(missileArr[i]->coord.getPositionX(), missileArr[i]->coord.getPositionY());
			cout << " ";
			missileArr[i] = nullptr;
			delete missileArr[i];
			break;
		}
	}

	//Do the excat same thing that ETManager does, go there and do the same here
	//The goal is to delete the memory from the array and free it from memory
	//and set the array index back to nullptr
	//should call the laser "KillLaser()"

}


void BulletManager::distroyAllMissile() {

	for (int i = 0; i < maxMissiles; i++)
	{
		if (missileArr[i] != nullptr)
			BulletManager::bulletManager->destroyMissile(BulletManager::bulletManager->missileArr[i]);
	}
}

void BulletManager::distroyAllBullet() {

	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] != nullptr)
			BulletManager::bulletManager->destroyBullets(BulletManager::bulletManager->bulletArr[i]);
	}
}

void BulletManager::createBullet(int x, int y, int upwards, int bulletType )
{
	int index;
	
	if (bulletType == 1) 
	{
		Bullet*  newBullet = new Bullet();
		index = checkAvailableBulletIndex();
		bulletArr[index] = newBullet;
		newBullet->startLaser(x, y, upwards);
	}		
	else
	{
		Missile* newMissile = new Missile();
		index = checkAvailableMissileIndex();
		missileArr[index] = newMissile;
		newMissile->startLaser(x, y, upwards);
	}
}


int BulletManager::checkAvailableBulletIndex() {
	

	for (int i = 0; i <  maxBullets; i++) 
	{

		if (bulletArr[i] == nullptr) 
		{
			return i;
		}
	}
	return -1;
}


int BulletManager::checkAvailableMissileIndex() {


	for (int i = 0; i < maxMissiles; i++)
	{

		if (missileArr[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

