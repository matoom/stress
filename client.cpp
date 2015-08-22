#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);

    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
}

void Client::connectToHost(QString host, int port) {
    socket->connectToHost(host, port);
    socket->waitForConnected();
}

bool Client::writeData(QByteArray data) {
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(data);
        socket->flush();
        return true;
    } else {
        qDebug() << "Unable to write to socket in" << socket->state() << "state";
        return false;
    }
}

QByteArray Client::readData() {
    socket->waitForReadyRead(3000);
    socket->bytesAvailable();
    return socket->readAll();
}
