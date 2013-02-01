#include "ai.h"
#include <cmath>

//globals
extern int numBBots;
extern int numYBots;

//forward declarations
void bluePlayerAnalysis(Coach *ourCoach);
void bluePlayerImplementOneRobot(Coach *ourCoach);
void bluePlayerImplementTwoRobot(Coach *ourCoach);
void bluePlayerImplementThreeRobot(Coach *ourCoach);
void bluePlayerImplementFourRobot(Coach *ourCoach);
void bluePlayerImplementFiveRobot(Coach *ourCoach);
void yellowPlayerAnalysis(Coach *ourCoach);
void yellowPlayerImplementOneRobot(Coach *ourCoach);
void yellowPlayerImplementTwoRobot(Coach *ourCoach);
void yellowPlayerImplementThreeRobot(Coach *ourCoach);
void yellowPlayerImplementFourRobot(Coach *ourCoach);
void yellowPlayerImplementFiveRobot(Coach *ourCoach);

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

		printDetectionFrame(&_memory[4], "from Coach::Update");

		//call analysis to update velocity
		Analysis();
	}
}

void Strategy::implement(Coach *ourCoach)
{
	if(ourCoach->teamBlue()){
		switch(ourCoach->fs.bBots.size()){
		case 0:
			//no robots =(
			break;
		case 1:
			bluePlayerImplementOneRobot(ourCoach);
			break;
		case 2:
			bluePlayerImplementTwoRobot(ourCoach);
			break;
		case 3:
			bluePlayerImplementThreeRobot(ourCoach);
			break;
		case 4:
			bluePlayerImplementFourRobot(ourCoach);
			break;
		case 5:
			bluePlayerImplementFiveRobot(ourCoach);
			break;
		default:
			break;
		}
	}
	else{
		switch(ourCoach->fs.bBots.size()){
		case 0:
			//no robots =(
			break;
		case 1:
			yellowPlayerImplementOneRobot(ourCoach);
			break;
		case 2:
			yellowPlayerImplementTwoRobot(ourCoach);
			break;
		case 3:
			yellowPlayerImplementThreeRobot(ourCoach);
			break;
		case 4:
			yellowPlayerImplementFourRobot(ourCoach);
			break;
		case 5:
			yellowPlayerImplementFiveRobot(ourCoach);
			break;
		default:
			break;
		}
	}
}

