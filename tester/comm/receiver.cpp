/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtNetwork>
#include <cstring>
#include <cmath>

#include "receiver.h"

#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"
#include "../proto/grSim_Packet.pb.h"
#include "../proto/grSim_Commands.pb.h"
#include "../proto/grSim_Replacement.pb.h"

#include "../ai/ai.h"

//globals
extern Coach blueCoach;
extern Coach yellowCoach;

Receiver::Receiver(QWidget *parent)
 : QDialog(parent)
{
    groupAddress = QHostAddress("224.5.23.2");        //grSim
    //groupAddress = QHostAddress("224.5.23.1");          //RefBox

    statusLabel = new QLabel(tr("Listening for multicasted messages"));
    quitButton = new QPushButton(tr("&Quit"));

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(10020, QUdpSocket::ShareAddress);     //grSim
    //udpSocket->bind(10001, QUdpSocket::ShareAddress);       //RefBox
    udpSocket->joinMulticastGroup(groupAddress);

    connect(udpSocket, SIGNAL(readyRead()),
         this, SLOT(processPendingDatagrams()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Multicast Receiver"));
}

void Receiver::processPendingDatagrams()
{
    SSL_WrapperPacket packet;
    SSL_GeometryFieldSize packetField;
    SSL_GeometryData packetGeo;
    SSL_DetectionFrame packetFrame;
    SSL_DetectionBall ball;
    std::string message;

    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram.data(), datagram.size());
    statusLabel->setText(tr("Received datagram: \"%1\"")
                      .arg(datagram.data()));


    message = std::string(datagram.data(), datagram.size());

    int mode = packet.ParseFromString(message);

    packetFrame = packet.detection();


    blueCoach.update(packetFrame);
    yellowCoach.update(packetFrame);

/*
    packetGeo = packet.geometry();
    packetField = packetGeo.field();
    printf("\nParse status: %d",mode);
    printf("\nNumber of b: %d",packetFrame.balls_size());
    printf("\nNumber of yellow: %d",packetFrame.robots_yellow_size());
    printf("\nNumber of blue: %d",packetFrame.robots_blue_size());
    printf("\nfield length: %d",packetField.field_length());
    printf("\nfield width: %d",packetField.field_width());
    printf("\nTimestamp: %f\n",packetFrame.t_sent());

    if(packetFrame.balls_size() > 0){
        ball = packetFrame.balls(0);
        float x = ball.x();
        float y = ball.y();
        float z = ball.z();
        printf("x: %f, y: %f, z: %f\n",x,y,z);
    }
*/

}
