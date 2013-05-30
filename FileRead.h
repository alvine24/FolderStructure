#ifndef FILEREAD_H
#define FILEREAD_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QString>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QDir>
#include <QHash>
#include "FileHash.h"

class FileRead
{
public:
    FileRead();
    void listFiles(QString mDir);

    bool mresult;
    QHash<QString, QString> mylist;
    FileHash m_oHashMD5;
};

#endif // FILEREAD_H
