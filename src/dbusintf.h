#ifndef DBUSINTF_H
#define DBUSINTF_H

#include <QDBusAbstractAdaptor>


class DBusIntf : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.giuliettasw.testinput")
public:
    explicit DBusIntf(QObject *parent = 0);
public slots:
    Q_NOREPLY void openApp();
};

#endif // DBUSINTF_H
