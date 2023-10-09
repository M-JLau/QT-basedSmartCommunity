#include "owner_mainwindow.h"
#include "ui_owner_mainwindow.h"
#include "yezhuguzhuangbaoxiu.h"
#include "ui_yezhuguzhuangbaoxiu.h"
#include "yezhuguzhangchaxunpingjia.h"
#include "ui_yezhuguzhangchaxunpingjia.h"
#include "yezhucheweiguanli.h"
#include "ui_yezhucheweiguanli.h"
#include "yezhujiaofeichaxun.h"
#include "ui_yezhujiaofeichaxun.h"
#include "yezhuzizhujiaofei.h"
#include "ui_yezhuzizhujiaofei.h"
#include <QSqlDatabase>
#include <QSqlQuery>

extern int yonghuming;
extern int theme;

Owner_MainWindow::Owner_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Owner_MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(700,640); //固定主窗口

    if(theme == 1){
    this->setStyleSheet("#Owner_MainWindow {border-image: url(:/2222.png);}#menubar{background-image: url(:/2222.png);}#menubar *{background-image: url(:/2222.png);}");}
    if(theme == 2){
    this->setStyleSheet("#Owner_MainWindow {border-image: url(:/fen1.jpg);}#menubar{background-image: url(:/fen1bgm.jpg);}#menubar *{background-image: url(:/fen1.jpg);}");}
    if(theme == 3){
    this->setStyleSheet("#Owner_MainWindow {border-image: url(:/fen2.jpg);}#menubar{background-image: url(:/fen2.jpg);}#menubar *{background-image: url(:/fen2.jpg);}");}
    if(theme == 4){
    this->setStyleSheet("#Owner_MainWindow {border-image: url(:/lan1.jpg);}#menubar{background-image: url(:/lan1.jpg);}#menubar *{background-image: url(:/lan1.jpg);}");}
    if(theme == 5){
    this->setStyleSheet("#Owner_MainWindow {border-image: url(:/lan2.jpg);}#menubar{background-image: url(:/lan2.jpg);}#menubar *{background-image: url(:/lan2.jpg);}");}

    QString qwer = tr("select * from usrlist where id=%1").arg(yonghuming);
    QSqlQuery query;
    query.exec(qwer);
    query.next();
    QString usrname = query.value(5).toString().trimmed();
    QLabel *normal=new QLabel(tr("欢迎您业主：%1").arg(usrname),this);
    ui->statusbar->addWidget(normal);//显示正常信息
    QLabel *permanent=new QLabel(this);
    permanent->setText(tr("<a href=\"https://github.com/yang1584375824/IntelligentCommunity\">点此访问我们的官网 </a>"));
    permanent->setOpenExternalLinks(true);//设置可以打开网站链接
    ui->statusbar->addPermanentWidget(permanent);//显示永久信息
    ui->statusbar->setSizeGripEnabled(false);//去掉状态栏右下角的三角
    ui->statusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

    this->setWindowTitle("业主管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));
    Yezhucheweiguanli *li = new Yezhucheweiguanli;
    setCentralWidget(li);

}

Owner_MainWindow::~Owner_MainWindow()
{
    delete ui;
}

void Owner_MainWindow::on_action_3_triggered()//故障报修
{
    Yezhuguzhuangbaoxiu *yezhuguzhangbaoxiu = new Yezhuguzhuangbaoxiu;
    setCentralWidget(yezhuguzhangbaoxiu);
}

void Owner_MainWindow::on_action_2_triggered()//故障查询和评价界面
{
    Yezhuguzhangchaxunpingjia *chaxunpingjia = new Yezhuguzhangchaxunpingjia;
    setCentralWidget(chaxunpingjia);
}

void Owner_MainWindow::on_action_4_triggered()//车位信息
{
    Yezhucheweiguanli *li = new Yezhucheweiguanli;
    setCentralWidget(li);
}

void Owner_MainWindow::on_action_triggered()//缴费查询
{
    Yezhujiaofeichaxun *xun = new Yezhujiaofeichaxun;
    setCentralWidget(xun);
}

void Owner_MainWindow::on_action_5_triggered()//业主自主缴费
{
    yezhuzizhujiaofei *fei = new yezhuzizhujiaofei;
    setCentralWidget(fei);
}
