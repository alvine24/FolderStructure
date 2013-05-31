/**
* @file FileRead.h
* @brief this header file will contain all required
* definitions and basic utilities functions for the
* synchronization between user's folders on local and
* server.
*
* @author Alvine AGBO
*
* @date 5/31/2013
*
* @version 1.0
*/

#ifndef FILEREAD_H
#define FILEREAD_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QString>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QDir>
#include <QHash>
#include <QList>
#include "FileHash.h"

class FileRead
{
public:
    /**
     * @brief FileRead
     * This is the default constructor
     */
    FileRead();

    /**
     * @brief listFiles
     * This function helps to build a list of files in a
     * defined folder
     * @param mDir is the name or path of the folder
     * @return the result of this function is a QHash of
     * the name of each file and their MD5 sum
     */
    QHash<QString, QString> listFiles(QString mDir);

    /**
     * @brief compareFileList
     * This function compare the QHash of two list of files
     * @param local is the QHash of files list on local folder
     * @param remote is the QHash of files list on the server folder
     * @return is a QList of the file that are not on the remote or server
     */
    QList<QString> compareFileList(QHash<QString, QString> local, QHash<QString, QString> remote);

    bool mresult;
    QHash<QString, QString> mylist;
    FileHash m_oHashMD5;
};

#endif // FILEREAD_H
