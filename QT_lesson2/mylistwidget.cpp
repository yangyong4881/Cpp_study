#include "mylistwidget.h"

mylistWidget::mylistWidget(int Num,QObject *parent)
    :QThread(parent)
{
    num = Num;
}
void mylistWidget::run()
{
    for(int i = 0; i < num; i++)
    {
        emit Sig_ProgressValue(i);
        msleep(200);
    }
}
