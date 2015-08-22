#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <QObject>
#include <QStringList>

class PayLoad : public QObject {
    Q_OBJECT

public:
    explicit PayLoad(QStringList list, QObject *parent = 0);
    
    bool verify();

    int getThreads();
    int getCycles();
    QString getHost();
    QString getRequest();

private:
    int threads;
    int cycles;
    QString host;
    QString request;

signals:
    int connect();

public slots:
    
};

#endif // PAYLOAD_H
