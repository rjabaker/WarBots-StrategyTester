#include "ai.h"
#include <cmath>

//globals
extern int numBBots;
extern int numYBots;

//forward declarations
void bluePlayerAnalysis(Coach *ourCoach);
void yellowPlayerAnalysis(Coach *ourCoach);

Coach::Coach(bool isBlue)
{
	_teamBlue = isBlue;
	strategy = NULL;
}

Coach::~Coach()
{
	if(strategy) delete strategy;
}

BlueCoach::BlueCoach()
	: Coach(true)
{}

YellowCoach::YellowCoach()
	: Coach(false)
{}

void Coach::Analysis(){
	if(_teamBlue) bluePlayerAnalysis(this);
	else yellowPlayerAnalysis(this);
}

void BlueCoach::Analysis()
{
	bluePlayerAnalysis(this);
}

void YellowCoach::Analysis()
{
	yellowPlayerAnalysis(this);
}

bool Coach::teamBlue()
{
	return _teamBlue;
}

const std::vector<SSL_DetectionFrame>* Coach::memory()
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
		fs.bBots.clear();
		fs.yBots.clear();
		fs.ball = Movable(newFrame.balls(0).x(), newFrame.balls(0).y(), 0, 0);	//velocity calculated in analysis

		for(int i = 0; i < _memory[4].robots_blue_size(); i++)
		{
			fs.bBots.push_back(Robot(_memory[4].robots_blue(i).robot_id(), 
									 _memory[4].robots_blue(i).orientation(), 
									 _memory[4].robots_blue(i).x(), 
									 _memory[4].robots_blue(i).y()));
		}
		for(int i = 0; i < _memory[4].robots_yellow_size(); i++)
		{
			fs.yBots.push_back(Robot(_memory[4].robots_yellow(i).robot_id(), 
									 _memory[4].robots_yellow(i).orientation(), 
									 _memory[4].robots_yellow(i).x(), 
									 _memory[4].robots_yellow(i).y()));
		}

		//printDetectionFrame(&_memory[4], "from Coach::Update");

		//call analysis to update velocity
		Analysis();
	}
}

void Strategy::implement(Coach *ourCoach)
{
	//abstract class to be derived
}