#-------------------------------------------------
#
# Project created by QtCreator 2017-02-25T12:37:27
#
#-------------------------------------------------

QT       += xml xmlpatterns

QT       -= gui

TARGET = decentralised_data
TEMPLATE = lib
CONFIG += staticlib

win32:CONFIG(release, debug|release): LIBS += -L"C:/Program Files/OpenSSL/lib/" -llibcrypto
else:win32:CONFIG(debug, debug|release): LIBS += -L"C:/Program Files/OpenSSL/lib/" -llibcrypto
else:unix: LIBS += -L"/usr/local/lib/" -lcrypto

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

win32:INCLUDEPATH += "C:/Program Files/OpenSSL/include/"
else:INCLUDEPATH += "/usr/local/include/"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += decentralised_data.cpp \
    dc_host.cpp \
    dc_user.cpp

HEADERS += decentralised_data.h \
    dc_host.h \
    dc_data_error.h \
    dc_user.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
