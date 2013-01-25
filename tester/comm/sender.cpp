#include <cmath>
#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"
#include "../proto/grSim_Packet.pb.h"
#include "../proto/grSim_Commands.pb.h"
#include "../proto/grSim_Replacement.pb.h"
#include "netraw.h"
#include "sender.h"

extern int numBBots;
extern int numYBots;

#define PI 3.1415926

void sendPacket(grSim_Packet* packet){
    std::string s;
    packet->SerializeToString(&s);
    Net::UDP udpsocket;
    Net::Address _addr;
    _addr.setHost("127.0.0.1",20011);
    udpsocket.open();
    udpsocket.send((void*) s.c_str(), s.length(), _addr);
}

void Move(double angle, double vel, bool kick, bool isBlue){
    double velT = cos(angle) * vel;
    double velN = sin(angle) * vel;

    double velK = 0;
    if(kick) velK = 2.0;

    grSim_Packet packet;    

    packet.mutable_commands()->set_isteamyellow(!isBlue);
    packet.mutable_commands()->set_timestamp(1.0);
    grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
    command->set_id(1);
    command->set_wheelsspeed(false);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(velT);
    command->set_velnormal(velN);
    command->set_velangular(0);
    command->set_kickspeedx(velK);
    command->set_kickspeedz(0);
    command->set_spinner(true);

    sendPacket(&packet);
}

void Move(double x, double y, double x1, double y1, double orientation, double vel, bool kick, bool isBlue, int id){
    if(isBlue)
    {
        if(id > numBBots){ return; }
    } 
    else 
    { 
        if(id > numYBots){ return; }
    }

    double velT;
    double velN;
    double yDiff= y1-y;
    double xDiff= x1-x;
    double angle = 9999999;
    double R = sqrt((yDiff*yDiff)+(xDiff*xDiff));

    double velK = 0;
    if(kick) velK = 2.0;

    if(R > 25){
        angle = acos(xDiff/R);
        if(yDiff < 0)
            angle = 2*PI - angle;
        angle -= orientation;
        if(angle < 0)
            angle = 2*PI + angle;

        double new_xDiff = R*cos(angle);
        double new_yDiff = R*sin(angle);

        double e;
        e = std::max(abs(new_xDiff),abs(new_yDiff));

        velT = (new_xDiff/e)*vel;
        velN = (new_yDiff/e)*vel;
    }
    else{
        velT = 0;
        velN = 0;
        R = 9999999;
    }
    if(R > 25 && R < 200){
        velT *= R/200.0;
        velN *= R/200.0;
    }
    printf("\nVelT is %f, VelN is %f, R is %f, angle is %f, x is %f, y is %f",velT,velN,R,angle,x1,y1);

    grSim_Packet packet;    

    packet.mutable_commands()->set_isteamyellow(!isBlue);
    packet.mutable_commands()->set_timestamp(1.0);
    grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
    command->set_id(id);
    command->set_wheelsspeed(false);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(velT);
    command->set_velnormal(velN);
    command->set_velangular(0);
    command->set_kickspeedx(velK);
    command->set_kickspeedz(0);
    command->set_spinner(true);

    sendPacket(&packet);
}