#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    Server(int port);
    void incomingConnection(qintptr socketDescriptor);
    QTcpSocket* getsock();
private:
    QTcpSocket *socket;
private slots:
    void receiveMessage();
public: signals:
    void givemsg(QString,int);

};

#endif // SERVER_H
