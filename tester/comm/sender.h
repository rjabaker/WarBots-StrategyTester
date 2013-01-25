#ifndef _SENDER_H_
#define _SENDER_H_

#include "../proto/grSim_Packet.pb.h"
#include "../proto/grSim_Commands.pb.h"
#include "../proto/grSim_Replacement.pb.h"

void sendPacket(grSim_Packet* packet);
void Move(double angle, double vel, bool kick, bool isBlue);
void Move(double x, double y, double x1, double y1, double orientation, double vel, bool kick, bool isBlue, int id);

#endif