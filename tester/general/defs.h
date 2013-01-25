#ifndef _GENERAL_H_
#define _GENERAL_H_

#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"

#include <vector>

class Movable
{
public:
	double pos_x;
	double pos_y;
	double speed_x;
	double speed_y;
	Movable(double pos_x, double pos_y, double speed_x, double speed_y);
	Movable();
};

class Robot: public Movable
{
public:
	unsigned int id;
	double orientation;
	Robot(unsigned int id, double orientation, double pos_x, double pos_y);
};

class FieldState
{
public:
	Movable ball;
	std::vector<Robot> bBots;
	std::vector<Robot> yBots;
	FieldState();
};

/*
class GameState
{
public:
	//some form of ENUM
};
*/

class GameSetting
{
public:
	int numBbots;
	int numYbots;
	void initSetting();
	void repeatedSetting();
	GameSetting(int b, int y);
};

#endif