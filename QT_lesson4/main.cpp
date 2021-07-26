#include "dialog.h"

#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load(":/QT_lesson4.qm", a.applicationDirPath());
    a.installTranslator(&qtTranslator);

    Dialog w;
    w.show();
    return a.exec();
}
