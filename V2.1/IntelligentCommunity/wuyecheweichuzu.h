#ifndef CHUZU_H
#define CHUZU_H

#include <QWidget>

namespace Ui {
class Wuyecheweichuzu;
}

class Wuyecheweichuzu : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyecheweichuzu(QWidget *parent = 0);
    ~Wuyecheweichuzu();

private slots:
    void on_selectpushButton_clicked();

    void on_yespushButton_clicked();

private:
    Ui::Wuyecheweichuzu *ui;
    void table1show();
    void table2show();
};

#endif // CHUZU_H
