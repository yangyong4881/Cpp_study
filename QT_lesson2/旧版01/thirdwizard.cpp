#include "thirdwizard.h"

#include "ui_thirdwizard.h"

#include <QLabel>
#include<QLineEdit>
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QProgressBar>
#include<QListWidget>
ThirdWizard::ThirdWizard(QWizardPage *parent):
    QWizardPage(parent),
    ui(new Ui::ThirdWizard)
{
    ui->setupUi(this);
    QLabel* label1 = new QLabel("安装进度：");
    QLabel* label2 = new QLabel("安装文件列表：");
    QProgressBar *progressBar = new QProgressBar;
    QListWidget * listWidget = new QListWidget;
    QGridLayout* layout1 = new QGridLayout;
    layout1->addWidget(label1,0,0);
    layout1->addWidget(progressBar,0,1);
    QWidget *widget1 = new QWidget;
    widget1->setLayout(layout1);
    layout1->addWidget(listWidget);
    QVBoxLayout* layout2 = new QVBoxLayout;
    layout2->addWidget(label2);
    layout2->addWidget(listWidget);

    QWidget *widget2 = new QWidget;
    widget2->setLayout(layout2);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    this->setLayout(layout);
}


ThirdWizard::~ThirdWizard()
{
    delete ui;
}


