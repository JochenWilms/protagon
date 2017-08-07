#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T17:21:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = protagon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        display.cpp \
    world.cpp \
    world_handler.cpp \
    #world.cpp  \
    pathfinder.cpp \
    node.cpp

HEADERS  += mainwindow.h \
    world.h \
    world_global.h \
    display.h \
    world_handler.h  \
    pathfinder.h \
    node.h


FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./lib/ -lworld
win32: LIBS += -L$$PWD/./lib/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -lworld
else:unix: LIBS += -L$$PWD/./ -lworld

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

DISTFILES += \
    maze1.png \
    ../../game/Game/smile.jpg


RESOURCES += \
    resource.qrc
