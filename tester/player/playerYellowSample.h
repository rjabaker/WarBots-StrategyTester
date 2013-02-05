#ifndef _PLAYERYELLOW_H_
#define _PLAYERYELLOW_H_

#include "../ai/ai.h"

//all new class names must start with 'Yellow'

class YellowSampleStrategy: public Strategy
{
public:
	void implement(Coach *ourCoach);
};


#endif