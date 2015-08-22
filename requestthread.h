#ifndef REQUESTTHREAD_H
#define REQUESTTHREAD_H

#include <QObject>
#include <QRunnable>

#include <client.h>
#include "payload.h"

class RequestThread : public QObject, public QRunnable {
    Q_OBJECT

public:
    explicit RequestThread(int id, PayLoad *payLoad, QObject *parent = 0);
    
    void run();

private:
    PayLoad *payLoad;
    Client *client;
    int id;

signals:
    void initRequest(QString host, int);
    bool write(QByteArray data);
    
public slots:
    
};

#endif // REQUESTTHREAD_H
