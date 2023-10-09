#include "guanliyuanrenshiguanli.h"
#include "ui_guanliyuanrenshiguanli.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

extern int yonghuming;


Guanliyuanrenshiguanli::Guanliyuanrenshiguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
     ui->comboBox->setCurrentIndex(3);
    //建立并打开数据库
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("ic.db");
//    if (!db.open()) {
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


Guanliyuanrenshiguanli::~Guanliyuanrenshiguanli()
{
    delete ui;
}


void Guanliyuanrenshiguanli::on_pushButton_clicked()
{
    QString searchname = ui->lineEdit_6->text();

    if(searchname == NULL)
    {
         QMessageBox::information(NULL,"fail"," 请输入需要查询人员的姓名！");
    }
    else
    {
        QString str = QString("select * from usrlist where name = '%1'").arg(searchname);
        QSqlQuery query;
        query.exec(str);
         QString id,tel,IDcard,pwd,name;
         int mark;
         while (query.next())
         {
             id = query.value(0).toString();
             tel = query.value(1).toString();
             IDcard =query.value(2).toString();
             pwd =  query.value(3).toString();
             mark = query.value(4).toInt();
             name = query.value(5).toString();
         }
        if((name != NULL)&&(mark==0))
        {
            ui->lineEdit->setText(name);
            ui->lineEdit_7->setText(id);
            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(IDcard);
            ui->lineEdit_4->setText(pwd);
            ui->comboBox->setCurrentIndex(3);

            ui->comboBox->setCurrentIndex(1);
            QMessageBox::information(NULL,"Success"," 查询成功!");
            ui->lineEdit_6->clear();
        }
        if((name != NULL)&&(mark==2))
        {
            ui->lineEdit->setText(name);
            ui->lineEdit_7->setText(id);
            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(IDcard);
            ui->lineEdit_4->setText(pwd);
            ui->comboBox->setCurrentIndex(3);

            ui->comboBox->setCurrentIndex(2);
            QMessageBox::information(NULL,"Success"," 查询成功!");
            ui->lineEdit_6->clear();
        }
        if((name != NULL)&&(mark==1))
        {
            ui->lineEdit->setText(name);
            ui->lineEdit_7->setText(id);
            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(IDcard);
            ui->lineEdit_4->setText(pwd);
           //  ui->lineEdit_5->setText(mark);

            ui->comboBox->setCurrentIndex(0);
            QMessageBox::information(NULL,"Success"," 查询成功!");
            ui->lineEdit_6->clear();


        }
 if(name == NULL)
 {
            ui->lineEdit->clear();
             ui->lineEdit_2->clear();
             ui->lineEdit_3->clear();
             ui->lineEdit_4->clear();
              ui->comboBox->setCurrentIndex(3);
             ui->lineEdit_6->clear();
             ui->lineEdit_7->clear();
             QString a = QString("没有叫%1的人，请重新输入人名").arg(searchname);
              QMessageBox::information(NULL,"fail",a);

        }
    }
}

