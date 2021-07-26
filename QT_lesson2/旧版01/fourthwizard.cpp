#include "fourthwizard.h"
#include "ui_fourthwizard.h"
#include <QLabel>
#include<QComboBox>
#include<QPushButton>
#include<QCheckBox>
#include<QStackedWidget>
#include<QLineEdit>
#include<QLabel>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QWidget>

FourthWizard::FourthWizard(QWizardPage *parent):
    QWizardPage(parent),
    ui(new Ui::FourthWizard)

{

    ui->setupUi(this);
//    QLabel *label = new QLabel("激活方式：");
//    QComboBox*combo = new QComboBox(this);
//    combo->setGeometry(50,50,200,30);
//    combo->addItem(tr("序列号"));
//    combo->addItem(tr("登录账号"));
//    QLineEdit *lineEdit = new QLineEdit;
//    lineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
//    QGridLayout *layout2 = new QGridLayout;
//    QLabel* label1 = new QLabel("用户名：");
//    QLabel* label2 = new QLabel("密码：");
//    QLineEdit *lineEdit1 = new QLineEdit;
//    QLineEdit *lineEdit2 = new QLineEdit;
//    layout2->addWidget(label1,0,0);
//    layout2->addWidget(lineEdit1,0,1);
//    layout2->addWidget(label2,1,0);
//    layout2->addWidget(lineEdit2,1,1);
//    QWidget *widget2 = new QWidget;
//    widget2->setLayout(layout2);
//    QPushButton *pushButton = new QPushButton("激活");
//    QCheckBox *checkBox = new QCheckBox("跳过");
//    QStackedWidget *stackWidget = new QStackedWidget;
//    stackWidget->addWidget(lineEdit);
//    stackWidget->addWidget(widget2);
////    stackWidget->addWidget(lineEdit);
////    stackWidget->addWidget(widget2);
//    connect(combo,&QComboBox::currentIndex,this,&FourthWizard::switchPage);
//    QHBoxLayout *layout1 = new QHBoxLayout;
//    layout1->addWidget(label);
//    layout1->addWidget(combo);
//    QWidget *widget1 = new QWidget;
//    widget1->setLayout(layout1);
//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(widget1,0,0,1,5);
//    layout->addWidget(stackWidget,1,0,1,5);
////    layout->addWidget(lineEdit,1,0,1,5);
////    //layout->addWidget(widget2,1,0,1,5);
//    layout->addWidget(pushButton,2,0,1,1);
//    layout->addWidget(checkBox,3,4);
//    this->setLayout(layout);
    ui->lineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(switchPage()));
}


FourthWizard::~FourthWizard()
{
    delete ui;
}

void FourthWizard::switchPage()
{
    if(ui->comboBox->currentIndex() == 0){
        ui->stackedWidget->setCurrentIndex(0);
    }else{
        ui->stackedWidget->setCurrentIndex(1);
    }
}
