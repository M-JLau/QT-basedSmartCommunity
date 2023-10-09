#include "yezhuguzhangchaxunpingjia.h"
#include "ui_yezhuguzhangchaxunpingjia.h"

extern int yonghuming;

Yezhuguzhangchaxunpingjia::Yezhuguzhangchaxunpingjia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhuguzhangchaxunpingjia)
{
    ui->setupUi(this);
}

Yezhuguzhangchaxunpingjia::~Yezhuguzhangchaxunpingjia()
{
    delete ui;
}

void Yezhuguzhangchaxunpingjia::on_pushButton_4_clicked()
{
        QString str=QString("select * from weixiu where 序号 = '%1'").arg(yonghuming);
        QSqlQuery query;
        query.exec(str);
        QString name,tel,add,pro,bao,jin,pin,money;
        while(query.next())
        {
            name=query.value(1).toString();
            tel=query.value(2).toString();
            add=query.value(3).toString();
            pro=query.value(4).toString();
            bao=query.value(5).toString();
            jin=query.value(6).toString();
            pin=query.value(7).toString();
            money=query.value(8).toString();
            ui->lineEdit->setText(name);
            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(add);
            ui->textEdit->setText(pro);
            ui->lineEdit_4->setText(bao);
            ui->lineEdit_5->setText(jin);
            ui->lineEdit_6->setText(pin);
            ui->lineEdit_7->setText(money);
            ui->lineEdit_4->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit_5->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit_7->setFocusPolicy(Qt::NoFocus);
        }
}

void Yezhuguzhangchaxunpingjia::on_pushButton_2_clicked()
{
    QString qingkuang = ui->lineEdit_4->text();
    QString jindu = ui->lineEdit_5->text();
    if(qingkuang == NULL || jindu == NULL){
        QMessageBox::information(NULL,"Fault","故障问题未维修，暂时不能进行评价!");
    }
    else{
        QString eval = ui->lineEdit_6->text();
        QString searchname = ui ->lineEdit->text();
        QString temp = QString("update weixiu set 维修评价 = '%1' where 姓名 = '%2'").arg(eval).arg(searchname);
        QSqlQuery query;
        query.exec(temp);
        QMessageBox::information(NULL,"Success"," 维修评价成功!!");
    }
}
