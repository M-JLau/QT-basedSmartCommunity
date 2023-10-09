#include "wuyecheweixinxiguanli.h"
#include "ui_wuyecheweixinxiguanli.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTableView>
#include <QSqlQuery>

extern int yonghuming;

Wuyecheweixinxiguanli::Wuyecheweixinxiguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyecheweixinxiguanli)
{
    ui->setupUi(this);
    value();
}

Wuyecheweixinxiguanli::~Wuyecheweixinxiguanli()
{
    delete ui;
}

void Wuyecheweixinxiguanli::value(){
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select number,addr,sellout,mark,user_id from park");
    model->setQuery(sql);
    model->setHeaderData(0,Qt::Horizontal,"车位编号");
    model->setHeaderData(1,Qt::Horizontal,"车位地址");
    model->setHeaderData(2,Qt::Horizontal,"是否租赁");
    model->setHeaderData(3,Qt::Horizontal,"车位级别");
    model->setHeaderData(4,Qt::Horizontal,"租赁者");
    ui->tableView->setModel(model);
}


void Wuyecheweixinxiguanli::on_addButton_clicked()
{
    QSqlQuery query;
    QString number = ui->numEdit->text();
    QString addr = ui->addrEdit->text();
    QString sellout;
    if(ui->yradioButton->isChecked()){
        sellout = "是";
    }else if (ui->nradioButton->isChecked()) {
        sellout = "否";
    }
    QString userid = ui->useridEdit->text();
    QString mark = ui->comboBox->currentText();

    if(number=="" || addr=="" || (ui->yradioButton->isChecked()==false&&ui->nradioButton->isChecked()==false)){
        QMessageBox::question(this,"错误提示","请填写全正确的所有信息",QMessageBox::Ok,QMessageBox::Ok);
    }else if (ui->yradioButton->isChecked()==true &&userid == "") {
        QMessageBox::question(this,"错误提示","请填写业主账号",QMessageBox::Ok,QMessageBox::Ok);
    }else if (ui->nradioButton->isChecked()==true && userid !="") {
        QMessageBox::question(this,"错误提示","请不要填写业主账号",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        QString sql = QString("insert into park values(null,'%1','%2','%3','%4','%5')").arg(number).arg(addr).arg(sellout).arg(userid).arg(mark);
        query.exec(sql);
        QMessageBox::question(this,"成功提示","添加车位信息成功！！！",QMessageBox::Ok,QMessageBox::Ok);
        ui->numEdit->clear();
        ui->addrEdit->clear();
        ui->useridEdit->clear();
    }
    value();

}

void Wuyecheweixinxiguanli::on_modifyButton_clicked()
{

    QSqlQuery query;
    QString number = ui->numEdit->text();
    QString addr = ui->addrEdit->text();
    QString sellout;
    if(ui->yradioButton->isChecked()){
        sellout = "是";
    }else if (ui->nradioButton->isChecked()) {
        sellout = "否";
    }
    QString userid = ui->useridEdit->text();
    QString mark = ui->comboBox->currentText();

    if(number=="" || addr=="" || (ui->yradioButton->isChecked()==false&&ui->nradioButton->isChecked()==false)){
        QMessageBox::question(this,"错误提示","请填写全正确的所有信息",QMessageBox::Ok,QMessageBox::Ok);
    }else if (ui->yradioButton->isChecked()==true &&userid == "") {
        QMessageBox::question(this,"错误提示","请填写业主账号",QMessageBox::Ok,QMessageBox::Ok);
    }else if (ui->nradioButton->isChecked()==true && userid !="") {
        QMessageBox::question(this,"错误提示","请不要填写业主账号",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        QString sql = QString("update park set addr='%1',sellout='%2',user_id='%3',mark='%5'where number='%4'").arg(addr).arg(sellout).arg(userid).arg(number).arg(mark);
        query.exec(sql);
        QMessageBox::question(this,"成功提示","修改车位信息成功！！！",QMessageBox::Ok,QMessageBox::Ok);
        ui->numEdit->clear();
        ui->addrEdit->clear();
        ui->useridEdit->clear();

    }

    value();

}

void Wuyecheweixinxiguanli::on_queryButton_clicked()
{
    QString number = ui->numEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    if(number != ""){
        QString sql = QString("select number,addr,sellout,user_id from park where number='%1'").arg(number);
        model->setQuery(sql);
        model->setHeaderData(0,Qt::Horizontal,"车位编号");
        model->setHeaderData(1,Qt::Horizontal,"车位地址");
        model->setHeaderData(2,Qt::Horizontal,"是否租赁");
        model->setHeaderData(3,Qt::Horizontal,"车位级别");
        model->setHeaderData(4,Qt::Horizontal,"租赁者");
        ui->tableView->setModel(model);
        ui->numEdit->clear();
        ui->addrEdit->clear();
        ui->useridEdit->clear();

    }else {
        QString sql = QString("select number,addr,sellout,user_id from park");
        model->setQuery(sql);
        model->setHeaderData(0,Qt::Horizontal,"车位编号");
        model->setHeaderData(1,Qt::Horizontal,"车位地址");
        model->setHeaderData(2,Qt::Horizontal,"是否租赁");
        model->setHeaderData(3,Qt::Horizontal,"车位级别");
        model->setHeaderData(4,Qt::Horizontal,"租赁者");
        ui->tableView->setModel(model);
        ui->numEdit->clear();
        ui->addrEdit->clear();
        ui->useridEdit->clear();

    }

}

void Wuyecheweixinxiguanli::on_delpushButton_clicked()
{
    QString number = ui->numEdit->text();
    if(number==""){
        QMessageBox::question(this,"错误提示","请输入正确的车位编号",QMessageBox::Ok,QMessageBox::Ok);
    }else {
        int re = QMessageBox::question(this,"删除提示","是否删除当前所选的车位信息？？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(re==QMessageBox::Yes){
            QString sql = QString("delete from park where number='%1'").arg(number);
            QSqlQuery query;
            query.exec(sql);
            value();
            QMessageBox::question(this,"删除提示","删除车位信息成功！！！",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
}
