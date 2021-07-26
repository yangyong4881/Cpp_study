#ifndef FOURTHWIZARD_H
#define FOURTHWIZARD_H
#include <QWizardPage>
#include<QStackedWidget>

namespace Ui {
class FourthWizard;
}

class FourthWizard: public QWizardPage
{
    Q_OBJECT

public:
    explicit  FourthWizard(QWizardPage *parent = 0);
    ~FourthWizard();

private slots:

    void switchPage();

private:
     Ui::FourthWizard *ui;
//     QStackedWidget *stackWidget;


};

#endif // FOURTHWIZARD_H
