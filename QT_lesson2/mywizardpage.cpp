#include "mywizardpage.h"

mywizardPage::mywizardPage(QWidget *parent) : QWizardPage(parent)
{
    m_bnextDisable = true;
}

bool mywizardPage::isComplete() const
{
    return !m_bnextDisable;
}
void mywizardPage::SetNextEnable(bool bflag){
    m_bnextDisable = !bflag;
}
