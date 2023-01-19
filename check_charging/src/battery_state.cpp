#include "ros/ros.h"
#include "xnergy_charger_rcu/ChargerState.h"
#include "std_msgs/Bool.h"
#include <string.h>


#include <ros/ros.h>

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<std_msgs::Bool>("chatter", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("xnergy_charger_rcu/rcu_status", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const xnergy_charger_rcu::ChargerState::ConstPtr& msg)
  {
  std_msgs::Bool output;
  if (strcmp(msg->message.c_str(), "charging"))
  {
    output.data = false;
  }
  else
    output.data = true;
    pub_.publish(output);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
