#include "wuyerenyuanguanli.h"
#include "ui_wuyerenyuanguanli.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

extern int yonghuming;

Wuyerenyuanguanli::Wuyerenyuanguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyerenyuanguanli)
{
    ui->setupUi(this);
}

Wuyerenyuanguanli::~Wuyerenyuanguanli()
{
    delete ui;
}

void Wuyerenyuanguanli::on_pushButton_clicked()//数据查询
{
    QString searchname = ui->lineEdit_6->text();

    if(searchname == NULL)
    {
         QMessageBox::information(NULL,"fail"," 请输入需要查询的业主名！");
    }
    else
    {
        QString str = QString("select * from yezhu where name = '%1'").arg(searchname);
        QSqlQuery query;
        query.exec(str);
         QString name,age,sex,tel,address;
         while (query.next())
         {
             name = query.value(1).toString();
             age = query.value(2).toString();
             sex=query.value(3).toString();
             tel =  query.value(4).toString();
             address = query.value(5).toString();
           }

        if(name == NULL)
        {

             ui->lineEdit->clear();
             ui->lineEdit_2->clear();
             ui->lineEdit_3->clear();
             ui->lineEdit_4->clear();
             ui->lineEdit_5->clear();
             ui->lineEdit_7->clear();
             QString a = QString("没有叫%1的人，请重新输入人名").arg(searchname);
              QMessageBox::information(NULL,"fail",a);
        }

    else
        {



            ui->lineEdit->setText(name);
            ui->lineEdit_2->setText(age);
            ui->lineEdit_3->setText(sex);
            ui->lineEdit_4->setText(tel);
            ui->lineEdit_5->setText(address);
            ui->lineEdit_7->setText("查询成功!!");
            ui->lineEdit_6->clear();



        }
    }
}


void Wuyerenyuanguanli::on_pushButton_2_clicked()//增加数据
{
    QString username = ui->lineEdit->text();
    QString age = ui->lineEdit_2->text();
    QString sex = ui->lineEdit_3->text();
    QString tel = ui->lineEdit_4->text();
    QString address = ui->lineEdit_5->text();
   // QString str = QString("insert into user (name,age,sex,tel,address) values('%1','%2','%3','%4','%5') ").arg(username).arg(age).arg(sex).arg(tel).arg(address);
    if(username == NULL || age == NULL || sex == NULL || tel == NULL || ui->lineEdit_5 == NULL) //插入信息的时候需要输入完整的信息
    {
        QMessageBox::information(NULL,"fail "," 信息写入失败！！ 请输入完整的信息");
    }
    else
    {
       QString str = QString("insert into yezhu (name,age,sex,tel,address) values('%1','%2','%3','%4','%5') ").arg(username).arg(age).arg(sex).arg(tel).arg(address);
        QSqlQuery query;
        query.exec(str); //执行插入操作
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        QMessageBox::information(NULL,"Success"," 信息写入成功！！");
    }

}

void Wuyerenyuanguanli::on_pushButton_3_clicked()//修改数据
{
    QString updatename = ui->lineEdit->text();
    QString updateage = ui->lineEdit_2->text();
    QString updatesex = ui->lineEdit_3->text();
     QString updatetel = ui->lineEdit_4->text();
      QString updateaddress = ui->lineEdit_5->text();
      if(updatename == NULL )
          {
               QMessageBox::information(NULL,"fail"," 请输入需要修改的人的名字、年龄、性别、手机号、住址");
          }
      else
      {
      QString temp = QString("select * from yezhu where name = '%1'").arg(updatename);

      QSqlQuery query;
      query.exec(temp);// 查询信息
      QString c;
      while (query.next())
      {
          c = query.value(1).toString();
      }
      if(c == NULL)
      {
          QString b = QString("没有名叫%1的人，修改失败").arg(updatename);
          QMessageBox::information(NULL,"fail",b);
          ui->lineEdit->clear();
          ui->lineEdit_2->clear();
          ui->lineEdit_3->clear();
          ui->lineEdit_4->clear();
          ui->lineEdit_5->clear();
      }
      else
      {

         QString temp = QString("update yezhu set age = '%1' , sex = '%2', tel = '%3', address = '%4' where name = '%5'").arg(updateage).arg(updatesex).arg(updatetel).arg(updateaddress).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
        }
}
}

void Wuyerenyuanguanli::on_pushButton_5_clicked()//删除数据
{
    QString name = ui->lineEdit->text();
    if(name ==  NULL)
    {
        QMessageBox::information(NULL,"fail"," 请输入需要删除的人的名字");//删除的时候需要输入姓名
    }
    else
    {
        //从数据库中查询是否有这个人
        QSqlQuery query;
        QString temp =  QString("select * from yezhu where name = '%1'").arg(name);
        query.exec(temp);
        QString deletename;
        while (query.next())
        {
            deletename = query.value(1).toString();
        }
        if(deletename == NULL)
        {
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            QString a = QString("没有叫%1的人，删除失败").arg(name);
            QMessageBox::information(NULL,"fail",a);
        }
        else
        {
            QString str =  QString("delete from yezhu where name = '%1'").arg(name);
            query.exec(str);//删除信息

            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            QMessageBox::information(NULL,"Success"," 信息删除成功！！");
        }
    }
}

void Wuyerenyuanguanli::on_pushButton_6_clicked()//查询所有数据
{
   QString name[100];//用来存储从数据库中找出来的信息
    QString sex[100];
    QString age[100];
    QString tel[100];
     QString address[100];
    int i = 0;
    QSqlQuery query;
    query.exec("select * from yezhu");//查询所有的信息
    while(query.next())
    {
        name[i] = query.value(1).toString();
        age[i] = query.value(2).toString();
        sex[i] = query.value(3).toString();
        tel[i] = query.value(4).toString();
        address[i] = query.value(5).toString();
        i++;
    }
    ui->textEdit->clear();
    int j = 0;
    for(j = 0; j < i; j++)//将这些信息都显示在下方的文本编辑框中
    {
        QString str = QString("姓名：%1 年龄：%2 性别：%3 手机号：%4 住址：%5").arg(name[j]).arg(age[j]).arg(sex[j]).arg(tel[j]).arg(address[j]);
        ui->textEdit->append(str);
    }



}


