#include "wuyezengjiaxinxi.h"
#include "ui_wuyezengjiaxinxi.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QComboBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

wuyezengjiaxinxi::wuyezengjiaxinxi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wuyezengjiaxinxi)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    //建立并打开数据库
//       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//       db.setDatabaseName("wuye.db");
//   if (!db.open()) {
//        QMessageBox::critical(nullptr, QObject::tr("未找到需要的数据库文件"),
//            QObject::tr("不能建立链接n.\n"
//                        "This example needs SQLite support. Please read "
//                        "the Qt SQL driver documentation for information how "
//                        "to build it.\n\n"
//                        "Click Cancel to exit."), QMessageBox::Cancel);
//    }else{
//        qDebug()<<"数据库打开成功！ "<<endl;
//      //  ui->label_data->setText(tr("数据库打开成功"));
//    }
}

wuyezengjiaxinxi::~wuyezengjiaxinxi()
{
    delete ui;
}

void wuyezengjiaxinxi::on_pushButton_clicked()
{
    QString searchname = ui->lineEdit_9->text();

    if(searchname == NULL)
    {
         QMessageBox::information(NULL,"fail"," 请输入需要查询人员的姓名！");
    }
    else
    {
        QString str = QString("select * from usrlist where name = '%1'").arg(searchname);

        QSqlQuery query;

        query.exec(str);
         QString name,id,tel,IDcard,pwd;
        int mark;
        int mark1 = 1;
         while (query.next())
         {
             mark= query.value(4).toInt();
             if(mark == 1){
             id = query.value(0).toString();
             tel = query.value(1).toString();
             IDcard =query.value(2).toString();
             pwd =  query.value(3).toString();
             name = query.value(5).toString();
             }else{
                 QString b = QString("没有叫%1的业主，请输入正确的业主名！").arg(searchname);
                 ui->lineEdit->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();
                 ui->lineEdit_4->clear();
                 ui->lineEdit_5->clear();
                 ui->comboBox->setCurrentIndex(0);
                 ui->comboBox_2->setCurrentIndex(0);
               //  ui->lineEdit_6->clear();
                 ui->lineEdit_7->clear();
                 ui->lineEdit_8->clear();
                 // ui->lineEdit_10->clear();
                 QMessageBox::information(NULL,"fail",b);
                  mark1 = 2;

             }
           }

          QString str1 = QString("select * from yezhu where name = '%1'").arg(searchname);
        // QSqlQuery query;
         query.exec(str1);
          QString sex,age,address,addressmk;
          while (query.next())
          {
              sex = query.value(3).toString();
              age = query.value(2).toString();
              address =query.value(4).toString();
              addressmk = query.value(5).toString();
            }

        if((name == NULL)&&(mark1 == 1))
        {
             ui->lineEdit->clear();
             ui->lineEdit_2->clear();
             ui->lineEdit_3->clear();
             ui->lineEdit_4->clear();
             ui->lineEdit_5->clear();
             ui->comboBox->setCurrentIndex(0);
             ui->comboBox_2->setCurrentIndex(0);
             ui->lineEdit_7->clear();
             ui->lineEdit_8->clear();

             QString a = QString("没有叫%1的业主，请输入正确的业主名！").arg(searchname);
              QMessageBox::information(NULL,"fail",a);

        }
    if(name != NULL)
        {
            ui->lineEdit->setText(name);
            ui->lineEdit_2->setText(id);
            ui->lineEdit_3->setText(tel);
            ui->lineEdit_4->setText(IDcard);
            ui->lineEdit_5->setText(pwd);
            ui->comboBox->setCurrentText(sex);
            ui->lineEdit_7->setText(age);
            ui->lineEdit_8->setText(address);
            ui->comboBox_2->setCurrentText(addressmk);


            ui->lineEdit_9->clear();
            QMessageBox::information(NULL,"Success"," 信息查询成功!!");

}


}
    }


void wuyezengjiaxinxi::on_pushButton_2_clicked()
{
    QString username = ui->lineEdit->text();
   QString id = ui->lineEdit_2->text();
    QString tel = ui->lineEdit_3->text();
    QString IDcard = ui->lineEdit_4->text();
    QString pwd = ui->lineEdit_5->text();
  //QString sex = ui->lineEdit_6->text();
  QString age = ui->lineEdit_7->text();
   QString address = ui->lineEdit_8->text();
//QString addressmk = ui->lineEdit_10->text();
QString sex = ui->comboBox->currentText();
QString addressmk = ui->comboBox_2->currentText();
   if( username == NULL || id == NULL || tel == NULL  || IDcard == NULL ||  pwd == NULL ||  sex == NULL  || age == NULL || address == NULL|| addressmk == NULL ) //插入信息的时候需要输入完整的信息

    {
       QMessageBox::information(NULL,"fail "," 信息写入失败！！ 请输入完整的信息");
    }
   else
   {

       QString str = QString("insert into usrlist (id,tel,IDcard,pwd,mark,name) values('%1','%2','%3','%4','1','%5') ").arg(id).arg(tel).arg(IDcard).arg(pwd).arg(username);

       QString str1 = QString("insert into yezhu (id,name,age,sex,address,addressmk) values('%1','%2','%3','%4','%5','%6') ").arg(id).arg(username).arg(age).arg(sex).arg(address).arg(addressmk);
        QSqlQuery query;
        query.exec(str); //执行插入操作
        query.exec(str1);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
       // ui->lineEdit_6->clear();
       ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
         //ui->lineEdit_10->clear();
         ui->comboBox->setCurrentIndex(0);
         ui->comboBox_2->setCurrentIndex(0);
        QMessageBox::information(NULL,"Success"," 信息写入成功！！");
   }
}

