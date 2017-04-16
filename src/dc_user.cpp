#include "dc_user.h"

dc_user::dc_user()
{
    _keyPair = NULL;
    _userName = QString::null;
}

dc_user::dc_user(EC_KEY* keyPair, QString userName)
{
    _keyPair = keyPair;
    _userName = userName;
}

void dc_user::save(QString dataDir)
{

}

QDataStream & operator >> ( QDataStream &ds, dc_user &obj)
{
    return ds >> obj._userName;
}

QDataStream & operator << ( QDataStream &ds, dc_user &obj)
{
    return ds << obj._userName;
}
