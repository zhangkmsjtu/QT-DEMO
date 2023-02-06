#ifndef TIMERUN_H
#define TIMERUN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class timerun; }
QT_END_NAMESPACE

class timerun : public QWidget
{
    Q_OBJECT

public:
    timerun(QWidget *parent = nullptr);
    ~timerun();

private:
    Ui::timerun *ui;
};
#endif // TIMERUN_H
