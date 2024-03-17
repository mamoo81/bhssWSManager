#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket> // https bağlantılarını açabilmek için. mesela https://img.basat.dev/ adresindeki ürün resimleri için.
#include <QDebug>
#include <restapihelper.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<RestApiHelper>("RestApiHelper", 1, 0, "RestApiHelper");

    const QUrl url(u"qrc:/bhssWSManager/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
