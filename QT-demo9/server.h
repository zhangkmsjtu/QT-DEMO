#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>

class server : public QTcpServer
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
private:
    QTcpSocket *sock;

private slots:
    void incomingConnection(qintptr handle);
    void receiveMessage();
};

#endif // SERVER_H
