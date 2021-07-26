#include "servewidget.h"
#include "ui_servewidget.h"
#include <QDateTime>
#include<QByteArray>

ServeWidget::ServeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServeWidget)
{
    ui->setupUi(this);
    tcpServer = NULL;
    tcpSocket = NULL;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,[=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();
        QString temp = QString("成功连接");
        ui->textEditRead->setText(temp);
        connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
             QByteArray array = tcpSocket->readAll();
             QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
             ui->textEditRead->append(time + " receive: ");
             ui->textEditRead->append(array);
            } );
    });
    start();
}

ServeWidget::~ServeWidget()
{
    delete ui;
}

void ServeWidget::start()
{
    if(!tcpServer->listen(QHostAddress::Any,8888)){
        close();
        return;
    }
}

void ServeWidget::on_ButtonSend_clicked()
{
    if(ui->textEditWrite->toPlainText()!=" "){
        QString str = ui->textEditWrite->toPlainText();
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->textEditRead->append(time + " mySend: ");
        ui->textEditRead->append(str);

    //tcpSocket->write( str.toUtf8().data() );
        QByteArray buff = str.toUtf8();
        tcpSocket->write(buff);
        ui->textEditWrite->clear();
    }
}
