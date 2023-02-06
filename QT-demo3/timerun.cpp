#include "timerun.h"
#include "ui_timerun.h"

timerun::timerun(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::timerun)
{
    ui->setupUi(this);
}

timerun::~timerun()
{
    delete ui;
}

