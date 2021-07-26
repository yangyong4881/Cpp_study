#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"QDialog"
#include"QColorDialog"
#include"QDebug"
#include"QMessageBox"
#include <QWizard>
#include<QPushButton>
#include<QCheckBox>
#include"QIcon"
#include<QGroupBox>
#include<QRadioButton>
#include<QLineEdit>
#include<QTextEdit>
#include<QProgressBar>
#include<QWidget>
#include<QListWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLabel>
#include<QFileInfo>
#include<QFileDialog>
#include<QAbstractButton>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QWizardPage * MainWindow::createPage1()    //wizard page 1
{
    QWizardPage *page = new QWizardPage;
    QTextEdit *textEdit = new QTextEdit("用户安全协议");
    QCheckBox *CheckBox_1 = new QCheckBox("我已阅读用户保护协议，并同意这份协议");
    CheckBox_1->setCheckable(true);
    CheckBox_1->setChecked(false);
//    connect(CheckBox_1,SIGNAL(stateChanged(int)),this,SLOT(Change()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(CheckBox_1);
    page->setButtonText(QWizard::NextButton,"下一步");
    page->setLayout(layout);
    return page;
}

//int MainWindow::Change(){
//    if(CheckBox_1->isChecked()){
//        bt->setEnabled(true);
//    }
//    else bt->setEnabled(false);
//    return 0;
//}

QWizardPage * MainWindow::createPage2()   //wizard page 2
{
    QWizardPage *page = new QWizardPage;
    QRadioButton *radio1 = new QRadioButton("当前用户");
    QRadioButton *radio2 = new QRadioButton("所有用户");
    QCheckBox * checkBox1 = new QCheckBox("关键Doc、XLS、PPT");
    QCheckBox * checkBox2 = new QCheckBox("关键PDF格式");
    QCheckBox * checkBox3 = new QCheckBox("关键PNG、JPG等图片格式");
    QCheckBox * checkBox4 = new QCheckBox("关键EPUBE");
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
    line->setText(file_path+"\\"+file_name);
    page->setLayout(layout);
    return page;
}



QWizardPage * MainWindow::createPage3()   //wizard page 3
{
    QWizardPage *page = new QWizardPage;
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
    page->setLayout(layout);
    return page;
}



QWizardPage * MainWindow::createPage4()   //wizard page 4
{
    QWizardPage *page = new QWizardPage;
    QLabel *label = new QLabel("激活方式：");
    combo = new QComboBox(this);
    combo->setGeometry(50,50,200,30);
    combo->addItem(tr("序列号"));
    combo->addItem(tr("登录账号"));
    QLineEdit *lineEdit = new QLineEdit;
  	lineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
    QGridLayout *layout2 = new QGridLayout;
    QLabel* label1 = new QLabel("用户名：");
    QLabel* label2 = new QLabel("密码：");
    QLineEdit *lineEdit1 = new QLineEdit;
    QLineEdit *lineEdit2 = new QLineEdit;
    layout2->addWidget(label1,0,0);
    layout2->addWidget(lineEdit1,0,1);
    layout2->addWidget(label2,1,0);
    layout2->addWidget(lineEdit2,1,1);
    QWidget *widget2 = new QWidget;
    widget2->setLayout(layout2);
    QPushButton *pushButton = new QPushButton("激活");
    QCheckBox *checkBox = new QCheckBox("跳过");


    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(label);
    layout1->addWidget(combo);

    QWidget *widget1 = new QWidget;
    widget1->setLayout(layout1);
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(widget1,0,0,1,5);
    layout->addWidget(lineEdit,1,0,1,5);
    //layout->addWidget(widget2,1,0,1,5);

    layout->addWidget(pushButton,2,0,1,1);
    layout->addWidget(checkBox,3,4);
    page->setLayout(layout);
    return page;
}



void MainWindow::on_pushButton_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("界面安装-[预览]");

    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.addPage(createPage4());

    wizard.exec();
}