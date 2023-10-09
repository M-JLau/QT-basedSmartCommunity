#ifndef USERCAR_H
#define USERCAR_H

#include <QWidget>

namespace Ui {
class Yezhucheweiguanli;
}

class Yezhucheweiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Yezhucheweiguanli(QWidget *parent = 0);
    ~Yezhucheweiguanli();

private slots:
    void on_pushButton_clicked();

    void on_delpushButton_clicked();

    void on_shenpushButton_clicked();

private:
    Ui::Yezhucheweiguanli *ui;
    void table1show();
    void table2show();
    void table3show();
};

#endif // USERCAR_H
