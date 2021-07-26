#ifndef THIRDWIZARD_H
#define THIRDWIZARD_H


#include <QWizardPage>
#include <QWizardPage>
#include <QFileDialog>
#include <qfiledialog.h>
#include <qstring.h>
#include <QDebug>
namespace Ui {
class ThirdWizard;
}

class ThirdWizard : public QWizardPage
{

    Q_OBJECT

public:
    explicit ThirdWizard(QWizardPage *parent = 0);
    ~ThirdWizard();


private:
     Ui::ThirdWizard *ui;


};

#endif // THIRDWIZARD_H
