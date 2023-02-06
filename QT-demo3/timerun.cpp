#include "timerun.h"
#include "ui_timerun.h"


timerun::timerun(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::timerun)
{
    ui->setupUi(this);
    timer1 = new QTimer(this);
//    connect(timer1,SIGNAL(timeout()),this,SLOT(daojishi()));
    connect(timer1,&QTimer::timeout,this,&timerun::daojishi);
    timer1->start(1000);
}

timerun::~timerun()
{
    delete ui;
}

void timerun::daojishi()
{
//    qDebug()<<"shuchu";
    int curval = ui->label->text().toInt();
    curval--;
    ui->label->setText(QString::number(curval));
}

