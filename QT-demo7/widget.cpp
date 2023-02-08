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
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("zkm-demo7.db");
    db.open();
    query=new QSqlQuery();
    query->exec("create table userinfo(username,password)");
    qmodel=new QSqlQueryModel();
    qmodel->setQuery("select * from userinfo");
    ui->tableView->setModel(qmodel);
    qmodel->setHeaderData(0,Qt::Horizontal,"用户名");
    qmodel->setHeaderData(1,Qt::Horizontal,"密码");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString username=ui->lineEdit_usr->text();
    QString password=ui->lineEdit_pw->text();
    QString sql="insert into userinfo(username,password) values('"+username+"','"+password+"')";
    query->exec(sql);
    QMessageBox::about(this,"消息","注册成功！");
    qmodel->setQuery("select * from userinfo");
}

void Widget::on_tableView_clicked(const QModelIndex &index)
{
    QString username=index.siblingAtColumn(0).data().toString();
    ui->lineEdit_usr->setText(username);
    QString password=index.siblingAtColumn(1).data().toString();
    ui->lineEdit_pw->setText(password);
//    qDebug()<<username;
    currentindex=index;
}

void Widget::on_pushButton_2_clicked()
{
    QString username=ui->lineEdit_usr->text();
    QString password=ui->lineEdit_pw->text();
    QString sql="update userinfo set password='"+password+"' where username='"+username+"'";
    query->exec(sql);
    qmodel->setQuery("select * from userinfo");


}

void Widget::on_pushButton_3_clicked()
{
//    QString username=ui->lineEdit_usr->text();
    QString username=currentindex.siblingAtColumn(0).data().toString();
    QString sql="delete from userinfo where username='"+username+"'";
    query->exec(sql);
    qmodel->setQuery("select * from userinfo");

}
