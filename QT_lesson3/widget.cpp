#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    drawEcllipse(20,20);
//    drawEcllipse(250,20);
//    drawEcllipse(480,20);
//    drawEcllipse(130,120);
//    drawEcllipse(350,120);
    QPainter painter(this);
    painter.setWindow(-170,-250,1000,800);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(20,20,  200, 200);

    painter.setPen(QPen(Qt::yellow, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(130,120,  200, 200);

    painter.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(20,20,200,200,-15*16,30*16);

    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(250,20,  200, 200);

    painter.setPen(QPen(Qt::yellow, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(130,120,200,200,40*16,45*16);

    painter.setPen(QPen(Qt::green, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(350,120,  200, 200);

    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(250,20,200,200,-15*16,30*16);

    painter.setPen(QPen(Qt::red, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(480,20,  200, 200);

    painter.setPen(QPen(Qt::green, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawArc(350,120, 200,200,30*16,50*16);



}

void Widget::drawEcllipse(int x,int y){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(x, y,  200, 200);
}
