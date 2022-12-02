TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

DISTFILES += \
    README.md

HEADERS += \
    controller/active.h \
    controller/character.h \
    controller/dungeoncrawler.h \
    controller/passive.h \
    level/MapPack1.h \
    level/level.h \
    npc/abstractcontroller.h \
    npc/guardcontroller.h \
    npc/npc.h \
    tiles/door.h \
    tiles/floor.h \
    tiles/pit.h \
    tiles/portal.h \
    tiles/ramp.h \
    tiles/switch.h \
    tiles/tile.h \
    tiles/wall.h \
    ui/gui/TilePixmap.h \
    ui/gui/graphicalui.h \
    ui/tui/terminalui.h

SOURCES += \
    controller/character.cpp \
    controller/dungeoncrawler.cpp \
    controller/passive.cpp \
    level/level.cpp \
    main.cpp \
    npc/abstractcontroller.cpp \
    npc/guardcontroller.cpp \
    npc/npc.cpp \
    tiles/door.cpp \
    tiles/floor.cpp \
    tiles/pit.cpp \
    tiles/portal.cpp \
    tiles/ramp.cpp \
    tiles/switch.cpp \
    tiles/tile.cpp \
    tiles/wall.cpp \
    ui/abstractui.cpp \
    ui/gui/graphicalui.cpp \
    ui/tui/terminalui.cpp
