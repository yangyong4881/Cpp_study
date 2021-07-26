#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<kmyloghandler.h>
#include<QFileInfo>
#include<QDateTime>
#include<QDesktopServices>
#include<QProcess>
#include<QDebug>
#include<QFileSystemWatcher>
#include<QString>
KMyLogHandler file;
QString text;
QFileSystemWatcher m_dirWatcher;
QString filepath1 = "E:\\Desktop\\QT_lesson5\\main.txt";
QString data1 = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.ms");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qInstallMessageHandler(logOutput);
    bool b = QObject::connect(&m_dirWatcher, &QFileSystemWatcher::fileChanged,
            [=](const QString& filepath1) {
                QString fileName(filepath1);
                QFile file(fileName);
                if(file.open(QIODevice::ReadOnly)){
                    QTextStream aStream(&file); //用文本流读取文件
                    aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
                    while(!aStream.atEnd()){
                        QString str = aStream.readLine();
                        ui->listWidget->addItem(str.toLocal8Bit());
                     }
                    file.close();
                }else{
                    ui->listWidget->addItem("Open Failed!");
                }
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QProcess* process = new QProcess();
void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->addItem( data1 +"--打开日记文件");
//    QString notepadPath = path;
//    process->start(notepadPath);
    file.open();
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->addItem(data1 + "关闭日记文件");
//    process->close();
    file.close();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << arg1;
    ui->listWidget->addItem(text);
    file.writerTxt(arg1);
}

void MainWindow::write(QString str)
{
    text = str;
}

void MainWindow::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString text;

    text.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.ms") + " ");
    switch(type)
    {
        case QtDebugMsg:
            text.append("Debug:");
            break;
    }
    text.append(msg);
    write(text);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString s = ui->lineEdit_2->text();
    ui->listWidget->addItem(data1 + "--写入信息为"+ui->lineEdit_2->text());
    file.writerTxt(s);
    ui->lineEdit_2->setText("");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget->addItem(data1 + "--读出一行信息");
    QString fileName(filepath1);
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream aStream(&file); //用文本流读取文件
        aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
            QString str = aStream.readLine();
            ui->lineEdit_3->setText(str.toLocal8Bit());
        file.close();
    }else{
        ui->lineEdit_3->setText("Open Failed!");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->listWidget->addItem(data1 + "--读出全部信息");
    QString fileName(filepath1);
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream aStream(&file); //用文本流读取文件
        aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
        while(!aStream.atEnd()){
            QString str = aStream.readLine();
            ui->listWidget_2->addItem(str.toLocal8Bit());
         }
        file.close();
    }else{
        ui->listWidget_2->addItem("Open Failed!");
    }
}
