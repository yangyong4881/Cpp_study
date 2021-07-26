#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(slot_click()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{
//    int inumber = ui->lineEdit->text().toInt();
//    int inumber2 = ui->lineEdit_2->text().toInt();
//    int sum = inumber + inumber2;
//    ui->lineEdit_3->setText(QString::number(sum));
//}

//void MainWindow::slot_cal(int inum1, int inum2)
//{
//    int isum = inum1 + inum2;
//    ui->lineEdit_3->setText(QString::number(isum));
//}


//void MainWindow::slot_click()
//{
//    int inum1 = ui->lineEdit->text().toInt();
//    int inum2 = ui->lineEdit_2->text().toInt();
//    //int inum3 = ui->lineEdit_3->text().toInt();
//    slot_cal(inum1,inum2);
//    //slot_multi(inum1,inum3);
//}

//void MainWindow::slot_multi(int inum1, int inum2)
//{
//    int imul = inum1 * inum2;
//    ui->pushButton->setText(QString::number(imul));
//}
void MainWindow::on_pushButton_0_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +0;
    ui->lineEdit->setText(str+QString::number(0));
}

void MainWindow::on_pushButton_1_clicked()
{

    QString str = ui->lineEdit->text();
    secondres = secondres*10 +1;
    ui->lineEdit->setText(str+QString::number(1));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +2;
    ui->lineEdit->setText(str+QString::number(2));
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +3;
    ui->lineEdit->setText(str+QString::number(3));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +4;
    ui->lineEdit->setText(str+QString::number(4));
}

void MainWindow::on_pushButton_5_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +5;
    ui->lineEdit->setText(str+QString::number(5));
}

void MainWindow::on_pushButton_6_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +6;
    ui->lineEdit->setText(str+QString::number(6));
}

void MainWindow::on_pushButton_7_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +7;
    ui->lineEdit->setText(str+QString::number(7));
}

void MainWindow::on_pushButton_8_clicked()
{
    QString str = ui->lineEdit->text();
   secondres = secondres*10 +8;
    ui->lineEdit->setText(str+QString::number(8));
}

void MainWindow::on_pushButton_9_clicked()
{
    QString str = ui->lineEdit->text();
    secondres = secondres*10 +9;
    ui->lineEdit->setText(str+QString::number(9));
}

void MainWindow::on_pushButton_10_clicked()
{
    QString str = ui->lineEdit->text();
    if(count ==1) res= res + secondres;
    else res = res-secondres;
    secondres = 0;
    count = 1;
    ui->lineEdit->setText(str+"+");
}

void MainWindow::on_pushButton_11_clicked()
{
    QString str = ui->lineEdit->text();
    if(count ==1) res= res + secondres;
    else res = res-secondres;
    secondres = 0;
    count = -1;
    ui->lineEdit->setText(str+"-");
}

void MainWindow::on_pushButton_12_clicked()
{
    QString str = ui->lineEdit->text();
    if(count ==1) res= res + secondres;
    else res = res-secondres;
    secondres = 0;
    ui->lineEdit->setText(str+"="+QString::number(res));

}

void MainWindow::on_pushButton_13_clicked()
{
    res= 0;
    secondres = 0;
    ui->lineEdit->setText(QString::number(0));
}



//void MainWindow::on_pushButton_14_clicked()
//{
//    QString str = ui->lineEdit->text();
//    count++;
//    ui->lineEdit->setText(str+"*");
//}

//void MainWindow::on_pushButton_15_clicked()
//{
//    QString str = ui->lineEdit->text();
//    count++;
//    ui->lineEdit->setText(str+"/");
//}
