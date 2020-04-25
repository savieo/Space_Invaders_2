#pragma once
#include <iostream>
#include "Extraterrestrial.h"
#include "BulletManager.h"
#include "Round.h"
#include "Coord.h"
using namespace std;

class Extraterrestrial;

class ETManager // extraterresttial manager 
{
//Vars
private:
	
	const int ticksPerSpawn = 30; //number of ticks between spawns

	
public:
     Extraterrestrial* etArr[20];
	 const int MAX_ET = 20;

//Functions
public:
	int ticks; //Current number of tick
	int nextSpawnTick;  //the number of tick when the next one spawns
	ETManager();
	static ETManager* etManager;
	static void CreateEtManager();
	static void DestroyEtManager();
	Coord coord;
	void update(); //Update all ETs
	void spawnET();
	void destroy(Extraterrestrial*);
	 Extraterrestrial* getET(int x, int y);	 //returns if an ET exists at location
	void isWon();
	void setRandomCoord();
};