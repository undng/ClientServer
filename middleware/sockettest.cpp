#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("bogotobogo.com", 80);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // send
        socket->write("hello server");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }
}
