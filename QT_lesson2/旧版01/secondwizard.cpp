#include "secondwizard.h"

#include "ui_secondwizard.h"
#include <QLabel>
#include<QHBoxLayout>
#include<QRadioButton>
#include<QCheckBox>
#include<QLineEdit>
#include<QPushButton>
#include<QGroupBox>
SecondWizard::SecondWizard(QWizardPage *parent):
    QWizardPage(parent),
    ui(new Ui::SecondWizard)
{

    ui->setupUi(this);
    QRadioButton *radio1 = new QRadioButton("当前用户");
    QRadioButton *radio2 = new QRadioButton("所有用户");
    QCheckBox * checkBox1 = new QCheckBox("关联Doc、XLS、PPT");
    QCheckBox * checkBox2 = new QCheckBox("关联PDF格式");
    QCheckBox * checkBox3 = new QCheckBox("关联PNG、JPG等图片格式");
    QCheckBox * checkBox4 = new QCheckBox("关联EPUBE");
    QLineEdit * line = new QLineEdit;
    QPushButton *pushButton1 = new QPushButton("安装位置");
    connect(pushButton1,&QPushButton::clicked,[=](){
        QString str=QFileDialog::getExistingDirectory(this,"打开文件","./");
        line->setText(str);
        });

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(radio1);
    layout1->addWidget(radio2);
    radio1->setChecked(true);
    QGroupBox * groupBox1 = new QGroupBox("用户");
    groupBox1->setLayout(layout1);
    QGridLayout *layout2 = new QGridLayout;
    layout2->addWidget(checkBox1,0,0);
    layout2->addWidget(checkBox2,0,1);
    layout2->addWidget(checkBox3,1,0);
    layout2->addWidget(checkBox4,1,1);
    layout2->addWidget(line,2,0);
    layout2->addWidget(pushButton1,2,1);
    QGroupBox * groupBox2 = new QGroupBox("兼容性");
    groupBox2->setLayout(layout2);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(groupBox1);
    layout->addWidget(groupBox2);
    this->setLayout(layout);
}

SecondWizard::~SecondWizard()
{
    delete ui;

}
