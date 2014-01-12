
message("Building libqpgui ...")

# TARGET is qpgui, and TEMPLATE is lib, so the output of this build will
# be libqpgui.a
#
TARGET = qpgui
TEMPLATE = lib

CONFIG += staticlib

DEFINES += QPGUI_LIBRARY

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    style.cpp \
    msg.cpp \
    qpfile.cpp \
    qpgroupbox.cpp \
    wlineedit.cpp

HEADERS += \
    qpgui.h\
    qpgui_global.h \
    layout.h \
    controlgroup.h \
    style.h \
    msg.h \
    qpfile.h \
    qpgroupbox.h \
    wlineedit.h

# Output the libqpgui.a file to the directory immediately above the
# respective build file.
#
debug {
    DESTDIR = ../lib/
}

release {
    DESTDIR = ../lib
}
