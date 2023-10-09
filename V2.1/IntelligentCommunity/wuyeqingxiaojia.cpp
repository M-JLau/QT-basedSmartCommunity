#include "wuyeqingxiaojia.h"
#include "ui_wuyeqingxiaojia.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include<QDateTime>
extern int yonghuming;

Wuyeqingxiaojia::Wuyeqingxiaojia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeqingxiaojia)
{
    ui->setupUi(this);
}

Wuyeqingxiaojia::~Wuyeqingxiaojia()
{
    delete ui;
}
void Wuyeqingxiaojia::on_pushButton_clicked()
{

    QString str1=QString("select * from usrlist where id = '%1'").arg(yonghuming);
    QSqlQuery query1;
    query1.exec(str1);
    QString namel;
    while(query1.next())
    {
        namel=query1.value(5).toString();
    }
    QString str2 =  QString("delete from qingjia where name = '%1'").arg(namel);
    QSqlQuery query2;
    query2.exec(str2);
    QString id = ui->lineEdit_3->text();
    QString onetime = ui->dateTimeEdit->text();
    QString twotime = ui->dateTimeEdit_2->text();
    QString str = QString("insert into qingjia (name,date,id,date2) values('%1','%2','%3','%4') ").arg(namel).arg(onetime).arg(id).arg(twotime);
    QSqlQuery query;
        if(!query.exec(str))
        {
             qDebug()<<"there is not a table of book in mysql!"<<query.lastError();
        }
        else
        {
            QMessageBox::information(NULL,"Success"," 请假申请提交成功！！");
        }
}
