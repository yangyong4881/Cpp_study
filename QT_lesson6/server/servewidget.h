#ifndef SERVEWIDGET_H
#define SERVEWIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>

namespace Ui {
class ServeWidget;
}

class ServeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServeWidget(QWidget *parent = 0);
    ~ServeWidget();
    void start();
private slots:
    void on_ButtonSend_clicked();

private:
    Ui::ServeWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};

#endif // SERVEWIDGET_H
