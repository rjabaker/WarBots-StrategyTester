#include "defs.h"

//globals
extern int numBBots;
extern int numYBots;

Movable::Movable()
{
	this->pos_x = 0;
	this->pos_y = 0;
	this->speed_x = 0;
	this->speed_y = 0;
}

Movable::Movable(double pos_x, double pos_y, double speed_x, double speed_y)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}

Robot::Robot(unsigned int id, double orientation, double pos_x, double pos_y)
	: Movable(pos_x, pos_y, 0.0, 0.0)		//initalize with zero velocity, velocity calculated in analysis
{
	this->id = id;
	this->orientation = orientation;
}

FieldState::FieldState()
{
	//nothing to do yet
}

GameSetting::GameSetting(int b, int y)
{
	numBBots = b;
	numYBots = y;
}