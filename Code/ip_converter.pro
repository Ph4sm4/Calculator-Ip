QT       += core gui
RESOURCES += C:\Users\I9\Documents\QT\ip_converter_source\ip_converter\MyResources.qrc
RC_ICONS = ip.ico
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    credits.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    credits.h \
    mainwindow.h

FORMS += \
    about.ui \
    credits.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResources.qrc
