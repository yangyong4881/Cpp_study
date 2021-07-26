#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QThread>
class mylistWidget: public QThread
{
    Q_OBJECT
public:
   explicit mylistWidget(int Num,QObject *parent = nullptr);

signals:
    void Sig_ProgressValue(int);
protected:
     virtual void run();
     int num;
};

#endif // MYLISTWIDGET_H

