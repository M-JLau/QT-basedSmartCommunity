#include "wuyeweixiuguanli.h"
#include "ui_wuyeweixiuguanli.h"

extern int yonghuming;

Wuyeweixiuguanli::Wuyeweixiuguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeweixiuguanli)
{
    ui->setupUi(this);
}

Wuyeweixiuguanli::~Wuyeweixiuguanli()
{
    delete ui;
}

void Wuyeweixiuguanli::on_pushButton_clicked()
{
          model = new QSqlTableModel(this);
          model->setTable("weixiu");
          model->select();
          model->setEditStrategy(QSqlTableModel::OnManualSubmit);
          model->setHeaderData(3,Qt::Horizontal,"报修地址");
          ui->tableView->setModel(model);

}

void Wuyeweixiuguanli::on_pushButton_3_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model->revertAll();
    } else { // 否则提交，在数据库中删除该行
        model->submitAll();
    }
}

void Wuyeweixiuguanli::on_pushButton_4_clicked()
{
    QString searchname = ui->lineEdit->text();
    if(searchname==NULL)
    {
         QMessageBox::information(NULL,"提示","请输入查询姓名",QMessageBox::Ok);
    }
    else
    {
        QString str=QString("select * from weixiu where 姓名 = '%1'").arg(searchname);
        QSqlQuery query;
        if(!query.exec(str))
        {
            qDebug()<<"there is not a table of weixiu in mysql"<<query.lastError();
        }
        QString tel,add,pro,bao,jin,pin,money;
        while(query.next())
        {
            tel=query.value(2).toString();
            add=query.value(3).toString();
            pro=query.value(4).toString();
            bao=query.value(5).toString();
            jin=query.value(6).toString();
            pin=query.value(7).toString();
            money=query.value(8).toString();

            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(add);
            ui->textEdit->setText(pro);
            ui->lineEdit_4->setText(bao);
            ui->lineEdit_5->setText(jin);
            ui->lineEdit_6->setText(pin);
            ui->textEdit->setReadOnly(true);
            ui->lineEdit_7->setText(money);
            ui->lineEdit_6->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit_2->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit_3->setFocusPolicy(Qt::NoFocus);
        }
        QMessageBox::information(NULL,"success","查询成功",QMessageBox::Ok);
    }
}

void Wuyeweixiuguanli::on_pushButton_2_clicked()
{
    QString qingkuang = ui->lineEdit_4->text();
    QString jindu = ui->lineEdit_5->text();
    QString money = ui->lineEdit_7->text();
    QString searchname = ui->lineEdit->text();
    if(searchname == NULL )
    {
         QMessageBox::information(NULL,"fail"," 请输入需要修改的人的姓名、情况、进度");
    }
    else
    {
         QString temp = QString("update weixiu set 受理情况 = '%1' , 维修进度 = '%2' , 价格 = '%3' where 姓名 = '%4'").arg(qingkuang).arg(jindu).arg(money).arg(searchname);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");

        }
}

