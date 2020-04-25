#ifndef COORD_H
#define COORD_H

class Coord
{
	int posX;
	int posY;
	
public:			
	Coord();
	int getPositionX() const;
	int getPositionY() const;
	void setPositionX(int);
	void setPositionY(int);
	static void gotoXY(int, int);
};

#endif