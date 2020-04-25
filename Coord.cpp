#include "Coord.h"
#include <windows.h>
#include <iostream>
using namespace std;

Coord::Coord()
{
	posX=0;
	posY=0;
}

int Coord::getPositionX() const
{
	return posX;
}

int Coord::getPositionY() const
{
	return posY;
}

void Coord::setPositionX(int x)
{
	posX=x;
}

void Coord::setPositionY(int y)
{
	posY=y;
}

void Coord::gotoXY(int x, int y)
{
	cout.flush();
	COORD coord;   
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}