﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>
#include <QModelIndex>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QSqlQuery *query;
    QSqlDatabase db;
    QSqlQueryModel *qmodel;
    QModelIndex currentindex;


};
#endif // WIDGET_H
