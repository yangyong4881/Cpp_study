#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QWizard"
#include<QtWidgets/QComboBox>
#include<QButtonGroup>
#include<QPushButton>
#include<QCheckBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


 private slots:
    void on_pushButton_clicked();
    void on_pushButton1_clicked();
//    int Change();

private:
    Ui::MainWindow *ui;
    QComboBox *combo;
    QPushButton* pushButton1;
    QLineEdit * line;
    QCheckBox *CheckBox_1;
    QAbstractButton *bt;
    QString file_full, file_name, file_path;
    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
    QWizardPage *createPage4();

//private:
//    QButtonGroup* m_group;

};
#endif // MAINWINDOW_H
