#include "server.h"

Server::Server()
{

}

Server::Server(int port)
{
    listen(QHostAddress::Any,port);

}

void Server::incomingConnection(qintptr socketDescriptor)
{
//    qDebug()<<"AAA";
    socket=new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

//    socket->peerAddress().toString();
    emit givemsg(socket->peerAddress().toString()+" 上线了。",1);

}

QTcpSocket *Server::getsock()
{
    return  this->socket;

}

void Server::receiveMessage()
{
    QByteArray arr= socket->readAll();
    QString str= arr.data();

    emit givemsg(str,1);

}
