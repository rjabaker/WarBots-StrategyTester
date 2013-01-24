#include "ai.h"
#include <cmath>

//globals
extern int numBbots;
extern int numYbots;

Coach::Coach(bool isBlue)
{
	_teamBlue = isBlue;
}

BlueCoach::BlueCoach()
	: Coach(true)
{}

YellowCoach::YellowCoach()
	: Coach(false)
{}

bool Coach::teamBlue()
{
	return _teamBlue;
}

const vector<SSL_DetectionFrame>* Coach::memory()
{
	return &_memory;
}

void Coach::update(SSL_DetectionFrame newFrame)
{
	//update memory
	if(_memory.size() < 5){
		_memory.push_back(newFrame);
	}
	else{
		_memory.push_back(newFrame);
		_memory.erase(_memory.begin());
	
		//update FieldState
		fs.Bbots.clear();
		fs.Ybots.clear();
		fs.ball = Movable(packetFrame.balls(0).x(), packetFrame.balls(0).y(), 0, 0);	//velocity calculated in analysis

		for(int i = 0, i < _memory[4].robots_blue_size(); i++)
		{
			fs.Bbots.push_back(Robot(_memory[4].robots_blue(i).robot_id(), 
									 _memory[4].robots_blue(i).orientation(), 
									 _memory[4].robots_blue(i).x(), 
									 _memory[4].robots_blue(i).y()));
		}
		for(int i = 0; i < _memory[4]._memory[4].robots_yellow_size(); i++)
		{
			fs.Ybots.push_back(Robot(_memory[4].robots_yellow(i).robot_id(), 
									 _memory[4].robots_yellow(i).orientation(), 
									 _memory[4].robots_yellow(i).x(), 
									 _memory[4].robots_yellow(i).y()));
		}

		//call analysis to update velocity
		analysis();
	}
}

void Coach::activateStrategy(Strat *strategy)
{
	strategy->implement();
}

void Strat::implement()
{
	vector<Robot> *ourTeam;
	if(ourCoach->teamBlue())
	{
		ourTeam = &ourCoach->fs.bBots;
	}
	else
	{
		ourTeam = &ourCoach->fs.yBots;
	}

	switch(ourTeam->size())
	{
	case 0:
		break;
	case 1:
		implement_one();
		break;
	case 2:
		implement_two();
		break;
	case 3:
		implement_three();
		break;
	case 4:
		implement_four();
		break;
	case 5:
		implement_five();
		break;
	default:
		break;
	}
}