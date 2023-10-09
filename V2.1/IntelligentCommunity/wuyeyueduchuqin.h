#ifndef MONTHLYATTENDANCE_H
#define MONTHLYATTENDANCE_H

#include <QWidget>

#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <string>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
namespace Ui {
class Wuyeyueduchuqin;
}

class Wuyeyueduchuqin : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeyueduchuqin(QWidget *parent = 0);
    ~Wuyeyueduchuqin();
private slots:
    void on_pushButton1_clicked();

private:
    Ui::Wuyeyueduchuqin *ui;
};

#endif // MONTHLYATTENDANCE_H
