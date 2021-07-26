#include "widget.h"

#include <QApplication>
#include "wizard.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wizard dlg;
    dlg.show();
    return a.exec();
}
