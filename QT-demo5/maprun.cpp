#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


#include "maprun.h"

maprun::maprun(QWidget *parent)
    : QWidget(parent)
{

    num = 1;
    pm->load(":/zkm/C:/Users/12318/Pictures/zkm"+QString::number(num)+".png");
    labmap.setPixmap(QPixmap(*pm));
    labmap.setParent(this);
    labmap.setScaledContents(true);
//    labmap.setStyleSheet("border:lpx solid red;");
    labmap.setGeometry(30,30,400,400);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(myfunc1()));
    timer1->start(1000);


//    文字链接
    labscp=new QLabel(this);
    labscp->setText("<a href='http://zhangkmsjtu.github.io'>更多内容</a>");
    labscp->setOpenExternalLinks(true);
}

maprun::~maprun()
{
}

void maprun::myfunc1()
{
    num++;
    if(num>2) num=1;
    pm->load(":/zkm/C:/Users/12318/Pictures/zkm"+QString::number(num)+".png");
    labmap.setPixmap(QPixmap(*pm));

}

