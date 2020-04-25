//  Translated into English 03/2019
//	15/01/2015 version
#define VERSION_H 15012015

#ifndef __GRAPHICALUTILITYCLASS_UIKIT_H
#define __GRAPHICALUTILITYCLASS_UIKIT_H

#include <windows.h>
#include <iostream>
using namespace std;

//	for reference: color constants
//#define FOREGROUND_BLUE      0x0001 // text color contains blue.
//#define FOREGROUND_GREEN     0x0002 // text color contains green.
//#define FOREGROUND_RED       0x0004 // text color contains red.
//#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
//#define BACKGROUND_BLUE      0x0010 // background color contains blue.
//#define BACKGROUND_GREEN     0x0020 // background color contains green.
//#define BACKGROUND_RED       0x0040 // background color contains red.
//#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.

class UIKit {
private:
	static HANDLE handle;
	static bool isPaletteReset;

	static void resetPalette();

public:
	/***********************
	//prototypes
	************************/

	//displays in color
	static void color(unsigned short theColor);

	//positions the cursor
	static void gotoXY(int x, int y);

	//gets the cursor's position
	static char getCharXY(int x, int y);

	//configures the window dimensions
	static void setWindowDimensions(int x1, int y1, int x2, int y2);

	//draws a frame
	static void frame(int cd,int ld,int cf,int lf, unsigned short _color);

	static int whereX();
	static int whereY();
	static void visibleCursor(bool visible);
};
#endif
