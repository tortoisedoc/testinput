# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = testinput
CONFIG += console
CONFIG += sailfishapp

QT += gui-private dbus

SOURCES += src/testinput.cpp \
    src/dbusintf.cpp


OTHER_FILES += qml/testinput.qml \
    rpm/testinput.changes.in \
    rpm/testinput.spec \
    rpm/testinput.yaml \
    translations/*.ts \
    testinput.desktop \
    testinput.service \
    com.giuliettasw.testinput.service

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/testinput-de.ts

systemd.path = /etc/systemd/user
systemd.files = testinput.service

dbus.path = /usr/share/dbus-1/services
dbus.files = com.giuliettasw.testinput.service


INSTALLS += systemd dbus

HEADERS += \
    src/dbusintf.h
