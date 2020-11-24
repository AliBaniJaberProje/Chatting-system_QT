#ifndef MY_UDP_H
#define MY_UDP_H

#include <QtCore/qglobal.h>
#include<QtNetwork/QUdpSocket>
#include"mainwindow.h"
class MY_UDP : public QObject
{
  Q_OBJECT
public:
  explicit MY_UDP(QObject *parent = 0);
 // void SayHello();
signals:

public slots:
 // void readyRead();

public:
  QUdpSocket *socket;
  MainWindow * wind ;
  QHostAddress *srcip;

};

#endif // MY_UDP_H
