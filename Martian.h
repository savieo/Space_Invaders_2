ifndef MARTIAN_H
#define MARTIAN_H

#include "Extraterrestrial.h"

class Martian : public Extraterrestrial
{
	bool jiggle;

public:
	Martian(int,int);
	void jiggleMartian();
};

#endif
