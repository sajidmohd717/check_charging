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
    //ROS_INFO("I heard: [%s]", msg->data.c_str());
  std_msgs::Bool output;
  if (strcmp(msg->message.c_str(), "charging"))
  {
    output.data = false;
  }
  else
    output.data = true;
//   //ROS_INFO("I heard: [%s]", msg->message.c_str());
//   //ROS_INFO("I heard: [%i]", var.data);
//   chatter_pub.publish(var);


    // std_msgs::Bool output;
    //.... do something with the input and generate the output...
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



// void chatterCallback(const xnergy_charger_rcu::ChargerState::ConstPtr& msg);

//   ros::init(argc, argv, "listener");

//   ros::NodeHandle n;

//   //ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//   // ros::Subscriber sub = n.subscribe("xnergy_charger_rcu/rcu_status", 1000, chatterCallback);

//   // ros::Publisher chatter_pub = n.advertise<std_msgs::Bool>("chatter", 1000);

// void chatterCallback(const xnergy_charger_rcu::ChargerState::ConstPtr& msg)
// {
//   //ROS_INFO("I heard: [%s]", msg->data.c_str());
//   std_msgs::Bool var;
//   if (strcmp(msg->message.c_str(), "charging"))
//   {
//     var.data = false;
//   }
//   else
//     var.data = true;
//   //ROS_INFO("I heard: [%s]", msg->message.c_str());
//   //ROS_INFO("I heard: [%i]", var.data);
//   chatter_pub.publish(var);
// }

// int main(int argc, char **argv)
// {
//   // ros::init(argc, argv, "listener");

//   // ros::NodeHandle n;

//   // //ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//   // ros::Subscriber sub = n.subscribe("xnergy_charger_rcu/rcu_status", 1000, chatterCallback);

//   // ros::Publisher chatter_pub = n.advertise<std_msgs::Bool>("chatter", 1000);

//   ros::spin();

//   return 0;
// }