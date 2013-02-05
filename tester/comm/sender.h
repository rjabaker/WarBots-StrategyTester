#ifndef _SENDER_H_
#define _SENDER_H_

#include "../proto/grSim_Packet.pb.h"
#include "../proto/grSim_Commands.pb.h"
#include "../proto/grSim_Replacement.pb.h"

void sendPacket(grSim_Packet* packet);		//sends a grSim command packet

//move a robot based on angle and wanted velocity, on/off kicker setting
void sendMove(double angle, double vel, double kickVel, bool isBlue, int id);

//move robot id with some orientation of a team from (x,y) to (x1,y1), on/off kicker setting
void sendMove(double x, double y, double x1, double y1, double orientation, double vel, double kickVel, bool isBlue, int id);

#endif