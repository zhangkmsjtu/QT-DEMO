#include "server.h"

server::server(QObject *parent) : QTcpServer(parent)
{
    listen(QHostAddress::Any,8888);

}

void server::incomingConnection(qintptr handle)
{
//    qDebug()<<"toto";
    sock=new QTcpSocket(this);
    sock->setSocketDescriptor(handle);
    connect(sock,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

}

void server::receiveMessage()
{
    if(sock->bytesAvailable()>0){
        char buffer[1024];
        sock->read(buffer,sock->bytesAvailable());
        qDebug()<<buffer;

    }
}
