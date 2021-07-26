#ifndef TITLEDIALOG_H
#define TITLEDIALOG_H

#include <QWidget>

namespace Ui {
class TitleDialog;
}

class TitleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit TitleDialog(QWidget *parent = nullptr);
    ~TitleDialog();

private:
    Ui::TitleDialog *ui;
};

#endif // TITLEDIALOG_H
