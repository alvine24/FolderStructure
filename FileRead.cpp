#include "FileRead.h"
#include <QDebug>

FileRead::FileRead()
{
}

QHash<QString, QString> FileRead::listFiles(QString mDir){
    QDir dir(mDir);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QFileInfo finfo, list) {
        //qDebug() << finfo.absoluteDir().dirName()+"/"+finfo.fileName() << endl;
        if (finfo.isDir()) {
            listFiles(finfo.absoluteFilePath());
        } else {
            //Calcul MD5 and store in a QHash
            QString m_sResValCryptoMD5;
            m_oHashMD5.SetInFile(finfo.absoluteFilePath());
            m_oHashMD5.SetOutFile("C:/Data/OutFile");
            m_oHashMD5.CalculateCryptoMD5();
            if(m_oHashMD5.IsOk() == true){
                m_sResValCryptoMD5 = m_oHashMD5.GetResCryptoMD5();
                mylist.insert(m_sResValCryptoMD5,finfo.absoluteDir().dirName()+"/"+finfo.fileName());
            }
        }
    }
    return mylist;
}

QList<QString> FileRead::compareFileList(QHash<QString, QString> local, QHash<QString, QString> remote){
    QString key;
    QList<QString> result;
    foreach(key, local.keys()){
        if(!remote.contains(key)){
            result.append(local[key]);
        }
    }
    return result;
}
