#include <ros/ros.h>
#include <std_msgs/Float64.h>

void callback_receiveFloat(const std_msgs::Float64& msg)
{ 
    ROS_INFO_STREAM("Float received: " << msg.data);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "sub_out_float");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic_float", 1000, callback_receiveFloat);
    ros::spin();
}


