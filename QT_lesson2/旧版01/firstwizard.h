#ifndef FIRSTWIZARD_H
#define FIRSTWIZARD_H
#include <QWizardPage>
#include<QCheckBox>
namespace Ui {
class FirstWizard;
}


class FirstWizard : public QWizardPage
{

    Q_OBJECT


public:

    explicit FirstWizard(QWizardPage *parent = 0);

    QCheckBox *checkBox;
    bool isComplete() const;

    ~FirstWizard();
    int count = -1;


private:
     Ui::FirstWizard *ui;


};





#endif // FIRSTWIZARD_H
