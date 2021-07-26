#include "servewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServeWidget w;
    w.show();

    return a.exec();
}
