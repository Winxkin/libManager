#-------------------------------------------------
#
# Project created by QtCreator 2021-10-24T11:46:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libManager
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    staff.cpp \
    home.cpp \
    memhome.cpp \
    manstaff.cpp \
    manmember.cpp \
    manbook.cpp \
    findbook.cpp \
    infostaff.cpp \
    infomember.cpp \
    borrow.cpp \
    breturn.cpp \
    bookdata.cpp

HEADERS  += login.h \
    staff.h \
    home.h \
    memhome.h \
    manstaff.h \
    manmember.h \
    manbook.h \
    findbook.h \
    global_variable.h \
    infostaff.h \
    infomember.h \
    borrow.h \
    breturn.h \
    bookdata.h

FORMS    += login.ui \
    home.ui \
    memhome.ui \
    manstaff.ui \
    manmember.ui \
    manbook.ui \
    findbook.ui \
    infostaff.ui \
    infomember.ui \
    borrow.ui \
    breturn.ui \
    bookdata.ui
