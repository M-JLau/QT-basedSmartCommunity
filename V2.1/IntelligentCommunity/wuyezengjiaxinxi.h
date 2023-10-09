#ifndef WUYEZENGJIAXINXI_H
#define WUYEZENGJIAXINXI_H

#include <QWidget>
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
class wuyezengjiaxinxi;
}

class wuyezengjiaxinxi : public QWidget
{
    Q_OBJECT

public:
    explicit wuyezengjiaxinxi(QWidget *parent = 0);
    ~wuyezengjiaxinxi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

//    void on_comboBox_activated(const QString &arg1);

private:
    Ui::wuyezengjiaxinxi *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // WUYEZENGJIAXINXI_H
