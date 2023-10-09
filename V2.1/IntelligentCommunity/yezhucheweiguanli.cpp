#include "yezhucheweiguanli.h"
#include "ui_yezhucheweiguanli.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QDate>

extern int yonghuming;

Yezhucheweiguanli::Yezhucheweiguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhucheweiguanli)
{
    ui->setupUi(this);
    table1show();
    table2show();
    table3show();
}

Yezhucheweiguanli::~Yezhucheweiguanli()
{
    delete ui;
}

void Yezhucheweiguanli::table1show(){
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select car_id,color,brand from car where user_id='%1'").arg(yonghuming);
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"车牌号");
    model->setHeaderData(1,Qt::Horizontal,"颜色");
    model->setHeaderData(2,Qt::Horizontal,"品牌");
    ui->tableView->setModel(model);
}

void Yezhucheweiguanli::table2show(){

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select number,addr,sellout,mark from park where sellout='%1'").arg("否");
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"车位地址");
    model->setHeaderData(2,Qt::Horizontal,"是否已出售");
    model->setHeaderData(3,Qt::Horizontal,"车位级别");
    ui->tableView_3->setModel(model);
}

void Yezhucheweiguanli::table3show(){

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select p.number,p.addr,p.sellout,s.state from park as p inner join shenqing as s on p.number=s.parknum where s.user_id='%1'").arg(yonghuming);//修改
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"车位地址");
    model->setHeaderData(2,Qt::Horizontal,"是否售出");
    model->setHeaderData(3,Qt::Horizontal,"状态");
    ui->tableView_2->setModel(model);
}

void Yezhucheweiguanli::on_pushButton_clicked()
{

    QString car_id = ui->numlineEdit->text();
    QString car_color = ui->colorlineEdit->text();
    QString car_brand = ui->brandlineEdit->text();

    if(car_id==""||car_color==""||car_brand==""){
        QMessageBox::question(this,"错误提示","请正确填写所有信息！！！",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        QSqlQueryModel *model = new QSqlQueryModel(this);
        QSqlQuery query;
        QString sql = QString("insert into car values(null,'%1','%2','%3','%4')").arg(car_color).arg(car_brand).arg(car_id).arg(yonghuming);//修改
        query.exec(sql);
        sql = QString("select car_id,color,brand from car where user_id='%1'").arg(yonghuming);//修改
        model->setQuery(sql);
        qDebug()<<model->rowCount();
        model->setHeaderData(0,Qt::Horizontal,"车牌号");
        model->setHeaderData(1,Qt::Horizontal,"颜色");
        model->setHeaderData(2,Qt::Horizontal,"品牌");
        ui->tableView->setModel(model);
    }


}

void Yezhucheweiguanli::on_delpushButton_clicked()
{

    QString car_id = ui->numlineEdit->text();
    if(car_id==""){
        QMessageBox::question(this,"错误提示","请正确填写所有信息！！！",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        int re = QMessageBox::question(this,"删除提示","是否删除当前信息？？？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(re==QMessageBox::Yes){
            QSqlQueryModel *model = new QSqlQueryModel(this);
            QSqlQuery query;
            QString sql = QString("delete from car where car_id='%1' and user_id='%2'").arg(car_id).arg(yonghuming);//修改
            query.exec(sql);
            sql = QString("select car_id,color,brand from car where user_id='%1'").arg(yonghuming);
            model->setQuery(sql);
            qDebug()<<model->rowCount();
            model->setHeaderData(0,Qt::Horizontal,"车牌号");
            model->setHeaderData(1,Qt::Horizontal,"颜色");
            model->setHeaderData(2,Qt::Horizontal,"品牌");
            ui->tableView->setModel(model);
        }
    }


}

void Yezhucheweiguanli::on_shenpushButton_clicked()
{

    QString d1 = QDate::currentDate().toString();
    QString parknum = ui->parklineEdit->text();
    if(parknum==""){
        QMessageBox::question(this,"错误提示","请正确填写所有信息！！！",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        int re = QMessageBox::question(this,"申请提示","是否申请当前车位？？？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(re==QMessageBox::Yes){
            QString sql = QString("insert into shenqing values(null,'%1','%2','%3','%4')").arg(yonghuming).arg("待审核").arg(d1).arg(parknum);
            QSqlQuery query;
            query.exec(sql);
        }
    }

    table3show();
}
