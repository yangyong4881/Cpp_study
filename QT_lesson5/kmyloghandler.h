#ifndef KMYLOGHANDLER_H
#define KMYLOGHANDLER_H
#include<QObject>
#include <QFile>
#include <QString>
class KMyLogHandler : public QObject
{
    Q_OBJECT
public:
    KMyLogHandler();
    ~KMyLogHandler();

    //打开
    void open();
    //关闭
    void close();
    //文本格式读
    void readTxt();
    //文本格式写
    void writerTxt(QString);
    //二进制读
    void readBin();
    //二进制写
    void writteBin();
    //输出
//    void fileInfoFun();

public:
    QFile file;
    QString str;
    QString fileName;
};

#endif // KMYLOGHANDLER_H
