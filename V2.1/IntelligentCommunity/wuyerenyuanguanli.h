#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Wuyerenyuanguanli;
}

class Wuyerenyuanguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyerenyuanguanli(QWidget *parent = 0);
    ~Wuyerenyuanguanli();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Wuyerenyuanguanli *ui;
};

#endif // WIDGET_H
