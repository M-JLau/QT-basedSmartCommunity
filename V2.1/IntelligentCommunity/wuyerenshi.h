#ifndef WUYERENSHI_H
#define WUYERENSHI_H

#include <QWidget>

namespace Ui {
class Wuyerenshi;
}

class Wuyerenshi : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyerenshi(QWidget *parent = 0);
    ~Wuyerenshi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Wuyerenshi *ui;
};

#endif // WUYERENSHI_H
