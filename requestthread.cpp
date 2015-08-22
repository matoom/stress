#include "requestthread.h"

RequestThread::RequestThread(PayLoad *payLoad, QObject *parent) : QRunnable(), QObject(parent) {
    this->payLoad = payLoad;

    client = new Client();

    connect(this, SIGNAL(initRequest(QString)), client, SLOT(connectToHost(QString)));
    connect(this, SIGNAL(write(QByteArray)), client, SLOT(writeData(QByteArray)));
}

void RequestThread::run() {
    emit initRequest(payLoad->getHost());

    for(int i = 0; i < payLoad->getCycles(); i++) {
        emit write(payLoad->getRequest().toUtf8());
    }
}
