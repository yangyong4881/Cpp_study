#include "kmyloghandler.h"
#include <QFile>
#include <QByteArray>
#include<QtDebug>
#include<QDataStream>
#include<QTextStream>
#include<QFileInfo>
#include<QDateTime>
#include<QProcess>

QProcess* process = new QProcess();
QString path = "notepad.exe E:\\Desktop\\QT_lesson5\\main.txt";
QString filepath = "E:\\Desktop\\QT_lesson5\\main.txt";
KMyLogHandler::KMyLogHandler()
{

}

KMyLogHandler::~KMyLogHandler()
{

}

void KMyLogHandler::open()
{
    QString notepadPath = path;
    process->start(notepadPath);
}

void KMyLogHandler::close()
{
    process->close();
}

void KMyLogHandler::readTxt()
{
    QString fileName(filepath);
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream aStream(&file); //用文本流读取文件
        aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
        while(!aStream.atEnd()){
            QString str = aStream.readLine();
            qDebug() << str;
        }
        file.close();
    }else{
        qDebug() << "Open Failed!";
    }
}

void KMyLogHandler::writerTxt(QString s)
{
    QString fileName(filepath);
    QFile file(fileName);

    if(file.open(QIODevice::Append)){
        file.write("\r\n"+s.toUtf8());
        file.close();
    }
}

void KMyLogHandler::readBin()
{
    QFile file("binary.dat");
    if(file.open(QIODevice::ReadOnly)){
        QDataStream in(&file);
        QString str1;
        in>>str1;
        file.close();
    }

}

void KMyLogHandler::writteBin()
{
    QFile file("binary.dat");
    if(file.open(QIODevice::WriteOnly)){
        QDataStream out(&file);
        out << QString("");
        file.close();
    }
}

//void KMyLogHandler::fileInfoFun()
//{
//    QFileInfo fileInfo(file);
//    QString fileName = fileInfo.fileName();

//    QDateTime ceateDt = fileInfo.created();
//    QDateTime modifyDt = fileInfo.lastModified();
//    QDateTime readDt = fileInfo.lastRead();

//    //qDebug() << "创建时间：" << ceateDt.toString("yyyy-MM-dd hh:mm:ss");
//   // qDebug() << "修改时间：" << modifyDt.toString("yyyy-MM-dd hh:mm:ss");
//   // qDebug() << "读取时间：" << readDt.toString("yyyy-MM-dd hh:mm:ss");
//}
