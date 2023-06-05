QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    botellas.cpp \
    enemigos.cpp \
    gasolina.cpp \
    inodoro.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    orina.cpp \
    personaje2.cpp \
    personaje3.cpp

HEADERS += \
    botellas.h \
    enemigos.h \
    gasolina.h \
    inodoro.h \
    mainwindow.h \
    obstaculo.h \
    orina.h \
    personaje2.h \
    personaje3.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
