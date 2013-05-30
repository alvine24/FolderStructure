#The file .pro to build and run the project must contain at least :

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XmlTest
TEMPLATE = app


SOURCES += FileRead.cpp \
    main.cpp

HEADERS  += FileRead.h

INCLUDEPATH += C:/Users/sheerServer/Projets/Qt/FileHash
LIBS+=  -LC:/Users/sheerServer/Projets/Qt/FileHash-build-Desktop_Qt_5_0_1_MSVC2010_32bit-Debug/debug -lFileHash
