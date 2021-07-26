#include "dialog.h"
#include "ui_dialog.h"
#include<QFile>

#include<QIcon>
#include<QPixmap>
#include<QMouseEvent>
#include<QFileDialog>
#include<QString>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->installEventFilter(this);//安装事件

    ui->label_3->setText(tr("Picture quality"));

    this->setFixedSize(600, 627);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){
        QString str=QFileDialog::getExistingDirectory(this,"打开文件","./");
        ui->lineEdit_2->setText(str);
        });
    initStyle();
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->pushButton && event->type() == QEvent::MouseButtonPress)
    {
        return true;
    }
    else return false;
}

void Dialog::initStyle()
{
    QFile file(":/main.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}




// 重写mouseMoveEvent
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
            move(event->pos() - m_point + pos());
}

// 重写mousePressEvent
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        {
            m_bPressed = true;
            m_point = event->pos();
        }
}

// 重写mouseReleaseEvent
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
        m_bPressed = false;
}



void Dialog::on_pushButton_7_clicked()
{

}
