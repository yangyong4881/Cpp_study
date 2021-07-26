#include "titlewidget.h"
#include "ui_titlewidget.h"


TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);
    this->setFixedHeight(30);
    connect(ui->clostBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

TitleWidget::~TitleWidget()
{
    delete ui;
}


