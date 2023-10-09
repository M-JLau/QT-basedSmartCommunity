#ifndef LEAVE_H
#define LEAVE_H

#include <QWidget>

namespace Ui {
class Wuyeqingxiaojia;
}

class Wuyeqingxiaojia : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeqingxiaojia(QWidget *parent = 0);
    ~Wuyeqingxiaojia();
private slots:
    void on_pushButton_clicked();




private:
    Ui::Wuyeqingxiaojia *ui;
};

#endif // LEAVE_H
