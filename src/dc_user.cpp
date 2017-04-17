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

bool dc_user::save(QString dataDir, QString pw)
{
    QDir usersDir(dataDir + "users");
    if(!usersDir.exists())
        usersDir.mkdir(dataDir + "users");

    QString filename = _userName.replace(" ", "-");
    QFile userFile(dataDir + "users/" + filename + ".usr");
    if(userFile.exists())
        return false;

    BIO* memBioKeyPair = BIO_new(BIO_s_mem());
    if(memBioKeyPair == NULL)
        return false;

    EC_GROUP *group = EC_GROUP_new_by_curve_name(NID_secp256k1);
    if(group == NULL)
        return false;

    int iRet = PEM_write_bio_ECPKParameters(memBioKeyPair, group);
    if (!iRet)
        return false;

    iRet = PEM_write_bio_ECPrivateKey(memBioKeyPair, _keyPair, NULL, NULL, 0, NULL, NULL);
    if (!iRet)
        return false;

    iRet = PEM_write_bio_EC_PUBKEY(memBioKeyPair, _keyPair);
    if (!iRet)
        return false;

    char* pchPriKey = NULL;
    pchPriKey = new char[4096];
    iRet = BIO_read(memBioKeyPair, pchPriKey, 4096);
    if(!iRet)
        return false;

    if(userFile.open(QIODevice::WriteOnly)) {

        userFile.write(pchPriKey);

        userFile.close();
    }

    BIO_free_all(memBioKeyPair);
    EC_GROUP_free(group);

    return true;
}

