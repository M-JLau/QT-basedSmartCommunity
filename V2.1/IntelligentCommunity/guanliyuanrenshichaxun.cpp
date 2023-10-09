#include "guanliyuanrenshichaxun.h"
#include "ui_guanliyuanrenshichaxun.h"

Guanliyuanrenshichaxun::Guanliyuanrenshichaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guanliyuanrenshichaxun)
{
    ui->setupUi(this);
//    /**连接数据库**/
//        db=QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("wuye.db");
//        if(!db.open()){
//            QMessageBox::information(NULL,"提示","数据库连接失败",QMessageBox::Ok);
//        }else{
//            QMessageBox::information(NULL,"提示","数据库连接成功",QMessageBox::Ok);
//        }
}

Guanliyuanrenshichaxun::~Guanliyuanrenshichaxun()
{
    delete ui;
}

void Guanliyuanrenshichaxun::on_pushButton_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("usrlist");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0,Qt::Horizontal,"登录账号");
    model->setHeaderData(1,Qt::Horizontal,"手机号");
    model->setHeaderData(2,Qt::Horizontal,"身份证号");
    model->setHeaderData(3,Qt::Horizontal,"密码");
    model->setHeaderData(4,Qt::Horizontal,"身份标识");
    model->setHeaderData(5,Qt::Horizontal,"姓名");
    ui->tableView->setModel(model);
}
