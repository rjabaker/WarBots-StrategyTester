#include "defs.h"
#include <cmath>
#include <cstdio>

#define PI 3.1415926

//globals
extern int numBBots;
extern int numYBots;

//settings.cpp
void initGameSetting();
void repeatedGameSetting();

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
	: Movable(pos_x, pos_y, 0.0, 0.0)		//velocity calculated in analysis
{
	this->id = id;
	this->orientation = orientation;
}

double Robot::angleTo(double x, double y)
{
	double abs_x = abs(x);
	double abs_y = abs(y);

	if(x > 0 && y > 0)			//Q1
		return atan(abs_y/abs_x);
	else if(x < 0 && y > 0)		//Q2
		return PI - atan(abs_y/abs_x);
	else if(x < 0 && y < 0)		//Q3
		return -PI + atan(abs_y/abs_x);
	else						//Q4
		return 0 - atan(abs_y/abs_x);
}

double Robot::distanceTo(double x, double y){
	double R = sqrt(pow(pos_x-x,2.0)+pow(pos_y-y,2.0));
	return R;
}

//move based on angle and wanted velocity, on/off kicker setting
void Robot::Move(double angle, double moveVelocity, double kickVelocity, bool isBlue)
{
    if(isBlue)
        if(id > numBBots){ return; }
    else 
        if(id > numYBots){ return; }
	sendMove(angle, moveVelocity, kickVelocity, isBlue, id);
}

//move to (target_x, target_y), on/off kicker setting
void Robot::Move(double target_x, double target_y, double moveVelocity, double kickVelocity, bool isBlue)
{
    if(isBlue)
        if(id > numBBots){ return; }
    else 
        if(id > numYBots){ return; }
	sendMove(pos_x, pos_y, target_x, target_y, orientation, moveVelocity, kickVelocity, isBlue, id);
}

void Robot::Stop(bool isBlue)
{
    if(isBlue)
        if(id > numBBots){ return; }
    else 
        if(id > numYBots){ return; }
	grSim_Packet packet;	
	packet.mutable_commands()->set_isteamyellow(!isBlue);
    packet.mutable_commands()->set_timestamp(0.0);
	grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
	command->set_id(id);
	command->set_wheelsspeed(false);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(0);
    command->set_velnormal(0);
    command->set_velangular(0);
    command->set_kickspeedx(0);
    command->set_kickspeedz(0);
    command->set_spinner(true);
	sendPacket(&packet);
}

bool Robot::FaceToward(double target_x, double target_y, double kickVelocity, bool isBlue)
{
    if(isBlue)
        if(id > numBBots){ return false; }
    else 
        if(id > numYBots){ return false; }

    //printf("angle is %f\n", angleTo(target_x-pos_x, target_y-pos_y));

    double angle = angleTo(target_x-pos_x, target_y-pos_y);
    double threshold = PI / 9.0;

    printf("orientation %f, angle %f, absdiff %f, threshold %f\n",
    		orientation, angle, fabs(orientation-angle), threshold);

	if( fabs(orientation-angle) < threshold) 
	{
		Stop(isBlue);
		return true;
	}

    Rotate(angle, kickVelocity, isBlue);
    return false;
}

void Robot::Rotate(double angle, double kickVelocity, bool isBlue)
{
    if(isBlue)
        if(id > numBBots){ return; }
    else 
        if(id > numYBots){ return; }

	double velA;
	if((angle-orientation) > 0)
		velA = 2.0;
	else
		velA = -2.0;

	grSim_Packet packet;	
	packet.mutable_commands()->set_isteamyellow(!isBlue);
    packet.mutable_commands()->set_timestamp(0.0);
	grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
	command->set_id(id);
	command->set_wheelsspeed(false);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(0);
    command->set_velnormal(0);
    command->set_velangular(velA);
    command->set_kickspeedx(kickVelocity);
    command->set_kickspeedz(0);
    command->set_spinner(true);

	sendPacket(&packet);
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

void GameSetting::initSetting()
{
	//game specific
	initGameSetting();
}

void GameSetting::repeatedSetting()
{
	//game specific
	repeatedGameSetting();
}
