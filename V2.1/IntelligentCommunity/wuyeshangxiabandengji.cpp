#include "wuyeshangxiabandengji.h"
#include "ui_wuyeshangxiabandengji.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include<QDateTime>
extern int yonghuming;

Wuyeshangxiabandengji::Wuyeshangxiabandengji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeshangxiabandengji)
{
    ui->setupUi(this);

}

Wuyeshangxiabandengji::~Wuyeshangxiabandengji()
{
    delete ui;
}

void Wuyeshangxiabandengji::on_pushButton_clicked()
{
      QDateTime dateTime;
      QString state;
      QString strDateTime = dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
      QString time1 = dateTime.currentDateTime().toString("hh:mm:ss");
      QTime one = QTime::fromString(time1,"hh:mm:ss");
      qDebug()<<one;

      QTime two = QTime::fromString("08:00:00","hh:mm:ss");
      qDebug()<<two;

      int i = two.msecsTo(one)/60000;
      qDebug()<<i;

      if(i>0)
      {
          QMessageBox::information(NULL,"提示","您已迟到！");

      }


    QString str1=QString("select * from usrlist where id = '%1'").arg(yonghuming);
    QSqlQuery query1;
    query1.exec(str1);
    QString namel;
    while(query1.next())
    {
        namel=query1.value(5).toString();
    }
    QString str = QString("insert into chuqin (name,shangban) values('%1','%2') ").arg(namel).arg(strDateTime);
    QSqlQuery query;
        if(!query.exec(str))
        {
             qDebug()<<"there is not a table of chuqin in mysql!"<<query.lastError();
        }
        else
        {
            QMessageBox::information(NULL,"Success"," 上班打卡成功！！");
        }

}

void Wuyeshangxiabandengji::on_pushButton_2_clicked()
{
    QDateTime dateTime;
    QString state2;
    QString strDateTime = dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

      QString time1 = dateTime.currentDateTime().toString("hh:mm:ss");
      QTime one = QTime::fromString(time1,"hh:mm:ss");
      qDebug()<<one;

      QTime two = QTime::fromString("17:00:00","hh:mm:ss");
      qDebug()<<two;

      int i = two.msecsTo(one)/60000;
      qDebug()<<i;

      if(i<0)
      {
          QMessageBox::information(NULL,"提示","您已早退！");

      }

    QString str1=QString("select * from usrlist where id = '%1'").arg(yonghuming);
    QSqlQuery query1;
    query1.exec(str1);
    QString namel;
    while(query1.next())
    {
        namel=query1.value(5).toString();
    }

         QString temp = QString("update chuqin set xiaban = '%1'  where name = '%2'").arg(strDateTime).arg(namel);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 下班打卡成功!!");
        }
