#include "admin_mainwindow.h"
#include "ui_admin_mainwindow.h"
#include "guanliyuanrenshiguanli.h"
#include "ui_guanliyuanrenshiguanli.h"
#include "guanliyuanyueduchuqin.h"
#include "ui_guanliyuanyueduchuqin.h"
#include "guanliyuanqingjiashenpi.h"
#include "ui_guanliyuanqingjiashenpi.h"
#include "guanliyuanchushihua.h"
#include "ui_guanliyuanchushihua.h"
#include "canshushezhi.h"
#include "ui_canshushezhi.h"
#include "guanliyuanrenshichaxun.h"
#include "ui_guanliyuanrenshichaxun.h"
#include "guanliyuantheme.h"
#include "ui_guanliyuantheme.h"
#include <QSqlDatabase>
#include <QSqlQuery>

extern int yonghuming;
extern int theme;

admin_MainWindow::admin_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));
    //this->setFixedSize(800,640); //固定主窗口

    if(theme == 1){
    this->setStyleSheet("#admin_MainWindow {border-image: url(:/2222.png);}#menubar{background-image: url(:/2222.png);}#menubar *{background-image: url(:/2222.png);}");}
    if(theme == 2){
    this->setStyleSheet("#admin_MainWindow {border-image: url(:/fen1.jpg);}#menubar{background-image: url(:/fen1bgm.jpg);}#menubar *{background-image: url(:/fen1.jpg);}");}
    if(theme == 3){
    this->setStyleSheet("#admin_MainWindow {border-image: url(:/fen2.jpg);}#menubar{background-image: url(:/fen2.jpg);}#menubar *{background-image: url(:/fen2.jpg);}");}
    if(theme == 4){
    this->setStyleSheet("#admin_MainWindow {border-image: url(:/lan1.jpg);}#menubar{background-image: url(:/lan1.jpg);}#menubar *{background-image: url(:/lan1.jpg);}");}
    if(theme == 5){
    this->setStyleSheet("#admin_MainWindow {border-image: url(:/lan2.jpg);}#menubar{background-image: url(:/lan2.jpg);}#menubar *{background-image: url(:/lan2.jpg);}");}

    Guanliyuanrenshiguanli *guanliyuanrenshiguanli = new Guanliyuanrenshiguanli;
    this->setCentralWidget(guanliyuanrenshiguanli);
    QString qwer = tr("select * from usrlist where id=%1").arg(yonghuming);
    QSqlQuery query;
    query.exec(qwer);
    query.next();
    QString usrname = query.value(5).toString().trimmed();
    QLabel *normal=new QLabel(tr("欢迎您管理员：%1").arg(usrname),this);
    ui->statusbar->addWidget(normal);//显示正常信息
    QLabel *permanent=new QLabel(this);
    permanent->setText(tr("<a href=\"https://github.com/yang1584375824/IntelligentCommunity\">点此访问我们的官网 </a>"));
    permanent->setOpenExternalLinks(true);//设置可以打开网站链接
    ui->statusbar->addPermanentWidget(permanent);//显示永久信息
    ui->statusbar->setSizeGripEnabled(false);//去掉状态栏右下角的三角
    ui->statusbar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

}

admin_MainWindow::~admin_MainWindow()
{
    delete ui;
}

void admin_MainWindow::on_action_triggered()//人事管理
{
    Guanliyuanrenshiguanli *guanliyuanrenshiguanli = new Guanliyuanrenshiguanli;
    this->setCentralWidget(guanliyuanrenshiguanli);
}

void admin_MainWindow::on_action_2_triggered()//月度出勤
{
    Guanliyuanyueduchuqin *chuqin =new Guanliyuanyueduchuqin;
    setCentralWidget(chuqin);
}

void admin_MainWindow::on_action_3_triggered()//请假审批
{
    Guanliyuanqingjiashenpi *pi = new Guanliyuanqingjiashenpi;
    setCentralWidget(pi);
}

void admin_MainWindow::on_action_4_triggered()//系统初始化
{
    guanliyuanchushihua *hua = new guanliyuanchushihua;
    setCentralWidget(hua);
}

void admin_MainWindow::on_actionAbout_us_triggered()// about us
{
    canshushezhi *zhi = new canshushezhi;
    setCentralWidget(zhi);
}

void admin_MainWindow::on_action_5_triggered()//人事查询
{
    Guanliyuanrenshichaxun *xun = new Guanliyuanrenshichaxun;
    setCentralWidget(xun);
}

void admin_MainWindow::on_action_6_triggered()//主题切换
{
    Guanliyuantheme *theme = new Guanliyuantheme;
    setCentralWidget(theme);
}
