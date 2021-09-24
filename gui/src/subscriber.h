#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <QObject>
#include <QVariant>
#include <QtDebug>
#include <QTimer>
#include <memory>

//ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>

class Subscriber : public QObject
{
    Q_OBJECT
public:

    Subscriber();
    ~Subscriber();
    void thread_callback(const std_msgs::Int8 &msg);
    void threading();


signals:



public slots:


private:

    ros::NodeHandle *_nh;
    ros::Subscriber _thread_sub;



};

#endif // SUBSCRIBER_H
