#include "payload.h"

PayLoad::PayLoad(QStringList list, QObject *parent) : QObject(parent) {
    if(list.size() >= 4) {
        if(list.at(1) != NULL)
            this->host = list.at(1);

        if(list.at(2) != NULL)
            this->port = list.at(2).toInt();

        if(list.at(3) != NULL)
            this->threads = list.at(3).toInt();

        if(list.at(4) != NULL)
            this->cycles = list.at(4).toInt();
    }

    this->request = "GET /ads-teenused/rest/findAddressSuggest.json?query=test HTTP/1.1\r\nHost: " +
            this->host + "\r\nConnection: keep-alive\r\n\r\n";
}

bool PayLoad::verify() {
    return this->host != NULL && this->threads != NULL && this->cycles != NULL;
}

int PayLoad::getThreads() {
    return this->threads;
}

int PayLoad::getCycles() {
    return this->cycles;
}

QString PayLoad::getHost() {
    return this->host;
}

int PayLoad::getPort() {
    return this->port;
}

QString PayLoad::getRequest() {
    return this->request;
}

