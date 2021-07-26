#include "myprogressbar.h"

myprogressBar::myprogressBar(int Num, QObject *parent)
    :QThread(parent)
{
    num = Num;
}

void myprogressBar::run()
{
    for(int i = 0; i < num; i++)
    {
        emit Sig_ProgressValue(i);
        msleep(200);
    }
    emit Sig_Next();
}
