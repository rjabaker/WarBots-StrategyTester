#ifndef _PLAYERBLUE_H_
#define _PLAYERBLUE_H_

#include "../ai/ai.h"

//all new class names must start with 'Blue'

class BlueSampleStrategy: public Strategy
{
public:
	void implement(Coach *ourCoach);
};

#endif