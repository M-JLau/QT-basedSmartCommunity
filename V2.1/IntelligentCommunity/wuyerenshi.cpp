#include "wuyerenshi.h"
#include "ui_wuyerenshi.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>


Wuyerenshi::Wuyerenshi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyerenshi)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("yezhu.db");
        if (!db.open()) {
            QMessageBox::critical(nullptr, QObject::tr("未找到需要的数据库文件"),
                QObject::tr("不能建立链接n.\n"
                            "This example needs SQLite support. Please read "
                            "the Qt SQL driver documentation for information how "
                            "to build it.\n\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        }else{
            qDebug()<<"数据库打开成功！ "<<endl;
          //  ui->label_data->setText(tr("数据库打开成功"));
        }
}

Wuyerenshi::~Wuyerenshi()
{
    delete ui;
}
void Wuyerenshi::on_pushButton_clicked()//数据查询
{
    QString searchname = ui->lineEdit_6->text();

    if(searchname == NULL)
    {
         QMessageBox::information(NULL,"fail"," 请输入需要查询的业主名！");
    }
    else
    {
        QString str = QString("select * from user where name = '%1'").arg(searchname);
        QSqlQuery query;
        query.exec(str);
         QString name,age,sex,tel,address;
         while (query.next())
         {
             name = query.value(0).toString();
             age = query.value(1).toString();
             sex=query.value(2).toString();
             tel =  query.value(3).toString();
             address = query.value(4).toString();
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

            qDebug()<<"name"<<name<<age<<sex<<tel<<address;

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


void Wuyerenshi::on_pushButton_2_clicked()//增加数据
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
       QString str = QString("insert into user (name,age,sex,tel,address) values('%1','%2','%3','%4','%5') ").arg(username).arg(age).arg(sex).arg(tel).arg(address);
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

void Wuyerenshi::on_pushButton_3_clicked()//修改数据
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
      QString temp = QString("select * from user where name = '%1'").arg(updatename);

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

         QString temp = QString("update user set age = '%1' , sex = '%2', tel = '%3', address = '%4' where name = '%5'").arg(updateage).arg(updatesex).arg(updatetel).arg(updateaddress).arg(updatename);
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

void Wuyerenshi::on_pushButton_5_clicked()//删除数据
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
        QString temp =  QString("select * from user where name = '%1'").arg(name);
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
            QString str =  QString("delete from user where name = '%1'").arg(name);
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

void Wuyerenshi::on_pushButton_6_clicked()//查询所有数据
{
   QString name[100];//用来存储从数据库中找出来的信息
    QString sex[100];
    QString age[100];
    QString tel[100];
     QString address[100];
    int i = 0;
    QSqlQuery query;
    query.exec("select * from user");//查询所有的信息
    while(query.next())
    {
        name[i] = query.value(0).toString();
        age[i] = query.value(1).toString();
        sex[i] = query.value(2).toString();
        tel[i] = query.value(3).toString();
        address[i] = query.value(4).toString();
        i++;
    }
    ui->textEdit->clear();
    int j = 0;
    for(j = 0; j < i; j++)//将这些信息都显示在下方的文本编辑框中
    {
        QString str = QString("姓名：%1 年龄：%2 性别：%3 手机号：%4 住址：%5").arg(name[j]).arg(age[j]).arg(sex[j]).arg(tel[j]).arg(address[j]);
        ui->textEdit->append(str);
    }

      /* QString name = ui->lineEdit->text();
       QSqlQueryModel *model = new QSqlQueryModel(this);
       QString sql = QString("select age,sex,tel,address from user where name='%1'").arg(name);
       model->setQuery(sql);
       qDebug()<<model->rowCount();
       model->setHeaderData(0,Qt::Horizontal,"姓名");
       model->setHeaderData(1,Qt::Horizontal,"年龄");
       model->setHeaderData(2,Qt::Horizontal,"性别");
       model->setHeaderData(3,Qt::Horizontal,"手机号");
       model->setHeaderData(4,Qt::Horizontal,"住址");
        ui->textEdit->append(model);
      // ui->textEdit->setTaber(model);
       // db.close();*/

}
