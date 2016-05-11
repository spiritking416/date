TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    read_data.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    read_data.h
