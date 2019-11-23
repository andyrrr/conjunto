#-------------------------------------------------
#
# Project created by QtCreator 2019-09-23T23:51:38
#
#-------------------------------------------------

TEMPLATE = app
TARGET = curl



QT       += core gui multimedia multimediawidgets webenginewidgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


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
        conexion.cpp \
        curlobj.cpp \
        detalles.cpp \
        estructura.cpp \
        main.cpp \
        interfaz.cpp \
        pagina.cpp \
        pelicula.cpp \
        singletondataset.cpp \
        worker.cpp

HEADERS += \
        conexion.h \
        curlobj.h \
        detalles.h \
        estructura.h \
        interfaz.h \
        pagina.h \
        pelicula.h \
        prueba.h \
        singletondataset.h \
        worker.h

FORMS += \
        detalles.ui \
        interfaz.ui

LIBS += -lcurl

# CONFIG += link_pkgconfig
# PKGCONFIG += curl

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
