#ifndef PRICE_H
#define PRICE_H

#include <QWidget>

namespace Ui {
class Wuyejiagewihu;
}

class Wuyejiagewihu : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyejiagewihu(QWidget *parent = 0);
    ~Wuyejiagewihu();

private slots:


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Wuyejiagewihu *ui;
};

#endif // PRICE_H
