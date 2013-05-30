#include <QApplication>
#include "FileRead.h"

bool testFileRead()
{
    FileRead test2;
    test2.listFiles(QDir::currentPath());
    qDebug() << "Count : " << test2.mylist.count();

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
