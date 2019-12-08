#-------------------------------------------------
#
# Project created by QtCreator 2019-12-02T00:10:54
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = decanat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Control/application.cpp \
        Control/contextdb.cpp \
        Control/departmentcontrol.cpp \
        Control/groupcontrol.cpp \
        Control/specialtycontrol.cpp \
        Control/studentcontrol.cpp \
        Entity/department.cpp \
        Entity/group.cpp \
        Entity/specialty.cpp \
        Entity/student.cpp \
        Interface/changerecord.cpp \
        Interface/listview.cpp \
        Interface/menu.cpp \
        main.cpp

HEADERS += \
    Control/application.h \
    Control/contextdb.h \
    Control/departmentcontrol.h \
    Control/groupcontrol.h \
    Control/specialtycontrol.h \
    Control/studentcontrol.h \
    Entity/department.h \
    Entity/group.h \
    Entity/specialty.h \
    Entity/student.h \
    Interface/changerecord.h \
    Interface/listview.h \
    Interface/menu.h \
    recordchangemode.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
