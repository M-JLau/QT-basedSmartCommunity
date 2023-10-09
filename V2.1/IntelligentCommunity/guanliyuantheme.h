#ifndef GUANLIYUANTHEME_H
#define GUANLIYUANTHEME_H

#include <QWidget>

namespace Ui {
class Guanliyuantheme;
}

class Guanliyuantheme : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuantheme(QWidget *parent = 0);
    ~Guanliyuantheme();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Guanliyuantheme *ui;
};

#endif // GUANLIYUANTHEME_H
