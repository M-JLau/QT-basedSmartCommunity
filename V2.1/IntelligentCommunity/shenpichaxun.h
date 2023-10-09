#ifndef SHENPICHAXUN_H
#define SHENPICHAXUN_H

#include <QWidget>

namespace Ui {
class shenpichaxun;
}

class shenpichaxun : public QWidget
{
    Q_OBJECT

public:
    explicit shenpichaxun(QWidget *parent = 0);
    ~shenpichaxun();

private slots:
    void on_pushButton_clicked();

private:
    Ui::shenpichaxun *ui;
};

#endif // SHENPICHAXUN_H
