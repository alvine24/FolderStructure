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
        if(!remote.contains(key) || remote[key] != local[key]){
            result.append(local[key]);
        }
    }
    return result;
}


bool FileRead::saveToUserFolder(QString &filename, QIODevice *data){
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }
    file.write(data->readAll());
    file.close();

    return true;
}

QString FileRead::getFilename(QUrl url){
    QString myPath = url.path();

    QString fileBaseName = QFileInfo(myPath).fileName();

    if(fileBaseName.isEmpty()){
        //To do
    }
    if(QFile::exists(fileBaseName)){ //file already exists
        //Save the name with a new name
        int i = 0;
        while(QFile::exists(fileBaseName+QString::number(i)))
            i++;
        fileBaseName += QString::number(i);
    }
    return fileBaseName;
}
