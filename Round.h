#ifndef ROUND_H
#define ROUND_H
#include "Ship.h"
#include <string>

using namespace std;

class Round {
	int  score;
	int difficulty;
	int health;
public:
	static void CreateRound(int difficulty ,int bulletType);
	static Round* round;
    Ship ship;
	Round(int difficulty);

	//Round();
	~Round();
	char startRound();
  //  bool getSH();
	 void updateScore(int _score);
	 int  getScore();
	 bool isWon;
	 void displayUpdateScore();
	
	 int getHealth();
	 void reduceHealth();
	 int HighScore;
	 int  getHighScore();
	 void setHighScore(int _score);
	 void resetRound();
};
#endif // !1