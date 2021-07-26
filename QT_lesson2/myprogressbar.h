#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QThread>
class myprogressBar
    : public QThread
{
      Q_OBJECT
 public:
     explicit myprogressBar(int Num,QObject *parent = nullptr);

 signals:
     void Sig_ProgressValue(int);
     void Sig_Next();
 protected:
      virtual void run();
     int num;
};

#endif// MYPROGRESSBAR_H
