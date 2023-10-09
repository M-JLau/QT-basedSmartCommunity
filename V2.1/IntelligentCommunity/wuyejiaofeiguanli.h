#ifndef WUYEJIAOFEIGUANLI_H
#define WUYEJIAOFEIGUANLI_H

#include <QWidget>
#include"QLineEdit"
namespace Ui {
class Wuyejiaofeiguanli;
}

class Wuyejiaofeiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyejiaofeiguanli(QWidget *parent = 0);
    ~Wuyejiaofeiguanli();
    //QString state;
    QLineEdit *edit;
    int a = 0;
private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::Wuyejiaofeiguanli *ui;
};

#endif // WUYEJIAOFEIGUANLI_H
