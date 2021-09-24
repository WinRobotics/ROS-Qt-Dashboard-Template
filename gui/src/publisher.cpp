#include "publisher.h"


Publisher::Publisher()
{
    _nh = new ros::NodeHandle();
    _pub_btn_1 = _nh->advertise<std_msgs::Int8>("Publish_btn_1",100);
    _pub_btn_2 = _nh->advertise<std_msgs::Int8>("Publish_btn_2",100);

}

Publisher::~Publisher()
{
    delete _nh;
}


void Publisher::setMsg(int data)
{

}

int Publisher::getMsg()
{
    return _value;
}

void Publisher:: publishdMsg_btn_1()
{

    std_msgs::Int8 msg;
    msg.data =12;
    _pub_btn_1.publish(msg);
     ros::spinOnce();


}

void Publisher::publishdMsg_btn_2()
{
    std_msgs::Int8 msg;
    msg.data =14;
    _pub_btn_2.publish(msg);
     ros::spinOnce();
}

