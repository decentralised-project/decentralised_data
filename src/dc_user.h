#ifndef DC_USER_H
#define DC_USER_H

#include <QObject>
#include <openssl/ec.h>

class dc_user
{
public:
    dc_user();
    dc_user(EC_KEY* keyPair, QString userName);

    void save(QString dataDir);

    friend QDataStream & operator << ( QDataStream &ds, dc_user &obj );
    friend QDataStream & operator >> ( QDataStream &ds, dc_user &obj );

private:
    EC_KEY *_keyPair;
    QString _userName;
};

#endif // DC_USER_H
