#include <iostream>
#include "Round.h"
#include "UIKit.h"
#include "Bullet.h"
#include <dos.h> 
#include "Extraterrestrial.h"
#include <string>
#include <conio.h>
#include <ctype.h>
using namespace std;


int main() 
{

	int type; char choice='c';
	system("mode 650");
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t######  ######   ####   #######  ######     ##########  #       #  #          #   ####   #######    #######  ######  "<< endl;
	cout << "\t\t\t\t\t\t\t#       #    #  #    #  #        #              #       # #     #  #          #  #    #   #      #  #        #     #  " << endl;
	cout << "\t\t\t\t\t\t\t#       #    #  #    #  #        #              #       #   #   #   #        #   #    #   #      #  #        #     #  " << endl;
	cout << "\t\t\t\t\t\t\t######  ######  ######  #        ######         #       #    #  #    #      #    ######   #      #  ######   ######     " << endl;
	cout << "\t\t\t\t\t\t\t     #  #       #    #  #        #              #       #     # #     #    #     #    #   #      #  #        #     #     " << endl;
	cout << "\t\t\t\t\t\t\t     #  #       #    #  #        #              #       #       #      #  #      #    #   #      #  #        #      #   " << endl;
	cout << "\t\t\t\t\t\t\t######  #       #    #  #######  ######     ##########  #       #       #        #    #  #######    #######  #       #    " << endl;
	
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDesigned by : C.B.J.K ";
	Sleep(5000);

	
	
	choice:cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tType of bullets" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t(1) | " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t(2) *  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t Select bullet type :"; cin >> type; 
	if (type == 1 || type == 2) {}
	else
	{
		cout << "Invalid bullet type.. try again!" << endl;
		system("cls");
		goto choice;
	}
	system("cls");
	
	

	
	
	Round::CreateRound(1, type);

	while (choice == 'c')
	{

		
		UIKit::frame(40, 7, 170,35, 10);
		choice = Round::round->startRound();
		if (choice == 'c')
		{
			system("cls");
			if (Round::round->getScore() > Round::round->getHighScore())
			{
				Round::round->setHighScore(Round::round->getScore());
				
			}


		}
	}
	
	return 0;
}

