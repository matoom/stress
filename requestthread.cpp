#include "requestthread.h"

RequestThread::RequestThread(int id, PayLoad *payLoad, QObject *parent) : QRunnable(), QObject(parent) {
    this->payLoad = payLoad;

    this->id = id;

    client = new Client();

    connect(this, SIGNAL(initRequest(QString, int)), client, SLOT(connectToHost(QString, int)));
    connect(this, SIGNAL(write(QByteArray)), client, SLOT(writeData(QByteArray)));
}

void RequestThread::run() {
    emit initRequest(payLoad->getHost(), payLoad->getPort());

    for(int i = 0; i < payLoad->getCycles(); i++) {
        emit write(payLoad->getRequest().toUtf8());
    }
}
