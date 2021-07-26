#ifndef MYWIZARD_H
#define MYWIZARD_H

#include <QWizard>

#include "firstwizard.h"
#include "secondwizard.h"
#include "thirdwizard.h"
#include "fourthwizard.h"

class mywizard : public QWizard
{
    Q_OBJECT

public:
    mywizard(QWidget *parent = nullptr);

    ~mywizard()
    {

    }


signals:

private:
    FirstWizard * m_Fw;
    SecondWizard * m_Sw;
    ThirdWizard * m_Tw;
    FourthWizard * m_Fow;


public:
    enum
    {
        Page_First,
        Page_Second,
        Page_Third,
        Page_Fourth
    };

};



















#endif // MYWIZARD_H
