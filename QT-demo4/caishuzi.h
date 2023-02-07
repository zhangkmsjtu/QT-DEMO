#ifndef CAISHUZI_H
#define CAISHUZI_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QString>
#include <QChar>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class caishuzi; }
QT_END_NAMESPACE

class caishuzi : public QWidget
{
    Q_OBJECT

public:
    caishuzi(QWidget *parent = nullptr);
    ~caishuzi();

private:
    Ui::caishuzi *ui;
    QTimer *timer1;
    int r;

private slots:
    void myfunc1();
    void on_pushButton_clicked();
};
#endif // CAISHUZI_H
