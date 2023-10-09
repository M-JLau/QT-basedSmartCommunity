#ifndef GUANLIYUANRENSHICHAXUN_H
#define GUANLIYUANRENSHICHAXUN_H

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
class Guanliyuanrenshichaxun;
}

class Guanliyuanrenshichaxun : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuanrenshichaxun(QWidget *parent = 0);
    ~Guanliyuanrenshichaxun();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Guanliyuanrenshichaxun *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};


#endif // GUANLIYUANRENSHICHAXUN_H
