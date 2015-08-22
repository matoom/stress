#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);

    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
}

bool Client::connectToHost(QString host) {
    socket->connectToHost(host, 80);
    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data) {
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(data);
        socket->flush();
        return true;
    } else {
        return false;
    }
}

QByteArray Client::readData() {
    socket->waitForReadyRead(3000);
    socket->bytesAvailable();
    return socket->readAll();
}
