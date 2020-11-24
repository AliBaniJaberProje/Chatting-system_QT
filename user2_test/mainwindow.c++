#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDir>
#include<QUdpSocket>
#include<QFileDialog>
#include<QString>
#include<QDateTime>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{  ui->setupUi(this);
  ui->port_dest->setText("7575");
  ui->port_src->setText("8585");
  ui->ip_dest->setText("192.168.0.102");
  ui->ip_src->setText("192.168.0.102");
   ui->msg->setMaxLength(40);

  timer =new QTimer(this);

  timer->start(1000);
  QDir dir("Desktop");
  foreach (QFileInfo var, dir.drives()) {
      ui->comboBox->addItem(var.absoluteFilePath());
    }
  socket  = new QUdpSocket(this);
  recever =new QUdpSocket(this);
 // WW2 = new QUdpSocket(this);
 connect(socket ,SIGNAL(readyRead()),this,SLOT(readyRead()));





}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
    }
}

void MainWindow::on_login_clicked()
{

  srcIP =QHostAddress(ui->ip_src->text());
  destIP =QHostAddress(ui->ip_dest->text());
  srcport = ui->port_src->text().toUShort();
  destport=ui->port_dest->text().toUShort();

     this->socket->bind(srcIP,srcport);
  //recever->bind(/*QHostAddress::LocalHost*/srcIP, srcport);
  connect(socket ,SIGNAL(readyRead()),this,SLOT(readyRead()));

   ui->statusBar->showMessage("Communication between"+ui->ip_src->text() + "and " +ui->ip_dest->text(),500000);
}

void MainWindow::on_send_file_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this, "open a file", "c://");
    QMessageBox::information(this,"..",file_name);
    QString msg = ui->ip_dest->text();
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "error","error");

      }
    QTextStream in(&file);
    QString text=in.readAll();
    sendfile(text);
    file.close();
    SayHello();

}

void MainWindow::mytimer()
{
  QTime time =QTime::currentTime();
  QString text_string=time.toString("hh : mm : ss");
  ui->time->setText(text_string);
}

void MainWindow::SayHello()
{
  QByteArray data ;
  data.append(ui->msg->text());
  ui->chat->append("me:"+data);
  socket->writeDatagram(data,destIP,destport);

}
void MainWindow::sendfile(QString data1)
{
  QByteArray data ;

  data.append(data1);
  for(int i=0;i<40;i++)
    {
      data.append(" ");
    }
  QString rr="me:file"+file_name;

  ui->chat->append(rr);
  socket->writeDatagram(data,destIP,destport);

}

void MainWindow::readyRead()
{
  QByteArray buffer ;
  buffer.resize(socket->pendingDatagramSize());
  QHostAddress sender ;
  quint16 senderPost;
  socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPost);
  if(buffer.length()>40){
    //  ui->chat->append("the file in path:");
      QFile file("D:/MSI/Desktop/ALIHOWNEWTWORK/myfile1.txt");
      if(!file.open((QFile::WriteOnly | QFile::Text))){
          //QMessageBox::Warning(this,"ERROR","ERROR");
        }
      QTextStream out(&file);

      out<<buffer;
      file.flush();
      file.close();
      ui->chat->append("Ali : the file in path:D:\MSI\Desktop\ALIHOWNEWTWORK\myfile1.txt");
    }
 else{
  ui->chat->append("Ali:"+ buffer);
  qDebug() <<"message from "<<sender.toString();
  qDebug()<<"message port " <<senderPost;
  qDebug()<<"message "<<buffer;
    }

}

void MainWindow::resever()
{
  this->readyRead();

}


void MainWindow::on_send_msg_clicked()
{
     SayHello();
}

void MainWindow::on_login_2_clicked()
{


}