void wuyezengjiaxinxi::on_pushButton_3_clicked()
{
    QString updatename = ui->lineEdit->text();
    QString updateid = ui->lineEdit_2->text();
    QString updatetel = ui->lineEdit_3->text();
    QString updateIDcard = ui->lineEdit_4->text();
    QString updatepwd = ui->lineEdit_5->text();
   // QString updatesex = ui->lineEdit_6->text();
    QString updateage = ui->lineEdit_7->text();
    QString updateaddress = ui->lineEdit_8->text();
   // QString updateaddressmk = ui->lineEdit_10->text();
    QString updatesex = ui->comboBox->currentText();
     QString updateaddressmk  = ui->comboBox_2->currentText();
      if(updatename == NULL )
          {
               QMessageBox::information(NULL,"fail"," 请输入需要修改的人的信息");
          }
      else
      {
      QString temp = QString("select * from usrlist where name = '%1'").arg(updatename);
      QString temp1 = QString("select * from yezhu where name = '%1'").arg(updatename);


      QSqlQuery query;
      query.exec(temp);// 查询信息
      query.exec(temp1);
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
         // ui->lineEdit_6->clear();
          ui->lineEdit_7->clear();
          ui->lineEdit_8->clear();
          //ui->lineEdit_10->clear();
          ui->comboBox->setCurrentIndex(0);
          ui->comboBox_2->setCurrentIndex(0);
      }
      else
      {

         QString temp = QString("update usrlist set id = '%1' ,tel = '%2' , IDcard = '%3', pwd = '%4' where name = '%5'").arg(updateid).arg(updatetel).arg(updateIDcard).arg(updatepwd).arg(updatename);
         QString temp1 = QString("update yezhu set id = '%1',sex = '%2' ,age = '%3' , address = '%4',addressmk = '%5' where name = '%6'").arg(updateid).arg(updatesex).arg(updateage).arg(updateaddress).arg(updateaddressmk).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         query.exec(temp1);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
           // ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
            // ui->lineEdit_10->clear();
            ui->comboBox->setCurrentIndex(0);
            ui->comboBox_2->setCurrentIndex(0);
        }
}
}

void wuyezengjiaxinxi::on_pushButton_4_clicked()
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
        QString temp =  QString("select * from usrlist where name = '%1'").arg(name);
        QString temp1 =  QString("select * from usrlist where name = '%1'").arg(name);
        query.exec(temp);
        query.exec(temp1);
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
            //ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
           //  ui->lineEdit_10->clear();
             ui->comboBox->setCurrentIndex(0);
             ui->comboBox_2->setCurrentIndex(0);
            QString a = QString("没有叫%1的人，删除失败").arg(name);
            QMessageBox::information(NULL,"fail",a);
        }
        else
        {
            QString str =  QString("delete from usrlist where name = '%1'").arg(name);
            query.exec(str);//删除信息
            QString str1 =  QString("delete from yezhu where name = '%1'").arg(name);
            query.exec(str1);//删除信息

            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            //ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
            // ui->lineEdit_10->clear();
            ui->comboBox->setCurrentIndex(0);
            ui->comboBox_2->setCurrentIndex(0);
            QMessageBox::information(NULL,"Success"," 信息删除成功！！");
        }
    }
}




void wuyezengjiaxinxi::on_pushButton_5_clicked()
{
    QString name[100];//用来存储从数据库中找出来的信息
    QString id[100];
    QString tel[100];
    QString IDcard[100];
    QString pwd[100];
    QString age[100];
    QString sex[100];
    QString address[100];
    QString addressmk[100];
     int i = 0;
      int a = 0;
     int mark;
     QSqlQuery query;

     query.exec("select * from usrlist where mark == 1");//查询所有的信息
    // query1.exec("select * from yezhu");//查询所有的信息
     while(query.next())
     {
         name[i] = query.value(5).toString();
         id[i] = query.value(0).toString();
         tel[i] = query.value(1).toString();
         IDcard[i] = query.value(2).toString();
         pwd[i] = query.value(3).toString();
         i++;
     }


     query.exec("select * from yezhu");//查询所有的信息
     while(query.next())

{
         age[a] = query.value(2).toString();
         sex[a] = query.value(3).toString();
         address[a] = query.value(4).toString();
         addressmk[a] = query.value(5).toString();
         a++;
 }
     ui->textEdit->clear();
     int j = 0;


     for(j = 0; j <i; j++)//将这些信息都显示在下方的文本编辑框中
     {
         QString str = QString("姓名：%1 登录账号：%2 手机号：%3 身份证号：%4 密码：%5 年龄：%6 性别：%7 住址：%8 房产类型：%9").arg(name[j]).arg(id[j]).arg(tel[j]).arg(IDcard[j]).arg(pwd[j]).arg(age[j]).arg(sex[j]).arg(address[j]).arg(addressmk[j]);
         ui->textEdit->append(str);
     }

}



