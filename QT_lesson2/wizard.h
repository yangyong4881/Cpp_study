#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include<QString>
#include<QStringList>
#include <QDateTime>

namespace Ui {
class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = nullptr);
    ~Wizard();
    QString str,string;
    QStringList list ;

protected:
    virtual void initializePage(int id);
    void sleep(int msec);


public slots:
    void slot_switchPage();
    void slot_checkbox();
    void slot_checkbox1();
    void slot_progressBar();
    void slot_radioButton();
    void slot_radioButton_2();
    void slot_pushButton();
    void slot_ProgressValue(int ivalue);
    void slot_ListWidget(int index);


private:
    Ui::Wizard *ui;
};

#endif // WIZARD_H
