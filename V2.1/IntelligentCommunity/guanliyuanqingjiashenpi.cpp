#include "guanliyuanqingjiashenpi.h"
#include "ui_guanliyuanqingjiashenpi.h"
#include <qdebug.h>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
extern int yonghuming;
Guanliyuanqingjiashenpi::Guanliyuanqingjiashenpi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guanliyuanqingjiashenpi)
{
    ui->setupUi(this);
}

Guanliyuanqingjiashenpi::~Guanliyuanqingjiashenpi()
{
    delete ui;
}

void Guanliyuanqingjiashenpi::on_pushButton_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("qingjia");
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"起始时间");
    model->setHeaderData(2,Qt::Horizontal,"原因");
    model->setHeaderData(3,Qt::Horizontal,"截止时间");
    model->setHeaderData(4,Qt::Horizontal,"审批结果");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,200);
    ui->tableView->setColumnWidth(4,200);
}

void Guanliyuanqingjiashenpi::on_pushButton_2_clicked()
{

    QString updatename = ui->lineEdit->text();
      QString updateshenpi = ui->lineEdit_5->text();
      if(updatename == NULL )
          {
               QMessageBox::information(NULL,"fail"," 请输入姓名和审批结果");
          }
      else
      {
      QString temp = QString("select * from qingjia where name = '%1'").arg(updatename);

      QSqlQuery query;
      query.exec(temp);// 查询信息
      QString c;
      while (query.next())
      {
          c = query.value(1).toString();
      }
      if(c == NULL)
      {
          QString b = QString("没有名叫%1的人，修改失败").arg(updatename);
          QMessageBox::information(NULL,"fail",b);
          ui->lineEdit->clear();
          ui->lineEdit_5->clear();
      }
      else
      {
        QString temp = QString("update qingjia set shenpi = '%1' where name = '%2'").arg(updateshenpi).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_5->clear();

        }
}
}


void Guanliyuanqingjiashenpi::on_pushButton_3_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll();
    } else {
        model->submitAll();
    }
}
