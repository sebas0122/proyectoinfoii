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
    inodoroj.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    orina.cpp \
    personaje_2.cpp \
    personaje_3.cpp

HEADERS += \
    botellas.h \
    enemigos.h \
    gasolina.h \
    inodoroj.h \
    mainwindow.h \
    obstaculo.h \
    orina.h \
    personaje_2.h \
    personaje_3.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
