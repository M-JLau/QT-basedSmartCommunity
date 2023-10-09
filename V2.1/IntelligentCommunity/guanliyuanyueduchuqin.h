#ifndef CHUQIN_H
#define CHUQIN_H

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
class Guanliyuanyueduchuqin;
}

class Guanliyuanyueduchuqin : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuanyueduchuqin(QWidget *parent = 0);
    ~Guanliyuanyueduchuqin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Guanliyuanyueduchuqin *ui;
     QSqlTableModel *model;
     QSqlTableModel *model1;
};

#endif // CHUQIN_H
