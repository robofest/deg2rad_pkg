#include <ros/ros.h>
#include <std_msgs/Int32.h>
using namespace std;

int main (int argc, char **argv)
{
    ros::init(argc, argv, "get_pub_int");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic_int", 1000);
    std_msgs::Int32 im;
    std::string s;

    while(ros::ok()) {
        try {
	        cout << "Enter a number: ";
	        getline(cin, s);
                im.data = std::stoi(s);
	        pub.publish(im); 
	} catch (std::exception& e) {
		cout << e.what() << " error. Try again. " << endl;
	}
    }
}


