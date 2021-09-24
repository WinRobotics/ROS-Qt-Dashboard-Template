#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "publisher.h"
#include "subscriber.h"
#include "ros/ros.h"
#include <memory.h>
#include <thread>




int main(int argc, char *argv[])
{

    //init ROS
    ros::init(argc, argv, "Dashboard");
    //Creating instances
    std::shared_ptr<Publisher> pub = std::make_shared<Publisher>();
    std::shared_ptr<Subscriber> sub = std::make_shared<Subscriber>();

   std::thread subthread(&Subscriber::threading,sub.get());

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<Publisher>("com.STELS.Publisher",1,0,"Publisher");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
