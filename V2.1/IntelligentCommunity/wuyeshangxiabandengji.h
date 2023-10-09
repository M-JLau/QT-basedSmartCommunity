#ifndef OFFICE_H
#define OFFICE_H

#include <QWidget>

namespace Ui {
class Wuyeshangxiabandengji;
}

class Wuyeshangxiabandengji : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeshangxiabandengji(QWidget *parent = 0);
    ~Wuyeshangxiabandengji();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Wuyeshangxiabandengji *ui;
};

#endif // OFFICE_H
