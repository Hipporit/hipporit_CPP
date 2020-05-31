CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(z_sliderplugin)
TEMPLATE    = lib

HEADERS     = z_sliderplugin.h \
    z_slider.h
SOURCES     = z_sliderplugin.cpp \
    z_slider.cpp
RESOURCES   =
LIBS        += -L.

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

FORMS += \
    z_slider.ui


