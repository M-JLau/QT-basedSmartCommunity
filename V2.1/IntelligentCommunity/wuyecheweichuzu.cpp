#include "wuyecheweichuzu.h"
#include "ui_wuyecheweichuzu.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

extern int yonghuming;

Wuyecheweichuzu::Wuyecheweichuzu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyecheweichuzu)
{
    ui->setupUi(this);
    table1show();
    table2show();
}

Wuyecheweichuzu::~Wuyecheweichuzu()
{
    delete ui;
}

void Wuyecheweichuzu::table1show(){

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select number,addr,sellout,user_id from park where sellout='%1'").arg("否");
    model->setQuery(sql);
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"车位地址");
    model->setHeaderData(2,Qt::Horizontal,"是否出售");
    model->setHeaderData(3,Qt::Horizontal,"购买者");
    ui->tableView->setModel(model);
}


void Wuyecheweichuzu::table2show(){
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select s.parknum,s.state,s.time,u.name,u.IDcard,u.tel from shenqing as s inner join usrlist as u on s.user_id=u.id where s.state='%1' order by time asc").arg("待审核");
    model->setQuery(sql);
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"进度状态");
    model->setHeaderData(2,Qt::Horizontal,"申请时间");
    model->setHeaderData(3,Qt::Horizontal,"姓名");
    model->setHeaderData(4,Qt::Horizontal,"身份证号");
    model->setHeaderData(5,Qt::Horizontal,"联系方式");
    ui->tableView_2->setModel(model);
}

void Wuyecheweichuzu::on_selectpushButton_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select number,addr,sellout,user_id from park where sellout='%1'").arg("否");
    model->setQuery(sql);
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"车位地址");
    model->setHeaderData(2,Qt::Horizontal,"是否出售");
    model->setHeaderData(3,Qt::Horizontal,"购买者");
    ui->tableView->setModel(model);
}

void Wuyecheweichuzu::on_yespushButton_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString IDcard = ui->IDlineEdit->text();
    QString number = ui->numlineEdit->text();
    QString name = ui->namelineEdit->text();
    if(IDcard==""||number==""||name==""){
        QMessageBox::question(this,"错误提示","请正确填写所有信息！！！",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        QSqlQuery query;
        QString sql = QString("select id from usrlist where name='%1' and IDcard='%2'").arg(name).arg(IDcard);
        query.exec(sql);
        if(query.next()){
            QString user_id = query.value(0).toString();
            sql = QString("update park set sellout='%1',user_id='%2'where number='%3'").arg("是").arg(user_id).arg(number);
            query.exec(sql);
            sql = QString("select * from (select p.number,p.addr,p.sellout,u.name,u.IDcard,u.tel from park as p inner join usrlist as u on p.user_id=u.id) where IDcard='%1';").arg(IDcard);
            model->setQuery(sql);
            model->setHeaderData(0,Qt::Horizontal,"车位编号");
            model->setHeaderData(1,Qt::Horizontal,"车位地址");
            model->setHeaderData(2,Qt::Horizontal,"是否出售");
            model->setHeaderData(3,Qt::Horizontal,"购买者姓名");
            model->setHeaderData(4,Qt::Horizontal,"身份证号");
            model->setHeaderData(5,Qt::Horizontal,"联系方式");
            sql = QString("update shenqing set state='%1'where user_id='%2' and parknum='%3'").arg("已购买").arg(user_id).arg(number);
            query.exec(sql);
            sql = QString("update shenqing set state='%1'where user_id!='%2' and parknum='%3'").arg("请另申车位").arg(user_id).arg(number);
            query.exec(sql);

            table1show();
            table2show();

            ui->tableView->setModel(model);
            ui->IDlineEdit->clear();
            ui->numlineEdit->clear();
            ui->namelineEdit->clear();
        }
    }

}
