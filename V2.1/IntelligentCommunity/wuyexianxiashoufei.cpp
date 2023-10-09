#include "wuyexianxiashoufei.h"
#include "ui_wuyexianxiashoufei.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QWidget>
extern int yonghuming;
wuyexianxiashoufei::wuyexianxiashoufei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wuyexianxiashoufei)
{
    ui->setupUi(this);
}

wuyexianxiashoufei::~wuyexianxiashoufei()
{
    delete ui;
}
void wuyexianxiashoufei::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString id = ui->lineEdit_4->text();
    QString sql = QString("select * from payment where id=%1 and state = '%2'").arg(id).arg("否");
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"账号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"缴费类型");
    model->setHeaderData(3,Qt::Horizontal,"缴费数量");
    model->setHeaderData(4,Qt::Horizontal,"缴费日期");
    model->setHeaderData(5,Qt::Horizontal,"是否缴费");
    ui->tableView->setModel(model);

}

void wuyexianxiashoufei::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit_4->text();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString type = ui->comboBox->currentText();
    QDate dateEdit=ui->dateEdit->date();
    QString date = dateEdit.toString("yyyy-MM-dd");
    QString sql = QString("update payment set state = '%1' where id = %2 and type = '%3' and date = '%4'").arg("是").arg(id).arg(type).arg(date);
    model->setQuery(sql);
    //ui->lineEdit_4->clear();
    //ui->lineEdit_5->clear();

    QMessageBox::information(NULL,"Success"," 缴费成功！！");
}
