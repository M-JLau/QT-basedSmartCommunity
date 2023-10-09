#include "quanju.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminlogin.h"
#include "worker_mainwindow.h"
#include "owner_mainwindow.h"
#include "admin_mainwindow.h"
#include "ui_admin_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLineEdit>

extern int yonghuming;
extern int theme;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFont(QFont("黑体",10));
    ui->lineEdit_2->setFont(QFont("黑体",10));
    this->setWindowTitle("山云涧社区管理系统");
    this->setWindowIcon(QIcon(":/logo.png"));
    QString qwer = tr("select * from theme");
    QSqlQuery query;
    query.exec(qwer);
    query.next();
    theme = query.value(0).toInt();
    if(theme == 1){
    this->setStyleSheet("#centralWidget{border-image: url(:/beijing1.jpg);}");}
    if(theme == 2){
    this->setStyleSheet("#centralWidget{border-image: url(:/fen1bg.jpg);}");}
    if(theme == 3){
    this->setStyleSheet("#centralWidget{border-image: url(:/fen2bg.jpg);}");}
    if(theme == 4){
    this->setStyleSheet("#centralWidget{border-image: url(:/lan1bg.jpg);}");}
    if(theme == 5){
    this->setStyleSheet("#centralWidget{border-image: url(:/lan2bg.jpg);}");}

    //this->setFixedSize(1032,359); //固定主窗口
    ui->lineEdit->setFocus();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("账号/手机号/身份证号码等");
    ui->lineEdit_2->setPlaceholderText("密码");
    ui->pushButton->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->pushButton->setShortcut(Qt::Key_Enter);
    ui->pushButton->setShortcut(Qt::Key_Return);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)//登录
{
        QSqlQuery query;
        if(query.exec("select * from usrlist"))
               {

                   while(query.next())//遍历数据表格

                   {

                        QString id= query.value(0).toString().trimmed();//trimmed函数表示去除QString两边的空格
                        QString tel= query.value(1).toString().trimmed();
                        QString IDcard =query.value(2).toString().trimmed();
                        QString password=query.value(3).toString().trimmed();
                        QString name=query.value(5).toString().trimmed();
                        int mark = query.value(4).toInt();

                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 1)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 1)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 1)){


                            QMessageBox::information(this,tr("提示"),tr("尊贵的业主:%1  欢迎您！").arg(name),QMessageBox::Ok);
                            yonghuming = id.toInt();
                            Owner_MainWindow *owner = new Owner_MainWindow;
                            owner->show();
                            this->close();
                            return;

                   }
                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 2)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 2)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 2)){

                            QMessageBox::information(this,tr("提示"),tr("物业工作人员:%1  欢迎您！").arg(name),QMessageBox::Ok);
                            yonghuming = id.toInt();
                            worker_MainWindow *worker = new worker_MainWindow;
                            worker->show();
                            this->close();
                            return;

                   }
                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 0)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 0)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 0)){

                            QMessageBox::information(this,tr("提示"),tr("管理员:%1  欢迎您！").arg(name),QMessageBox::Ok);
                            yonghuming = id.toInt();
                            admin_MainWindow *admin = new admin_MainWindow;
                            admin->show();
                            this->close();
                            return;

                   }

               }
                       QMessageBox::warning(this, tr("登录失败"),
                                            tr("请输入正确的账号或密码！"), QMessageBox::Ok);
                       ui->lineEdit->clear();
                       ui->lineEdit_2->clear();
                       ui->lineEdit->setFocus();
}


}
void MainWindow::on_commandLinkButton_clicked(bool checked)//管理员登录
{
    adminlogin *admin = new adminlogin;
    admin->setWindowTitle("欢迎您！管理员");
    admin->setWindowIcon(QIcon(":/logo.png"));
    admin->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked(bool checked)//关闭窗口
{
    ui->setupUi(this);
    this->close();
}


