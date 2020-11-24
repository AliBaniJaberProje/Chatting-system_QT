#ifndef USER2_H
#define USER2_H
#include<QMessageBox>
#include<QDir>
#include<QUdpSocket>
#include<QFileDialog>
#include<QString>
#include<QDateTime>
#include"mainwindow.h"
#include <QtCore/qglobal.h>

class user2
{
public:
  user2();
  void send_data();
  void resevd_data();
  QUdpSocket *socket_send;



};

#endif // USER2_H
