#include "canshushezhi.h"
#include "ui_canshushezhi.h"

extern int yonghuming;

canshushezhi::canshushezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canshushezhi)
{
    ui->setupUi(this);
}

canshushezhi::~canshushezhi()
{
    delete ui;
}
