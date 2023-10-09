#include "yezhujiaofeichaxun.h"
#include "ui_yezhujiaofeichaxun.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
extern int yonghuming;
Yezhujiaofeichaxun::Yezhujiaofeichaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhujiaofeichaxun)
{
    ui->setupUi(this);
//    //建立并打开数据库
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("jiaofeixinxi.db");
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

Yezhujiaofeichaxun::~Yezhujiaofeichaxun()
{
    delete ui;
}
void Yezhujiaofeichaxun::on_pushButton_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString type = ui->comboBox->currentText();
    QDate dateEdit=ui->dateEdit->date();
    QString date = dateEdit.toString("yyyy-MM-dd");
    //ui->lineEdit_2->setText(date);
    if(type=="全部查询")
    {
    QString sql = QString("select * from payment where id=%1 and payment.date = '%3'").arg(yonghuming).arg(date);
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
    else if(type=="未缴费")
        {
    QString sql = QString("select * from payment where id=%1 and state = '%2' and payment.date = '%3'").arg(yonghuming).arg("否").arg(date);
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
    else
{
    QString sql = QString("select * from payment where id=%1 and payment.type = '%2' and payment.date = '%3'").arg(yonghuming).arg(type).arg(date);
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
}

void Yezhujiaofeichaxun::on_pushButton_2_clicked()
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

void Yezhujiaofeichaxun::on_pushButton_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QString sql = QString("select * from payment  where id=%1").arg(yonghuming);
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
