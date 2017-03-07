#ifndef DECENTRALISED_DATA_H
#define DECENTRALISED_DATA_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDir>
#include <QDataStream>
#include "dc_host.h"
#include "dc_data_error.h"

class decentralised_data: public QObject
{
    Q_OBJECT
    public:
        explicit decentralised_data(QObject *parent, QString &dataDirPath);

        void initialize();
        QList<dc_host> getHosts();

    signals:
        void dataError(data_error error);

    private:
        QString _dataDirectory;
};

#endif // DECENTRALISED_DATA_H
