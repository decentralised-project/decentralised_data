#ifndef DC_HOST_H
#define DC_HOST_H

#include <QObject>
#include <QDataStream>

class dc_host : public QObject
{
    Q_OBJECT
public:
    explicit dc_host(QObject *parent = 0, QString ip = "", int port = 0);

    QString ipAddress() const;
    void setIpAddress(const QString &ip);

    int port() const;
    void setPort(int p);

private:
    QString _ipAddress;
    int _port;
};
QDataStream &operator<<(QDataStream &out, const dc_host &host);
QDataStream &operator>>(QDataStream &in, dc_host &host);

#endif // DC_HOST_H
