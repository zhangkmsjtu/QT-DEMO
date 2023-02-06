#ifndef TIMERUN_H
#define TIMERUN_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class timerun; }
QT_END_NAMESPACE

class timerun : public QWidget
{
    Q_OBJECT

public:
    timerun(QWidget *parent = nullptr);
    ~timerun();
    QTimer *timer1;


private:
    Ui::timerun *ui;
private slots:
    void daojishi();

};
#endif // TIMERUN_H
