#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "system_manager.h"

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "wayland;xcb");

    QGuiApplication app(argc, argv);
    app.setApplicationName("UzOS Desktop Shell");
    app.setOrganizationName("UzOS");
    app.setApplicationVersion("1.0.0");

    QQuickStyle::setStyle("Basic");

    QQmlApplicationEngine engine;
    SystemManager systemManager;

    engine.rootContext()->setContextProperty("SystemManager", &systemManager);

    const QUrl url(u"qrc:/qml/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
