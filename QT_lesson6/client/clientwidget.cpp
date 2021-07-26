#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
#include <QDebug>
#include<QDateTime>
#include<QByteArray>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = NULL;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
                 ui->textEditRead->setText("成功连接服务器！");
            });
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_info()));
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::recv_info()
{
    QString recv_buff = tcpSocket->readAll();
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textEditRead->append(time + "receive");
    ui->textEditRead->append(recv_buff);
}


void ClientWidget::on_buttonConnect_clicked()
{
    QString ip = ui->lineEdit->text();
    qint16  port = ui->lineEdit_2->text().toUInt();
    tcpSocket->connectToHost(QHostAddress(ip),port);
}


void ClientWidget::on_buttonSend_clicked()
{
    if(ui->textEditRead->toPlainText()!=""){
         QString str = ui->textEditWrite->toPlainText();
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->textEditRead->append(time + " mySend: ");
        ui->textEditRead->append(str);
        QByteArray buff = str.toUtf8();
        tcpSocket->write(buff);
        ui->textEditWrite->clear();
    }
}

