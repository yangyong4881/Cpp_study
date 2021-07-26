#include "mywizard.h"
#include <QTextCodec>
#include <QIcon>

mywizard::mywizard(QWidget *parent) :
    QWizard(parent),

    m_Fw(new FirstWizard),
    m_Sw(new SecondWizard),
    m_Tw(new ThirdWizard),
    m_Fow(new FourthWizard)
{
    //将向导页加入向导
    setPage(mywizard::Page_First,m_Fw);
    setPage(mywizard::Page_Second,m_Sw);
    setPage(mywizard::Page_Third,m_Tw);
    setPage(mywizard::Page_Fourth,m_Fow);

    //设置导航样式
    setWizardStyle( QWizard::ModernStyle );
    setWindowTitle( "界面安装 - [预览]");
    //去掉向导页面按钮
    setOption( QWizard::NoBackButtonOnStartPage );
    setOption( QWizard::NoBackButtonOnLastPage );

    //设置两个按钮
    setButtonText(QWizard::NextButton, "下一步[N]");
    setButtonText(QWizard::BackButton, "上一步");
    setButtonText(QWizard::FinishButton,"完成");
    setButtonText(QWizard::CancelButton,"取消");

}
