#include "wizard.h"
#include "ui_wizard.h"
#include<QFileDialog>
#include<myprogressbar.h>
#include<mylistwidget.h>
#include<QDebug>
Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
    //page1
    connect(ui->checkBox_2, SIGNAL(toggled(bool)), this, SLOT(slot_checkbox()));
    connect(ui->checkBox_2, SIGNAL(toggled(bool)), ui->wizardPage, SIGNAL(completeChanged()));

    //page2
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        str=QFileDialog::getExistingDirectory(this,"打开文件","./");
        ui->lineEdit->setText(str);
        });
    connect(ui->radioButton_2, SIGNAL(toggled(bool)), this, SLOT(slot_radioButton_2()));
    connect(ui->radioButton_2, SIGNAL(toggled(bool)), ui->wizardPage1, SIGNAL(completeChanged()));
    connect(ui->radioButton, SIGNAL(toggled(bool)), this, SLOT(slot_radioButton()));
    connect(ui->radioButton, SIGNAL(toggled(bool)), ui->wizardPage1, SIGNAL(completeChanged()));

    //page3

    //page4
    ui->lineEdit_5->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(slot_switchPage()));
    connect(ui->comboBox, SIGNAL(activated(int)), ui->wizardPage3, SIGNAL(completeChanged()));
    //按跳过则可点击完成
    connect(ui->checkBox, SIGNAL(toggled(bool)), this, SLOT(slot_checkbox1()));
    connect(ui->checkBox, &QCheckBox::stateChanged, ui->wizardPage3, &mywizardPage::completeChanged);
    //按激活则可点击完成
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(slot_pushButton()));
    connect(ui->pushButton_2, &QPushButton::clicked, ui->wizardPage3, &mywizardPage::completeChanged);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::slot_progressBar()
{
    ui->wizardPage2->SetNextEnable(true);
}


void Wizard::slot_checkbox()
{
    ui->wizardPage->SetNextEnable(ui->checkBox_2->isChecked());
}
void Wizard::slot_checkbox1()
{
    ui->wizardPage3->SetNextEnable(ui->checkBox->isChecked());
}

void Wizard::slot_radioButton_2()
{
    ui->wizardPage1->SetNextEnable(ui->radioButton_2->isChecked());
}
void Wizard::slot_radioButton()
{
    ui->wizardPage1->SetNextEnable(ui->radioButton->isChecked());
}
void Wizard::slot_pushButton()
{
    ui->wizardPage3->SetNextEnable(true);
}

void Wizard::initializePage(int id)
{
    if(page(id) == ui->wizardPage2)
    {
        QDir *dir= new QDir(str);
        list = dir->entryList();
        int num = list.size();
        //进度条进程
        myprogressBar* thread = new myprogressBar(num);
        ui->progressBar->setRange(0, num-1);
        connect(thread, SIGNAL(Sig_ProgressValue(int)),this, SLOT(slot_ProgressValue(int)));

        //list进程
        mylistWidget* listThread = new mylistWidget(num);
        connect(listThread,SIGNAL(Sig_ProgressValue(int)),this,SLOT(slot_ListWidget(int)));
        thread->start();
        listThread->start();
        connect(thread, SIGNAL(Sig_Next()),this, SLOT(slot_progressBar()));
        connect(thread, SIGNAL(Sig_Next()), ui->wizardPage2, SIGNAL(completeChanged()));
    }
}

void Wizard::slot_ProgressValue(int ivalue)
{ 
    ui->progressBar->setValue(ivalue);
}
void Wizard::slot_ListWidget(int index)
{
    string = list.at(index);
    ui->listWidget->addItem(string);
}


void Wizard::slot_switchPage()
{
    if(ui->comboBox->currentIndex() == 0){
        ui->stackedWidget->setCurrentIndex(0);
    }else{
        ui->stackedWidget->setCurrentIndex(1);
    }
}
