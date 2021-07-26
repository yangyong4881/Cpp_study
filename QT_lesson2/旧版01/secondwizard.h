#ifndef SECONDWIZARD_H
#define SECONDWIZARD_H

#include <QWizardPage>
#include <QFileDialog>
#include <qfiledialog.h>
#include <QString>
#include <QDebug>
#include <string>


namespace Ui {
class SecondWizard;
}


class SecondWizard : public QWizardPage
{

    Q_OBJECT

public:

    explicit SecondWizard(QWizardPage *parent = 0);


    ~SecondWizard();
    QString str;

private:
     Ui::SecondWizard *ui;


private slots:

//    void button_clicked();


};



#endif // SECONDWIZARD_H



