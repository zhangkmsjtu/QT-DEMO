#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


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

void Widget::paintEvent(QPaintEvent *event)
{
    //相当于QPainter *painter=new QPainter(this);
    QPainter painter(this);
    painter.drawLine(0,200,400,200);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawArc(30,30,100,100,30*16,140*16);
    painter.drawPie(50,50,100,100,0,90*16);
    painter.drawRect(200,100,150,100);
    painter.fillRect(100,350,200,300,QBrush(QColor(255,0,0)));

    painter.drawLine(10,500,500,500);
    for(int i=1;i<10;i++){
        painter.drawLine(50*i,480,50*i,500);
        painter.drawText(50*i-5,520,QString::number(50*i));

    }
    painter.drawText(490,520,"水平轴");

    painter.drawLine(10,500,10,50);
    for(int i=1;i<9;i++){
        painter.drawLine(10,500-50*i,30,500-50*i);
        painter.drawText(22,500-50*i,QString::number(50*i));

    }
    painter.drawText(10,30,"竖直轴/步数");

//    painter.drawText(45,45,"每天步数");
    painter.drawText(12,520,"0");
//    生成随机数
    int x1, y1, x2, y2;
    x1=10;
    y1=qrand()%400;
    for(int i=0;i<80;i++){
        x2=10+5*i;
        y2=500-qrand()%400;

        painter.drawLine(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
        painter.setPen(QPen(Qt::red,5));
        painter.drawPoint(x1,y1);

    }



}

