#include "server.h"

Server::Server()
{

}

Server::Server(int port)
{
    listen(QHostAddress::Any,port);

}
