#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>

ros::Publisher pub;

void cb_receiveInt(const std_msgs::Int32& msg)
{
    std_msgs::Float64 f;
    f.data = msg.data*M_PI/180.0;
    pub.publish(f);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "deg2rad");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("topic_int", 1000, cb_receiveInt);
    pub = nh.advertise<std_msgs::Float64>("topic_float", 1000);
    ros::spin(); // to enable msg callback functions
}