void Guanliyuanrenshiguanli::on_pushButton_2_clicked()
{
    QString updatename = ui->lineEdit->text();
    QString updateid = ui->lineEdit_7->text();
    QString updatetel = ui->lineEdit_2->text();
    QString updateIDcard = ui->lineEdit_3->text();
     QString updatepwd = ui->lineEdit_4->text();
      QString updatemark = ui->comboBox->currentText();

      //QString total;
    //  var total=$('#total').combobox('getValue');

      if(updatename == NULL )
          {
               QMessageBox::information(NULL,"fail"," 请输入需要修改的人的信息");
          }
      else
      {
      QString temp = QString("select * from usrlist where name = '%1'").arg(updatename);

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
          ui->comboBox->setCurrentIndex(3);
          ui->lineEdit_7->clear();
      }
      else
      {

          QString state = ui->comboBox->currentText();
if(state=="业主")
    {
         QString temp = QString("update usrlist set id = '%1' ,tel = '%2' , IDcard = '%3', pwd = '%4', mark = '1' where name = '%5'").arg(updateid).arg(updatetel).arg(updateIDcard).arg(updatepwd).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
             ui->comboBox->setCurrentIndex(3);
            ui->lineEdit_7->clear();
            }
if(state=="物业管理员")
    {
         QString temp = QString("update usrlist set id = '%1' ,tel = '%2' , IDcard = '%3', pwd = '%4', mark = '0' where name = '%5'").arg(updateid).arg(updatetel).arg(updateIDcard).arg(updatepwd).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->comboBox->setCurrentIndex(3);
            ui->lineEdit_7->clear();
            }
if(state=="物业工作人员")
    {
         QString temp = QString("update usrlist set id = '%1' ,tel = '%2' , IDcard = '%3', pwd = '%4', mark = '2' where name = '%5'").arg(updateid).arg(updatetel).arg(updateIDcard).arg(updatepwd).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->comboBox->setCurrentIndex(3);
            ui->lineEdit_7->clear();
            }
        }
}
}

void Guanliyuanrenshiguanli::on_pushButton_3_clicked()
{

    QString id = ui->lineEdit_7->text();
    QString tel = ui->lineEdit_2->text();
    QString IDcard = ui->lineEdit_3->text();
    QString pwd = ui->lineEdit_4->text();
   // QString mark = ui->lineEdit_5->text();
    QString username = ui->lineEdit->text();
    QString mark = ui->comboBox->currentText();

   if(id == NULL || tel == NULL  || IDcard == NULL || pwd == NULL || mark == NULL || ui->lineEdit == NULL) //插入信息的时候需要输入完整的信息
    {
       QMessageBox::information(NULL,"fail "," 信息写入失败！！ 请输入完整的信息");
    }
   else

   {
        QString state= ui->comboBox->currentText();

       if(state == "业主")
        {
       QString str = QString("insert into usrlist (id,tel,IDcard,pwd,mark,name) values('%1','%2','%3','%4','1','%5') ").arg(id).arg(tel).arg(IDcard).arg(pwd).arg(username);
        QSqlQuery query;
        query.exec(str); //执行插入操作
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
       ui->comboBox->setCurrentIndex(3);
        ui->lineEdit_7->clear();
        QMessageBox::information(NULL,"Success"," 信息写入成功！！");
       }
        if(state == "物业管理员")
            {
        QString str = QString("insert into usrlist (id,tel,IDcard,pwd,mark,name) values('%1','%2','%3','%4','0','%5') ").arg(id).arg(tel).arg(IDcard).arg(pwd).arg(username);
         QSqlQuery query;
         query.exec(str); //执行插入操作
         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();
        ui->comboBox->setCurrentIndex(3);
         ui->lineEdit_7->clear();
         QMessageBox::information(NULL,"Success"," 信息写入成功！！");
        }
        if(state == "物业工作人员")
            {
        QString str = QString("insert into usrlist (id,tel,IDcard,pwd,mark,name) values('%1','%2','%3','%4','2','%5') ").arg(id).arg(tel).arg(IDcard).arg(pwd).arg(username);
         QSqlQuery query;
         query.exec(str); //执行插入操作
         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();
        ui->comboBox->setCurrentIndex(3);
         ui->lineEdit_7->clear();
         QMessageBox::information(NULL,"Success"," 信息写入成功！！");
   }
}
   }


void Guanliyuanrenshiguanli::on_pushButton_4_clicked()
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
            ui->comboBox->setCurrentIndex(3);
            ui->lineEdit_7->clear();
            QString a = QString("没有叫%1的人，删除失败").arg(name);
            QMessageBox::information(NULL,"fail",a);
        }
        else
        {
            QString str =  QString("delete from usrlist where name = '%1'").arg(name);
            query.exec(str);//删除信息

            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
             ui->comboBox->setCurrentIndex(3);
            ui->lineEdit_7->clear();
            QMessageBox::information(NULL,"Success"," 信息删除成功！！");
        }
    }
}
