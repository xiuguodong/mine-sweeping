QT       += core gui
QT       += multimedia

#let us play a beutiful music :)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += resources_big
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    freemode.cpp \
    losecg.cpp \
    main.cpp \
    minecg.cpp \
    minemode.cpp \
    startgame.cpp \
    wincg.cpp

HEADERS += \
    freemode.h \
    losecg.h \
    minecg.h \
    minemode.h \
    startgame.h \
    wincg.h

FORMS += \
    freemode.ui \
    losecg.ui \
    minecg.ui \
    minemode.ui \
    startgame.ui \
    wincg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
