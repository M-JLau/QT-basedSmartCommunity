#include "guanliyuanchushihua.h"
#include "ui_guanliyuanchushihua.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

extern int yonghuming;

guanliyuanchushihua::guanliyuanchushihua(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guanliyuanchushihua)
{
    ui->setupUi(this);

}

guanliyuanchushihua::~guanliyuanchushihua()
{
    delete ui;
}

void guanliyuanchushihua::on_pushButton_clicked()
{



    QSqlQuery query;
    QString temp1 =  QString("select * from usrlist");
    query.exec(temp1);



    QMessageBox::information(NULL,"警告"," 信息是否要删除！！");


        QString str1 =  QString("delete from usrlist where mark != 0");
        query.exec(str1);//删除信息
        QString str =  QString("delete  from car");
        query.exec(str);//删除信息
        QString str2 =  QString("delete from chuqin");
        query.exec(str2);//删除信息
        QString str3 =  QString("delete  from park");
        query.exec(str3);//删除信息
        QString str4 =  QString("delete from payment");
        query.exec(str4);//删除信息
        QString str5 =  QString("delete  from qingjia");
        query.exec(str5);//删除信息
        QString str6 =  QString("delete from shenqing");
        query.exec(str6);//删除信息
//        QString str7 =  QString("delete from typer");
//         query.exec(str7);//删除信
        QString str8 =  QString("delete  from weixiu");
        query.exec(str8);//删除信息
        QString str9 =  QString("delete  from yezhu");
        query.exec(str9);//删除信息

        QMessageBox::information(NULL,"Success"," 信息删除成功！！");


}

