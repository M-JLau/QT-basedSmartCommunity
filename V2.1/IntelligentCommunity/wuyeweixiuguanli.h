#ifndef STAFF_WIDGET_H
#define STAFF_WIDGET_H

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
class Wuyeweixiuguanli;
}

class Wuyeweixiuguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeweixiuguanli(QWidget *parent = 0);
    ~Wuyeweixiuguanli();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Wuyeweixiuguanli *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

};

#endif // STAFF_WIDGET_H
