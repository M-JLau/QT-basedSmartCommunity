#include "wuyejiaofeiguanli.h"
#include "ui_wuyejiaofeiguanli.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QLineEdit>

extern int yonghuming;

Wuyejiaofeiguanli::Wuyejiaofeiguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyejiaofeiguanli)
{
    ui->setupUi(this);

    //建立并打开数据库
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("jiaofeixinxi.db");
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

Wuyejiaofeiguanli::~Wuyejiaofeiguanli()
{
    delete ui;
}
void Wuyejiaofeiguanli::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString id = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QDate dateEdit=ui->dateEdit->date();
    QString date = dateEdit.toString("yyyy-MM-dd");
    QString state = ui->comboBox_2->currentText();
    if(state=="所有业主")
    {
    QString sql = QString("select * from payment where payment.type = '%1' and payment.date = '%2'").arg(type).arg(date);
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"账号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"缴费类型");
    model->setHeaderData(3,Qt::Horizontal,"缴费数量");
    model->setHeaderData(4,Qt::Horizontal,"缴费日期");
    model->setHeaderData(5,Qt::Horizontal,"是否缴费");
    ui->tableView->setModel(model);
    }
    else
    {
    QString sql = QString("select * from payment where type = '%1' and date = '%2' and id =%3").arg(type).arg(date).arg(id);
    model->setQuery(sql);
    qDebug()<<model->rowCount();
    model->setHeaderData(0,Qt::Horizontal,"账号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"缴费类型");
    model->setHeaderData(3,Qt::Horizontal,"缴费数量");
    model->setHeaderData(4,Qt::Horizontal,"缴费日期");
    model->setHeaderData(5,Qt::Horizontal,"是否缴费");
    ui->tableView->setModel(model);

    }
}

void Wuyejiaofeiguanli::on_comboBox_2_currentTextChanged(const QString &arg1)
{

    if(arg1=="所有业主")
        {
       ui->label_6->close();
       ui->lineEdit_3->close();

    }
    if(arg1=="个人")
        {
       ui->label_6->show();
       ui->lineEdit_3->show();

    }

}
