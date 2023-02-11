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
    int port=ui->lineEditPORT->text().toInt();
    server=new Server(port);
    connect(server,SIGNAL(givemsg(QString,int)),this,SLOT(mygivemsg(QString,int)));
}

void Widget::mygivemsg(QString str,int type)
{
   if(type==1)
       ui->textEditRECEIVE->setText(str);
   else if(type==2){
       ui->listWidgetLOG->addItem(str);
   }

}

void Widget::on_pushButton_2_clicked()
{
    QByteArray arr=ui->textEdit_2SEND->toPlainText().toUtf8();
    sock=server->getsock();
    sock->write(arr);
}
