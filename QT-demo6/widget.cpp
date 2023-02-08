#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("zkm0208.db");
    db.open();
    dbsqu=new QSqlQuery();
    dbsqu->exec("create table user1(usr,pas)");
    dbsqu->exec("insert into user1(usr,pas) values('zkm1',43435)");


}

Widget::~Widget()
{
    delete ui;
}

