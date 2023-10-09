#include "guanliyuantheme.h"
#include "ui_guanliyuantheme.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

extern int theme;

Guanliyuantheme::Guanliyuantheme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guanliyuantheme)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(theme-1);
    ui->pushButton->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->pushButton->setShortcut(Qt::Key_Enter);
    ui->pushButton->setShortcut(Qt::Key_Return);
}

Guanliyuantheme::~Guanliyuantheme()
{
    delete ui;
}

void Guanliyuantheme::on_pushButton_clicked()
{
    int mark = ui->comboBox->currentIndex();
    int updatemark;
    if(mark == 0){
        updatemark = 1;
    }
    if(mark == 1){
        updatemark = 2;
    }
    if(mark == 2){
        updatemark = 3;
    }
    if(mark == 3){
        updatemark = 4;
    }
    if(mark == 4){
        updatemark = 5;
    }
    QString temp = QString("update theme set mark = '%1'").arg(updatemark);
    QSqlQuery query;
    query.exec(temp);
    QMessageBox::information(this,tr("提示"),tr("主题修改成功，重启后生效！"),QMessageBox::Ok);
}
