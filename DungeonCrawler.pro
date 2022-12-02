TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        abstractcontroller.cpp \
        abstractui.cpp \
        active.cpp \
        character.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        graphicalui.cpp \
        guardcontroller.cpp \
        level.cpp \
        main.cpp \
        npc.cpp \
        passive.cpp \
        pit.cpp \
        portal.cpp \
        ramp.cpp \
        switch.cpp \
        terminalui.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
    MapPack1.h \
    TilePixmap.h \
    abstractcontroller.h \
    abstractui.h \
    active.h \
    character.h \
    door.h \
    dungeoncrawler.h \
    floor.h \
    graphicalui.h \
    guardcontroller.h \
    level.h \
    npc.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    switch.h \
    terminalui.h \
    tile.h \
    wall.h
