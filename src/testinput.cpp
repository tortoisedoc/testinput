/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QDBusConnection>
#include <QDBusError>
#include <sailfishapp.h>
#include <qpa/qplatformnativeinterface.h>
#include <qpa/qplatformwindow.h>

#include "dbusintf.h"

extern QQuickView* mainView = NULL;

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QGuiApplication * app = SailfishApp::application(argc, argv);

    // create the MainApplication adaptor:
    DBusIntf * intf = new DBusIntf(app);
    bool res = QDBusConnection::sessionBus().registerObject("/MainApplication", intf);
    QString service("com.giuliettasw.testinput");
    res = QDBusConnection::sessionBus().registerService(service);

    qDebug() << " DBUS REGISTERATION RESULT : " << res << " LAST ERROR " << QDBusConnection::sessionBus().lastError();

    mainView = SailfishApp::createView();

    QSize screenSize = mainView->screen()->size();
    mainView->setGeometry(QRect(0, 0, screenSize.width(), screenSize.height()));

    mainView->setObjectName("main");

    //mainView->setResizeMode(QQuickView::SizeViewToRootObject);

    QSurfaceFormat format;
    format = mainView->format();
    //qDebug() << format;
    format.setAlphaBufferSize(8);
    mainView->setClearBeforeRendering(true);
    mainView->setFormat(format);
    mainView->setColor(QColor(Qt::transparent));

    QString qmlPath("qml/testinput.qml");
    QUrl path (SailfishApp::pathTo(qmlPath));
    mainView->setSource(path);

    QPlatformNativeInterface *native = QGuiApplication::platformNativeInterface();
    mainView->create();
    QRegion inputRegion(0,0,200,900);
    //QRegion inputRegion(mainView->geometry());
    native->setWindowProperty(mainView->handle(), QLatin1String("MOUSE_REGION"), inputRegion);
    mainView->setMask(inputRegion);
    native->setWindowProperty(mainView->handle(), QLatin1String("CATEGORY"), QString("notification"));
    mainView->show();
    return app->exec();
}

