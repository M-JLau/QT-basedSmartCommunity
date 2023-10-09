#ifndef WUYEXIANXIASHOUFEI_H
#define WUYEXIANXIASHOUFEI_H
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QWidget>

namespace Ui {
class wuyexianxiashoufei;
}

class wuyexianxiashoufei : public QWidget
{
    Q_OBJECT

public:
    explicit wuyexianxiashoufei(QWidget *parent = 0);
    ~wuyexianxiashoufei();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::wuyexianxiashoufei *ui;
};

#endif // WUYEXIANXIASHOUFEI_H
