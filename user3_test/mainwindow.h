#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include<QTimer>
#include<QString>
#include<QUdpSocket>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  void SayHello();
  ~MainWindow();

protected:
  void changeEvent(QEvent *e);

private slots:
  void on_login_clicked();

  void on_send_file_clicked();
  void mytimer();
  //void

  void on_send_msg_clicked();

  void on_login_2_clicked();

public slots:
  void readyRead();


public:
  Ui::MainWindow *ui;
  QTimer * timer;
 // QString getIp_src();
  QUdpSocket *socket;
 QUdpSocket *socket2;
  QTimer *timeout;
  void resever();
void sendfile(QString data1);
  QUdpSocket * clientSocket;
  QUdpSocket * recever ;
   QUdpSocket * WW2;
  quint16  srcport;
  quint16 destport;
   QHostAddress srcIP;
   QHostAddress destIP;
   QString chek="*";
   QString chek2;


 // QMessageBox msgBox;


  quint16 serverPort;

  QHostAddress clientIP;
  quint16 clientPort;

  QByteArray  *ABQofFiles;

QString file_name ;


};

#endif // MAINWINDOW_H
