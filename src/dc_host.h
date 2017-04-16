#ifndef DC_HOST_H
#define DC_HOST_H

#include <QObject>
#include <QDataStream>
#include <QMetaProperty>

class dc_host
{
public:
    dc_host();

    QString ipAddress() const { return _ipAddress; }
    void setIpAddress(const QString &ip) { _ipAddress = ip; }

    int port() const { return _port; }
    void setPort(int p) { _port = p; }

    friend QDataStream & operator << ( QDataStream &ds, dc_host &obj );
    friend QDataStream & operator >> ( QDataStream &ds, dc_host &obj );
private:
    QString _ipAddress;
    int _port;
};

#endif // DC_HOST_H
