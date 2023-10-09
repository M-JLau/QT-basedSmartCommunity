#include "yezhuguzhuangbaoxiu.h"
#include "ui_yezhuguzhuangbaoxiu.h"

extern int yonghuming;

Yezhuguzhuangbaoxiu::Yezhuguzhuangbaoxiu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhuguzhuangbaoxiu)
{
    ui->setupUi(this);
}

Yezhuguzhuangbaoxiu::~Yezhuguzhuangbaoxiu()
{
    delete ui;
}

void Yezhuguzhuangbaoxiu::on_pushButton_2_clicked()//业主故障报修
{
    QString issue = ui->textEdit->toPlainText();
    QString address = ui->lineEdit->text();

    if(issue==NULL){
        QMessageBox::information(NULL,"Fault","请填写故障问题!!");
    }
    else{
        QString str=QString("select * from usrlist where id = '%1'").arg(yonghuming);
        QSqlQuery query;
        query.exec(str);
        QString namee,tell,idd;
        while(query.next())
        {
            idd=query.value(0).toString();
            namee=query.value(5).toString();
            tell=query.value(1).toString();
        }
        QString temp = QString("insert into weixiu (序号,姓名,电话,地址,问题描述) values('%1','%2','%3','%4','%5')").arg(idd).arg(namee).arg(tell).arg(address).arg(issue);
        QSqlQuery query1;
        query1.exec(temp);
        QMessageBox::information(NULL,"Success"," 故障报修成功!!");
    }
}
