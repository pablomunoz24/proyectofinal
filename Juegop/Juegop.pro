QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canon.cpp \
    enemigos.cpp \
    main.cpp \
    mainwindow.cpp \
    pirata.cpp \
    puntaje.cpp \
    salud.cpp

HEADERS += \
    canon.h \
    enemigos.h \
    mainwindow.h \
    pirata.h \
    puntaje.h \
    salud.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

DISTFILES += \
    Musica para el juego/y2mate.com - Bonus Game Win  Donkey Kong Country OST.mp3 \
    Musica para el juego/y2mate.com - Donkey Kong Country  Game Over Restored.mp3 \
    Musica para el juego/y2mate.com - Donkey Kong Country OST Super Nintendo  Track 0123  Theme.mp3 \
    Musica para el juego/y2mate.com - Gangplank Galleon Restored to HD.mp3
