#ifndef UDP_S_H
#define UDP_S_H

#include <QtCore/qglobal.h>
#include<QtNetwork/QUdpSocket>

class UDP_S
{
public:
  UDP_S();


public:
  explicit UDP_S(QObject * parent =0 );
  void  sayHello();

 signals:

public slots:
  void readyRead();

private:




};

#endif // UDP_S_H
