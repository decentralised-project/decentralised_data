#include "decentralised_data.h"


decentralised_data::decentralised_data(QObject *parent, QString dataDirPath) : QObject(parent)
{
    _dataDirectory = dataDirPath;
    QDir dataDir(_dataDirectory);
    if(dataDir.exists(_dataDirectory))
        dataDir.mkpath(_dataDirectory);
}

QList<dc_host> decentralised_data::getHosts()
{
    QList<dc_host> hosts;
    QFile file(_dataDirectory + "hosts");
    if(file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_1);

        //in >> hosts;

        file.close();
    }
    return hosts;
}

