#include <QCoreApplication>
#include <QThreadPool>

#include <iostream>
#include "requestthread.h"
#include "payload.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    PayLoad *payLoad = new PayLoad(QCoreApplication::arguments());

    QThreadPool *qThreadPool = QThreadPool::globalInstance();
    qThreadPool->setMaxThreadCount(payLoad->getThreads());

    if(payLoad->verify()) {
        for(int i = 0; i < payLoad->getThreads(); i++){
            qThreadPool->start(new RequestThread(i, payLoad));
        }
        qDebug() << "All threads started ..";
    } else {
        qDebug() <<"Parameters missing";
    }

    qThreadPool->waitForDone();

    qDebug() << "Done";

    return a.exec();
}
