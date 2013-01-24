#ifndef _AI_H_
#define _AI_H_

#include "../general/defs.h"

//decision AI
class Coach
{
	bool _teamBlue;
	vector<SSL_DetectionFrame> _memory;
public:
	FieldState fs;
	bool teamBlue();
	const vector<SSL_DetectionFrame>* memory();
	void update(SSL_DetectionFrame newFrame);
	void analysis();
	void activateStrategy(Strat *strategy);

	Coach(bool isBlue);
};

class BlueCoach: public Coach{
public:
	BlueCoach();
};

class YellowCoach: public Coach{
public:
	YellowCoach();
};

//implementation AI
class Strat
{
public:
	Coach *ourCoach;
	void implement();
	virtual void implement_one();
	virtual void implement_two();
	virtual void implement_three();
	virtual void implement_four();
	virtual void implement_five();
	//virtual void implement_six();
};

//base AI
//robot class now acted onboard

#endif