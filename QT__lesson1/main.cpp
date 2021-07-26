#include "mainwindow.h"

#include <QApplication>
#include <QTextEdit>
#include <QPushButton>>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QTextEdit* t1 = new QTextEdit(&w);
//    t1->setGeometry(20,100,100,50);


//    QTextEdit* t2 = new QTextEdit(&w);
//    t2->setGeometry(150,100,100,50);


//    QTextEdit* t3 = new QTextEdit(&w);
//    t3->setGeometry(280,100,100,50);
//    QPushButton b;
//    b.setText("calculation");
//    b.setParent(&w);
//    b.setGeometry(410,100,100,50);


    w.show();
    return a.exec();
}
