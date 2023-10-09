#include "wuyeyueduchuqin.h"
#include "ui_wuyeyueduchuqin.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>

extern int yonghuming;

Wuyeyueduchuqin::Wuyeyueduchuqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeyueduchuqin)
{
    ui->setupUi(this);

}

Wuyeyueduchuqin::~Wuyeyueduchuqin()
{
    delete ui;
}



void Wuyeyueduchuqin::on_pushButton1_clicked()
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
            QString sql = QString("select * from chuqin where name = '%1'").arg(namel);
            model->setQuery(sql);
            qDebug()<<model->rowCount();

            model->setHeaderData(0,Qt::Horizontal,"姓名");
            model->setHeaderData(1,Qt::Horizontal,"上班时间");
            model->setHeaderData(2,Qt::Horizontal,"下班时间");

            ui->tableView->setModel(model);
            ui->tableView->setColumnWidth(1,200);
            ui->tableView->setColumnWidth(2,200);

}
