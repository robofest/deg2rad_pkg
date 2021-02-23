#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>

class Deg2Rad
{
public:
    Deg2Rad()
    {
        sub = nh.subscribe("topic_int", 1000, &Deg2Rad::cb_receiveInt, this); // note &Deg2Rad:: is added
        pub = nh.advertise<std_msgs::Float64>("topic_float", 1000);
    }
    void cb_receiveInt(const std_msgs::Int32& msg); // prototype

private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
};

void Deg2Rad::cb_receiveInt(const std_msgs::Int32& msg)
{
    std_msgs::Float64 f;
    f.data = msg.data*M_PI/180.0;
    ROS_INFO_STREAM("via deg2rad_OO node");
    pub.publish(f);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "deg2rad_OO");
    Deg2Rad dr{};   // C++11 brace-initialization. Same as Deg2Rad dr;
                    // since all the code is in the constructor
                    // we do not need to do anything else with this object dr here.
    ros::spin();    // to enable msg callback functions
}
