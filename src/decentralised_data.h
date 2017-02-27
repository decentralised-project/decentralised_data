#ifndef DECENTRALISED_DATA_H
#define DECENTRALISED_DATA_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDir>
#include <QDataStream>
#include "dc_host.h"

class decentralised_data: public QObject
{
    Q_OBJECT
    public:
        explicit decentralised_data(QObject *parent = 0, QString dataDirPath = "");

        QList<dc_host> getHosts();

    private:
        QString _dataDirectory;
};

#endif // DECENTRALISED_DATA_H
