#include "wuyejiagewihu.h"
#include "ui_wuyejiagewihu.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

Wuyejiagewihu::Wuyejiagewihu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyejiagewihu)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString sql = QString("select typer.type,typer.danjia,wuye.type,wuye.size from typer inner join wuye on wuye.id=typer.typeid  ");
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"类型");
    model->setHeaderData(1,Qt::Horizontal,"单价(元/平方米)");
    model->setHeaderData(2,Qt::Horizontal,"户型");
    model->setHeaderData(3,Qt::Horizontal,"面积（平方米）");
    ui->tableView->setModel(model);
}

Wuyejiagewihu::~Wuyejiagewihu()
{
    delete ui;
}


void Wuyejiagewihu::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    if(arg1 == "物业费")
    {

        QString sql = QString("select typer.type,typer.danjia,wuye.type,wuye.size from typer inner join wuye on wuye.id=typer.typeid  ");
        model->setQuery(sql);
        qDebug()<<model->rowCount();
        model->setHeaderData(0,Qt::Horizontal,"类型");
        model->setHeaderData(1,Qt::Horizontal,"单价(元/平方米)");
        model->setHeaderData(2,Qt::Horizontal,"户型");
        model->setHeaderData(3,Qt::Horizontal,"面积（平方米）");
        ui->tableView->setModel(model);
    }
    else if(arg1 == "车位费")
    {

        QString sql = QString("select typer.type,chewei.type,chewei.money from typer inner join chewei on chewei.id=typer.typeid  ");
        model->setQuery(sql);
        qDebug()<<model->rowCount();
        model->setHeaderData(0,Qt::Horizontal,"类型");
        model->setHeaderData(1,Qt::Horizontal,"车位类型");
        model->setHeaderData(2,Qt::Horizontal,"车位费（元）");
        ui->tableView->setModel(model);
    }
}

void Wuyejiagewihu::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString type = ui->comboBox_2->currentText();
    QString type1 = ui->comboBox_3->currentText();
    QString edit = ui->lineEdit->text();
    if(type == "物业费")
        {

        QString sql = QString("update typer set danjia = '%1' where typeid = %2 ").arg(edit).arg("1");
        model->setQuery(sql);
        QSqlQueryModel *model1 = new QSqlQueryModel(this);
        QString sql1 = QString("select typer.type,typer.danjia,wuye.type,wuye.size from typer inner join wuye on wuye.id=typer.typeid  ");
        model1->setQuery(sql1);
        qDebug()<<model->rowCount();
        model1->setHeaderData(0,Qt::Horizontal,"类型");
        model1->setHeaderData(1,Qt::Horizontal,"单价(元/平方米)");
        model1->setHeaderData(2,Qt::Horizontal,"户型");
        model1->setHeaderData(3,Qt::Horizontal,"面积（平方米）");
        ui->tableView->setModel(model1);
        ui->comboBox->setCurrentIndex(0);
    }
    else
    {

        if(type1 == "  A 类型")
            {
            QString sql = QString("update chewei set money = '%1' where type = '%2' ").arg(edit).arg("A类型");
            model->setQuery(sql);
        }
        else if(type1 == "  B 类型")
            {
            QString sql = QString("update chewei set money = '%1' where type = '%2' ").arg(edit).arg("B类型");
            model->setQuery(sql);
        }
        else if(type1 == "  C 类型")
            {
            QString sql = QString("update chewei set money = '%1' where type = '%2' ").arg(edit).arg("C类型");
            model->setQuery(sql);
        }
        QSqlQueryModel *model1 = new QSqlQueryModel(this);
        QString sql1 = QString("select typer.type,chewei.type,chewei.money from typer inner join chewei on chewei.id=typer.typeid  ");
        model1->setQuery(sql1);
        qDebug()<<model->rowCount();
        model1->setHeaderData(0,Qt::Horizontal,"类型");
        model1->setHeaderData(1,Qt::Horizontal,"车位类型");
        model1->setHeaderData(2,Qt::Horizontal,"车位费（元）");
        ui->tableView->setModel(model1);
        ui->comboBox->setCurrentIndex(1);
    }
    QMessageBox::information(this,tr("提示"),tr("修改成功！"),QMessageBox::Ok);
}

void Wuyejiagewihu::on_pushButton_2_clicked()
{
    QString id[100];//用来存储从数据库中找出来的信息
    QString name[100];
    //QString type[100];
    QString number[100];
    QString number2[100];
    QString number4[100];
    QDate dateEdit=ui->dateEdit->date();
    QString date = dateEdit.toString("yyyy-MM-dd");

    int i = 0;
    int number3,number5;
    QSqlQuery query;
    query.exec("select usrlist.id,usrlist.name from usrlist where mark = 1");//查询所有的信息
    while(query.next())
    {

        id[i] = query.value(0).toString();
        name[i] = query.value(1).toString();

        i++;
    }

    QSqlQuery query1,query2,query3,query4;
    int j = 0;
    for(j = 0; j < i; j++)//将这些信息都显示在下方的文本编辑框中
    {
        float size1,danjia1;
        QString danjia = QString("select typer.danjia from yezhu inner join wuye on yezhu.addressmk=wuye.type join typer on wuye.id = typer.typeid where yezhu.id=%1").arg(id[j]);
        query1.exec(danjia);
        while(query1.next())
        {
        danjia1 = query1.value(0).toFloat();
        }
        QString  size= QString("select wuye.size from yezhu inner join wuye on yezhu.addressmk=wuye.type join typer on wuye.id = typer.typeid where yezhu.id=%1").arg(id[j]);
        query2.exec(size);

        while(query2.next())
        {
         size1 = query2.value(0).toFloat();
        }
        float number1 = danjia1 * size1;
        number[j]=QString::number(number1);
        QString a =  QString("select weixiu.价格 from weixiu where 序号=%1").arg(id[j]);
        query3.exec(a);
        while(query3.next())
        {
        number3 = query3.value(0).toInt();
        }
        if(number3!=NULL)
        {
        number2[j]=QString::number(number3);
        }
        QString b =  QString("select chewei.money from chewei inner join park on chewei.type = park.mark where user_id=%1").arg(id[j]);
        query4.exec(b);
        while(query4.next())
        {
        number5 = query4.value(0).toInt();
        }
        if(number5!=NULL)
        {
        number4[j]=QString::number(number5);
        }
        QSqlQueryModel *model = new QSqlQueryModel(this);
        QSqlQueryModel *model1 = new QSqlQueryModel(this);
        QSqlQueryModel *model2 = new QSqlQueryModel(this);
        QString str = QString("insert into payment values (%1,'%2','%3','%4','%5','%6')").arg(id[j]).arg(name[j]).arg("物业费").arg(number[j]).arg(date).arg("否");
        QString str1 = QString("insert into payment values (%1,'%2','%3','%4','%5','%6')").arg(id[j]).arg(name[j]).arg("维修费").arg(number2[j]).arg(date).arg("否");
        QString str2 = QString("insert into payment values (%1,'%2','%3','%4','%5','%6')").arg(id[j]).arg(name[j]).arg("车位费").arg(number4[j]).arg(date).arg("否");
        model->setQuery(str);
        model1->setQuery(str1);
        model2->setQuery(str2);
        QMessageBox::information(this,tr("提示"),tr("缴费信息发布成功！"),QMessageBox::Ok);
    }
}
