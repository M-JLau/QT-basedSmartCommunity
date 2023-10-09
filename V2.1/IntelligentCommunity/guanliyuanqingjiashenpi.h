#ifndef SHENPI_H
#define SHENPI_H

#include <QWidget>
#include <QSqlTableModel>
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
class Guanliyuanqingjiashenpi;
}

class Guanliyuanqingjiashenpi : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuanqingjiashenpi(QWidget *parent = 0);
    ~Guanliyuanqingjiashenpi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Guanliyuanqingjiashenpi *ui;
     QSqlTableModel *model;
};

#endif // SHENPI_H
