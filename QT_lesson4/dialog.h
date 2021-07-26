#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class QEvent;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
   // virtual void customEvent(QEvent *event);
    virtual bool eventFilter(QObject * , QEvent *);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_7_clicked();

private:
   void initStyle();
private:
    Ui::Dialog *ui;

    bool m_bPressed = true;
    QPoint m_point;
};
#endif // DIALOG_H
