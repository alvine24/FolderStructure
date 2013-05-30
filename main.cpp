#include <QApplication>
#include "XmlTest.h"
#include "ClassXml.h"
#include "FileRead.h"

bool testXml()
{
    XmlTest test;
    test.CreateXMLFile();
    return test.mresult;
}

bool testClassXml()
{
    ClassXml test1;
    test1.FileXml();
    return test1.mresult;
}

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
