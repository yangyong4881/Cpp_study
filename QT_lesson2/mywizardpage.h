#ifndef MYWIZARDPAGE_H
#define MYWIZARDPAGE_H

#include<QWidget>
#include<QWizardPage>
class mywizardPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit mywizardPage(QWidget *parent = nullptr);
    virtual bool isComplete() const;
    void SetNextEnable(bool bflag);

signals:

private:
    bool m_bnextDisable;
};


#endif // MYWIZARDPAGE_H
