#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Yezhujiaofeichaxun;
}

class Yezhujiaofeichaxun : public QWidget
{
    Q_OBJECT

public:
    explicit Yezhujiaofeichaxun(QWidget *parent = 0);
    ~Yezhujiaofeichaxun();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::Yezhujiaofeichaxun *ui;
};

#endif // WIDGET_H
