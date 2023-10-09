#include "guanliyuanyueduchuqin.h"
#include "ui_guanliyuanyueduchuqin.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
extern int yonghuming;

Guanliyuanyueduchuqin::Guanliyuanyueduchuqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guanliyuanyueduchuqin)
{
    ui->setupUi(this);
    //建立并打开数据库
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("shangban.db");
//    if (!db.open()) {
//        QMessageBox::critical(nullptr, QObject::tr("未找到需要的数据库文件"),
//            QObject::tr("不能建立链接n.\n"
//                        "This example needs SQLite support. Please read "
//                        "the Qt SQL driver documentation for information how "
//                        "to build it.\n\n"
//                        "Click Cancel to exit."), QMessageBox::Cancel);
//    }else{
//        qDebug()<<"数据库打开成功！ "<<endl;
//      //  ui->label_data->setText(tr("数据库打开成功"));
//    }
}

Guanliyuanyueduchuqin::~Guanliyuanyueduchuqin()
{
    delete ui;
}

void Guanliyuanyueduchuqin::on_pushButton_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("chuqin");
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"上班时间");
    model->setHeaderData(2,Qt::Horizontal,"下班时间");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);

}

void Guanliyuanyueduchuqin::on_pushButton_2_clicked()
{
              QString name = ui->lineEdit->text();
              model1 = new QSqlTableModel(this);
              model1->setTable("chuqin");
              model1->setFilter(QObject::tr("name= '%1'").arg(name));
              model1->setHeaderData(0,Qt::Horizontal,"姓名");
              model1->setHeaderData(1,Qt::Horizontal,"上班时间");
              model1->setHeaderData(2,Qt::Horizontal,"下班时间");
              model1->select();
              model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
              ui->tableView->setModel(model1);
              ui->tableView->setColumnWidth(1,200);
              ui->tableView->setColumnWidth(2,200);

}

void Guanliyuanyueduchuqin::on_pushButton_3_clicked()
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
