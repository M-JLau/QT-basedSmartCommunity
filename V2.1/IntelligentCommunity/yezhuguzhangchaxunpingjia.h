#ifndef OWNER_SEARCH_H
#define OWNER_SEARCH_H

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
class Yezhuguzhangchaxunpingjia;
}

class Yezhuguzhangchaxunpingjia : public QWidget
{
    Q_OBJECT

public:
    explicit Yezhuguzhangchaxunpingjia(QWidget *parent = 0);
    ~Yezhuguzhangchaxunpingjia();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Yezhuguzhangchaxunpingjia *ui;
     QSqlDatabase db;
};

#endif // OWNER_SEARCH_H
