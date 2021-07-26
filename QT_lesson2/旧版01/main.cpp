#include <QApplication>
#include "mywizard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mywizard w;

    w.show();

    return a.exec();
}
