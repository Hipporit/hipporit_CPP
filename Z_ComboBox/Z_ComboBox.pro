CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(z_comboboxplugin)
TEMPLATE    = lib

RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(z_combobox.pri)

FORMS += \
    z_combobox.ui

HEADERS += \
    z_comboboxplugin.h\


SOURCES += \
    z_comboboxplugin.cpp
