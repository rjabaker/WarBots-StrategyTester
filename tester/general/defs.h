#ifndef _GENERAL_H_
#define _GENERAL_H_

#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"
#include "../comm/sender.h"

#include <vector>

//movable objects (ball, robot)
//has x, y parts of position and velocity
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

//robot class
//movable with addtional info on robotID and orientation
class Robot: public Movable
{
public:
	unsigned int id;
	double orientation;
	Robot(unsigned int id, double orientation, double pos_x, double pos_y);

	double angleTo(double x, double y);
	double distanceTo(double x, double y);
	void Move(double angle, double moveVelocity, double kickVelocity, bool isBlue);
	void Move(double target_x, double target_y, double moveVelocity, double kickVelocity, bool isBlue);
	void Stop(bool isBlue);
	bool FaceToward(double target_x, double target_y, double kickVelocity, bool isBlue);
	void Rotate(double angle, double kickVelocity, bool isBlue);
};

//class for the coach to store additional info
//derived from detection packets that aren't
//present in the detection packets themselves
class FieldState
{
public:
	Movable ball;
	std::vector<Robot> bBots;
	std::vector<Robot> yBots;
	FieldState();
};

//game specific setting, contains:
//limits on number of player controled robots
//arbitary function to do initial setup (invoked once at start)
//arbitary function to do repeated setup (invoked every iteration)
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