QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auditoriums.cpp \
    connection.cpp \
    edit.cpp \
    groups.cpp \
    login.cpp \
    main.cpp \
    mainuser.cpp \
    mainwindow.cpp \
    schedule.cpp \
    teachers.cpp

HEADERS += \
    auditoriums.h \
    connection.h \
    edit.h \
    groups.h \
    login.h \
    mainuser.h \
    mainwindow.h \
    schedule.h \
    teachers.h

FORMS += \
    auditoriums.ui \
    edit.ui \
    groups.ui \
    login.ui \
    mainuser.ui \
    mainwindow.ui \
    schedule.ui \
    teachers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc
