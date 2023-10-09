#include "shenpichaxun.h"
#include "ui_shenpichaxun.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
extern int yonghuming;
shenpichaxun::shenpichaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shenpichaxun)
{
    ui->setupUi(this);
}

shenpichaxun::~shenpichaxun()
{
    delete ui;
}

void shenpichaxun::on_pushButton_clicked()
{
    QString str=QString("select * from usrlist where id = '%1'").arg(yonghuming);
     QSqlQuery query;
     query.exec(str);
     QString namel;
     while(query.next())
     {
         namel=query.value(5).toString();
     }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select * from qingjia where name = '%1'").arg(namel);
    model->setQuery(sql);
    qDebug()<<model->rowCount();

    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"请假时间");
    model->setHeaderData(2,Qt::Horizontal,"原因");
    model->setHeaderData(3,Qt::Horizontal,"销假时间");
 model->setHeaderData(4,Qt::Horizontal,"审批结果");
    ui->tableView->setModel(model);
}
