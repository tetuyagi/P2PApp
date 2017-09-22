#-------------------------------------------------
#
# Project created by QtCreator 2017-08-30T18:25:04
#
#-------------------------------------------------

QT       += core gui \
            network \
            multimedia multimediawidgets \
            serialbus \
             websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P2PApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    audio.cpp \
    rudpsessionserver.cpp \
    rudpserver.cpp \
    addressmap.cpp \
    address.cpp \
    ../WebsocketApp/websocketclient.cpp \
    roomwindow.cpp

HEADERS  += mainwindow.h \
    camera.h \
    audio.h \
    utility.h \
    rudpsessionserver.h \
    rudpserver.h \
    addressmap.h \
    address.h \
    ../WebsocketApp/websocketclient.h \
    roomwindow.h


FORMS    += mainwindow.ui \
    roomwindow.ui

CONFIG += mobility

INCLUDEPATH += /Users/tyagi/Qt/5.8/clang_64/lib/QtNetwork.framework/Headers \
               /Users/tyagi/Qt/5.8/clang_64/lib/QtMultimedia.framework/Headers \
               /Users/tyagi/Qt/5.8/clang_64/lib/QtMultimediaWidgets.framework/Headers

RESOURCES += \
    white.qrc

