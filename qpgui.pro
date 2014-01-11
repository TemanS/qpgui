#-------------------------------------------------
#
# Project created by QtCreator 2011-12-16T17:35:36
#
#-------------------------------------------------

TARGET = qpgui
TEMPLATE = lib

CONFIG += staticlib

DEFINES += QPGUI_LIBRARY

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += qpgui.cpp \
    style.cpp \
    msg.cpp \
    qpfile.cpp \
    qpgroupbox.cpp \
    wlineedit.cpp

HEADERS += qpgui.h\
        qpgui_global.h \
    layout.h \
    controlgroup.h \
    style.h \
    msg.h \
    qpfile.h \
    qpgroupbox.h \
    wlineedit.h

debug {
    DESTDIR = ../lib/debug
}

release {
    DESTDIR = ../lib/release
}

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2CA2A10
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = qpgui.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}









