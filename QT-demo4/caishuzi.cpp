#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "caishuzi.h"
#include "ui_caishuzi.h"

caishuzi::caishuzi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::caishuzi)
{
    ui->setupUi(this);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(myfunc1()));
    timer1->start(1000);
    int a=qrand();
    r=a%100+1;
}

caishuzi::~caishuzi()
{
    delete ui;
}

void caishuzi::myfunc1()
{
//    qDebug()<<"time";
    QString curtime= QTime::currentTime().toString("hh:mm:ss.zzz");
    ui->label->setText("当前时间: "+curtime);
}


void caishuzi::on_pushButton_clicked()
{
    if(ui->lineEdit->text().toInt()>r){
    QMessageBox::about(this,"消息","猜大了.");
    }else if(ui->lineEdit->text().toInt()<r){
        QMessageBox::about(this,"消息","猜小了.");
    }else{
        QMessageBox::about(this,"恭喜.","猜对了.");

    }

}
