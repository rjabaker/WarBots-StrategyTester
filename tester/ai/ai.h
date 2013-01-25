#ifndef _AI_H_
#define _AI_H_

#include "../general/defs.h"

class Strategy;

//decision AI
class Coach
{
	bool _teamBlue;
	std::vector<SSL_DetectionFrame> _memory;
public:
	FieldState fs;
	bool teamBlue();
	const std::vector<SSL_DetectionFrame>* memory();
	void update(SSL_DetectionFrame newFrame);
	virtual void Analysis();
	Coach(bool isBlue);
};

class BlueCoach: public Coach{
public:
	void Analysis();
	BlueCoach();
};

class YellowCoach: public Coach{
public:
	void Analysis();
	YellowCoach();
};

//implementation AI
class Strategy
{
public:
	void implement(Coach *ourCoach);
};

#endif