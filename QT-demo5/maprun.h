#ifndef MAPRUN_H
#define MAPRUN_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QString>

class maprun : public QWidget
{
    Q_OBJECT

public:
    maprun(QWidget *parent = nullptr);
    ~maprun();
    int num;
    QPixmap *pm=new QPixmap();

private:
    QLabel labmap;
    QLabel *labscp;
    QTimer *timer1;
private slots:
    void myfunc1();
};
#endif // MAPRUN_H
