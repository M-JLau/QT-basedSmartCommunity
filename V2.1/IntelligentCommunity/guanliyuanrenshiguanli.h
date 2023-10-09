#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Guanliyuanrenshiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuanrenshiguanli(QWidget *parent = 0);
    ~Guanliyuanrenshiguanli();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
