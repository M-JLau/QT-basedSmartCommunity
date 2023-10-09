#ifndef OWNER_ADD_H
#define OWNER_ADD_H

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
class Yezhuguzhuangbaoxiu;
}

class Yezhuguzhuangbaoxiu : public QWidget
{
    Q_OBJECT

public:
    explicit Yezhuguzhuangbaoxiu(QWidget *parent = 0);
    ~Yezhuguzhuangbaoxiu();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Yezhuguzhuangbaoxiu *ui;
    QSqlDatabase db;
};

#endif // OWNER_ADD_H
