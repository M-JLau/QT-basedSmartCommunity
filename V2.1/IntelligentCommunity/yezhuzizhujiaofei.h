#ifndef YEZHUZIZHUJIAOFEI_H
#define YEZHUZIZHUJIAOFEI_H

#include <QWidget>

namespace Ui {
class yezhuzizhujiaofei;
}

class yezhuzizhujiaofei : public QWidget
{
    Q_OBJECT

public:
    explicit yezhuzizhujiaofei(QWidget *parent = 0);
    ~yezhuzizhujiaofei();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::yezhuzizhujiaofei *ui;
};

#endif // YEZHUZIZHUJIAOFEI_H
