#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

    QByteArray readData();

private:
    QTcpSocket *socket;

signals:
    
public slots:
    bool connectToHost(QString host);
    bool writeData(QByteArray data);
    
};

#endif // CLIENT_H
