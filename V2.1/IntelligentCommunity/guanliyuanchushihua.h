#ifndef GUANLIYUANCHUSHIHUA_H
#define GUANLIYUANCHUSHIHUA_H

#include <QWidget>

namespace Ui {
class guanliyuanchushihua;
}

class guanliyuanchushihua : public QWidget
{
    Q_OBJECT

public:
    explicit guanliyuanchushihua(QWidget *parent = 0);
    ~guanliyuanchushihua();

private slots:
    void on_pushButton_clicked();

private:
    Ui::guanliyuanchushihua *ui;
};

#endif // GUANLIYUANCHUSHIHUA_H
