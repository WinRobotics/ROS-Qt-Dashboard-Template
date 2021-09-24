#include "subscriber.h"

Subscriber::Subscriber()
{

      _nh = new ros::NodeHandle();
      //_thread_sub = _nh->subscribe<std_msgs::Int8>("Sub",100,&Subscriber::thread_callback,this); //this is not working
      _thread_sub = _nh->subscribe("sub",100,&Subscriber::thread_callback,this);
}

Subscriber::~Subscriber()
{
    
}

void Subscriber::thread_callback(const std_msgs::Int8 &msg)
{

          qDebug()<<"Trigger Subbing";
          //emit signal

}

void Subscriber::threading()
{
    while(ros::ok())
    {
        // qDebug()<<"Subbing";
        ros::spinOnce();
    }

}



