QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR = $${PWD}

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

TRANSLATIONS += \
	translations/translatable_widget_ja_JP.ts \
	translations/translatable_widget_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../translator/release/ -ltranslator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../translator/debug/ -ltranslator
else:unix: LIBS += -L$$OUT_PWD/../translator/ -ltranslator

INCLUDEPATH += $$PWD/../translator
DEPENDPATH += $$PWD/../translator
