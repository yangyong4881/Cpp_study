#include "firstwizard.h"
#include "ui_firstwizard.h"
#include <QLabel>
#include<QDebug>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QCheckBox>
FirstWizard::FirstWizard(QWizardPage *parent) :
    QWizardPage(parent),
    ui(new Ui::FirstWizard)

{
    ui->setupUi(this);
//   QTextEdit *textEdit = new QTextEdit("用户安全协议");
//    QCheckBox *checkBox = new QCheckBox("我已阅读用户保护协议，并同意这份协议");
//    checkBox->setCheckable(true);
//    checkBox->setChecked(false);
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(textEdit);
//    layout->addWidget(checkBox);
//    this->setLayout(layout);
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&FirstWizard::completeChanged);
}


FirstWizard::~FirstWizard()
{
    delete ui;
}


bool FirstWizard::isComplete() const
{

    if (!ui->checkBox->isChecked())
    {
        return false;
    }
    else{
        return true;
    }
}


