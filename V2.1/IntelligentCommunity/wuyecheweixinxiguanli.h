#ifndef CAR_H
#define CAR_H

#include <QWidget>

namespace Ui {
class Wuyecheweixinxiguanli;
}

class Wuyecheweixinxiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyecheweixinxiguanli(QWidget *parent = 0);
    ~Wuyecheweixinxiguanli();

private slots:

    void on_addButton_clicked();

    void on_modifyButton_clicked();

    void on_queryButton_clicked();

    void on_delpushButton_clicked();

private:
    Ui::Wuyecheweixinxiguanli *ui;
    void value();
};

#endif // CAR_H
