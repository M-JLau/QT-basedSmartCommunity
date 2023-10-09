#ifndef CANSHUSHEZHI_H
#define CANSHUSHEZHI_H

#include <QWidget>

namespace Ui {
class canshushezhi;
}

class canshushezhi : public QWidget
{
    Q_OBJECT

public:
    explicit canshushezhi(QWidget *parent = 0);
    ~canshushezhi();

private:
    Ui::canshushezhi *ui;
};

#endif // CANSHUSHEZHI_H
