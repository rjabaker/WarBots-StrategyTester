#ifndef _AI_H_
#define _AI_H_

#include "../general/defs.h"
#include "../general/debug.h"

class Strategy;

//decision AI
class Coach
{
	bool _teamBlue;										//if the coach is for team blue
	std::vector<SSL_DetectionFrame> _memory;			//coach memory (five latest frames)
public:
	FieldState fs;										//coach analysis of the field
	bool teamBlue();
	const std::vector<SSL_DetectionFrame>* memory();	//returns _memory
	Coach(bool isBlue);									//returns _isBlue
	void update(SSL_DetectionFrame newFrame);			//update memory with detection frame
	virtual void Analysis();							//setup fieldstate with info in memory

};

//blue team coach
//needed since we need multiple definitions of Analysis
class BlueCoach: public Coach{
public:
	void Analysis();
	BlueCoach();
};

//yellow team coach
//needed since we need multiple definitions of Analysis
class YellowCoach: public Coach{
public:
	void Analysis();
	YellowCoach();
};

//implementation AI
class Strategy
{
public:
	void implement(Coach *ourCoach);					//calls the player's implementation
};

#endif