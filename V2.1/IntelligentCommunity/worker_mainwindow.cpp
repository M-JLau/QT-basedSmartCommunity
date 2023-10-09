#include "worker_mainwindow.h"
#include "ui_worker_mainwindow.h"
#include "wuyeweixiuguanli.h"
#include "ui_wuyeweixiuguanli.h"
#include "wuyeqingxiaojia.h"
#include "ui_wuyeqingxiaojia.h"
#include "wuyeyueduchuqin.h"
#include "ui_wuyeyueduchuqin.h"
#include "wuyeshangxiabandengji.h"
#include "ui_wuyeshangxiabandengji.h"
#include "wuyecheweixinxiguanli.h"
#include "ui_wuyecheweixinxiguanli.h"
#include "wuyecheweichuzu.h"
#include "ui_wuyecheweichuzu.h"
#include "wuyejiaofeiguanli.h"
#include "ui_wuyejiaofeiguanli.h"
#include "wuyejiagewihu.h"
#include "ui_wuyejiagewihu.h"
#include "wuyexianxiashoufei.h"
#include "ui_wuyexianxiashoufei.h"
#include "shenpichaxun.h"
#include "ui_shenpichaxun.h"
#include "wuyezengjiaxinxi.h"
#include "ui_wuyezengjiaxinxi.h"
#include <QSqlDatabase>
#include <QSqlQuery>

extern int yonghuming;
extern int theme;

worker_MainWindow::worker_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::worker_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("物业管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));
    //this->setFixedSize(700,640); //固定主窗口

    if(theme == 1){
    this->setStyleSheet("#worker_MainWindow {border-image: url(:/2222.png);}#menubar{background-image: url(:/2222.png);}#menubar *{background-image: url(:/2222.png);}");}
    if(theme == 2){
    this->setStyleSheet("#worker_MainWindow {border-image: url(:/fen1.jpg);}#menubar{background-image: url(:/fen1bgm.jpg);}#menubar *{background-image: url(:/fen1.jpg);}");}
    if(theme == 3){
    this->setStyleSheet("#worker_MainWindow {border-image: url(:/fen2.jpg);}#menubar{background-image: url(:/fen2.jpg);}#menubar *{background-image: url(:/fen2.jpg);}");}
    if(theme == 4){
    this->setStyleSheet("#worker_MainWindow {border-image: url(:/lan1.jpg);}#menubar{background-image: url(:/lan1.jpg);}#menubar *{background-image: url(:/lan1.jpg);}");}
    if(theme == 5){
    this->setStyleSheet("#worker_MainWindow {border-image: url(:/lan2.jpg);}#menubar{background-image: url(:/lan2.jpg);}#menubar *{background-image: url(:/lan2.jpg);}");}

    wuyezengjiaxinxi *xi = new wuyezengjiaxinxi;
    setCentralWidget(xi);
    QString qwer = tr("select * from usrlist where id=%1").arg(yonghuming);
    QSqlQuery query;
    query.exec(qwer);
    query.next();
    QString usrname = query.value(5).toString().trimmed();
    QLabel *normal=new QLabel(tr("欢迎您物业工作人员：%1").arg(usrname),this);
    ui->statusbar->addWidget(normal);//显示正常信息
    QLabel *permanent=new QLabel(this);
    permanent->setText(tr("<a href=\"https://github.com/yang1584375824/IntelligentCommunity\">点此访问我们的官网 </a>"));
    permanent->setOpenExternalLinks(true);//设置可以打开网站链接
    ui->statusbar->addPermanentWidget(permanent);//显示永久信息
    ui->statusbar->setSizeGripEnabled(false);//去掉状态栏右下角的三角
    ui->statusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));



}

worker_MainWindow::~worker_MainWindow()
{
    delete ui;
}

void worker_MainWindow::on_action_triggered()//人事管理
{

//    Wuyerenyuanguanli *wuyerenyuanguan = new Wuyerenyuanguanli;
//    this->setCentralWidget(wuyerenyuanguan);
    wuyezengjiaxinxi *xi = new wuyezengjiaxinxi;
    setCentralWidget(xi);

}

void worker_MainWindow::on_actionrenshi_triggered()//请销假
{
    Wuyeqingxiaojia *jia = new Wuyeqingxiaojia;
    setCentralWidget(jia);
}

void worker_MainWindow::on_action_2_triggered()//维修管理
{
    Wuyeweixiuguanli *wuyeweixiuguanli = new Wuyeweixiuguanli;
    setCentralWidget(wuyeweixiuguanli);
}

void worker_MainWindow::on_action_3_triggered()//月度出勤
{
    Wuyeyueduchuqin *qin = new Wuyeyueduchuqin;
    setCentralWidget(qin);
}

void worker_MainWindow::on_action_4_triggered()//上下班登记
{
    Wuyeshangxiabandengji *ji = new Wuyeshangxiabandengji;
    setCentralWidget(ji);
}

void worker_MainWindow::on_action_5_triggered()//车位信息管理
{
    Wuyecheweixinxiguanli *li = new Wuyecheweixinxiguanli;
    setCentralWidget(li);
}

void worker_MainWindow::on_action_6_triggered()//车位出租
{
    Wuyecheweichuzu *zu = new Wuyecheweichuzu;
    setCentralWidget(zu);

}

void worker_MainWindow::on_action_7_triggered()//缴费信息查询
{
    Wuyejiaofeiguanli *li = new Wuyejiaofeiguanli;
    setCentralWidget(li);
}

void worker_MainWindow::on_action_8_triggered()//缴费维护
{
    Wuyejiagewihu *hu = new Wuyejiagewihu;
    setCentralWidget(hu);
}

void worker_MainWindow::on_action_9_triggered()//线下收费
{
    wuyexianxiashoufei *fei = new wuyexianxiashoufei;
    setCentralWidget(fei);
}

void worker_MainWindow::on_action_10_triggered()//审批查询
{
    shenpichaxun *xun = new shenpichaxun;
    setCentralWidget(xun);
}
