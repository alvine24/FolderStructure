#include <QApplication>
#include "FileRead.h"

bool testFileRead()
{
    FileRead test2;
    QHash<QString, QString> myHash = test2.listFiles(QDir::currentPath());
    QString key;
    foreach(key, myHash.keys()){
        qDebug() << key << " = " << myHash[key];
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //qDebug() << testXml();
    //qDebug() << testClassXml();
    qDebug() << testFileRead();

    return app.exec();
}
