#include <cmath>
#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"
#include "../proto/grSim_Packet.pb.h"
#include "../proto/grSim_Commands.pb.h"
#include "../proto/grSim_Replacement.pb.h"
#include "netraw.h"

void sendPacket(grSim_Packet packet){
    std::string s;
    packet.SerializeToString(&s);
    Net::UDP udpsocket;
    Net::Address _addr;
    _addr.setHost("127.0.0.1",20011);
    udpsocket.open();
    udpsocket.send((void*) s.c_str(), s.length(), _addr);
}

void Move(float angle, float vel){
    float velT = cos(angle) * vel;
    float velN = sin(angle) * vel;

    grSim_Packet packet;    

    packet.mutable_commands()->set_isteamyellow(true);
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
    command->set_kickspeedx(0);
    command->set_kickspeedz(0);
    command->set_spinner(true);

    sendPacket(packet);
}