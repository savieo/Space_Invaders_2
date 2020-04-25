#ifndef SHIP_H
#define SHIP_H

#include "Coord.h"

class Ship
{
protected:
	void drawShip() const;

	// collide logic
	// shoot logic

public :
	bool isDead = false;

public:
	void eraseShip() const;
	Coord coord;
	Ship();

	Ship(int bulletType);		
	void changePosition(char);
	void checkHealth();
};

#endif