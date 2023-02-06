#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(ui->leusername->text()=="zkm" && ui->lepassword->text()=="12345"){
        qDebug()<<"登录成功";
        QMessageBox::information(this,"消息","登录成功");
        home.show();
        this->close();

    }else {
        qDebug()<<"用户名或密码错误";
        QMessageBox::information(this,"消息","用户名或密码错误");
}
}

