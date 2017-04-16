#include "dc_host.h"

dc_host::dc_host()
{
}

QDataStream & operator >> ( QDataStream &ds, dc_host &obj)
{
    return ds >> obj._ipAddress >> obj._port;
}

QDataStream & operator << ( QDataStream &ds, dc_host &obj)
{
    return ds << obj._ipAddress << obj._port;
}
