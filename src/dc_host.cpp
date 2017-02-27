#include "dc_host.h"

dc_host::dc_host(QObject *parent, QString ip, int port) : QObject(parent)
{
    _ipAddress = ip;
    _port = port;
}

QString dc_host::ipAddress() const
{
    return _ipAddress;
}

void dc_host::setIpAddress(const QString &ip)
{
    _ipAddress = ip;
}

int dc_host::port() const
{
    return _port;
}

void dc_host::setPort(int p)
{
    _port = p;
}

QDataStream &operator<<(QDataStream &out, const dc_host &host)
{
    out << host.ipAddress() << host.port();
    return out;
}

QDataStream &operator>>(QDataStream &in, dc_host &host)
{
    QString ip;
    int port;
    in >> ip >> port;
    host = dc_host(0, ip, port);
    return in;
}
