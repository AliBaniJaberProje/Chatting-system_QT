#include "my_udp.h"
#include<QUdpSocket>
#include<QHostAddress>
#include<QByteArray>
#include"mainwindow.h"

MY_UDP::MY_UDP(QObject *parent)
  : QObject(parent)
{

//  socket  = new QUdpSocket(this);
//  srcip=new QHostAddress(wind->getIp_src());
//  socket->bind(srcip,7777);
//  connect(socket ,SIGNAL(readyRead()),this,SLOT(readyRead()));


}


//void MY_UDP::SayHello()
//{
//  QByteArray data ;
//  data.append("hello Ali ");
//  socket->writeDatagram(data,QHostAddress::LocalHost,7777);


//}

//void MY_UDP::readyRead()
//{
//  QByteArray buffer ;
//  buffer.resize(socket->pendingDatagramSize());
//  QHostAddress sender ;
//  quint16 senderPost;
//  socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPost);

//  qDebug() <<"message from "<<sender.toString();
//  qDebug()<<"message port " <<senderPost;
//  qDebug()<<"message "<<buffer;
//}

