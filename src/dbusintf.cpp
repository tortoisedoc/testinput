#include "dbusintf.h"
#include <QDebug>
#include <QQuickView>


extern QQuickView * mainView;

DBusIntf::DBusIntf(QObject *parent) :
    QDBusAbstractAdaptor(parent){
}

void DBusIntf::openApp(){
    qDebug() << "TESTINPUT STARTED";
    mainView->show();
}
