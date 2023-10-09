#include "yezhuzizhujiaofei.h"
#include "ui_yezhuzizhujiaofei.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QWidget>
extern int yonghuming;
yezhuzizhujiaofei::yezhuzizhujiaofei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yezhuzizhujiaofei)
{
    ui->setupUi(this);
}

yezhuzizhujiaofei::~yezhuzizhujiaofei()
{
    delete ui;
}
void yezhuzizhujiaofei::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QString sql = QString("select * from payment where id=%1 and state = '%2'").arg(yonghuming).arg("否");
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

void yezhuzizhujiaofei::on_pushButton_2_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString type = ui->comboBox->currentText();
    QDate dateEdit=ui->dateEdit->date();
    QString date = dateEdit.toString("yyyy-MM-dd");
    QString sql = QString("update payment set state = '%1' where id = %2 and type = '%3' and date = '%4'").arg("是").arg(yonghuming).arg(type).arg(date);
    model->setQuery(sql);



    QMessageBox::information(NULL,"Success"," 缴费成功！！");
}
