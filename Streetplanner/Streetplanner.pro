QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    city.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    abstractmap.cpp \
    newstreet.cpp \
    shortway.cpp \
    street.cpp \
    mapio.cpp \
    mapionrw.cpp \
    dijkstra.cpp

HEADERS += \
    city.h \
    dialog.h \
    mainwindow.h \
    map.h \
    abstractmap.h \
    newstreet.h \
    shortway.h \
    street.h \
    mapio.h \
    mapionrw.h \
    dijkstra.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    newstreet.ui \
    shortway.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
