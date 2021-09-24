#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <QObject>
#include <QVariant>
#include <QtDebug>
#include <QTimer>


//ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>



class Publisher : public QObject
{
    Q_OBJECT
public:
    //explicit Publisher(QObject *parent = nullptr);
    Publisher();
    ~Publisher();
    Q_PROPERTY(int msg READ getMsg WRITE setMsg NOTIFY Msg_Sig);
    void setMsg(int data);
    int getMsg();


signals:

    void Msg_Sig();

public slots:
    void publishdMsg_btn_1();
    void publishdMsg_btn_2();


private:
    int _value;
    ros::NodeHandle *_nh;
    ros::Publisher _pub_btn_1;
    ros::Publisher _pub_btn_2;
    ros::Subscriber _subscriber;


};

#endif // PUBLISHER_H
