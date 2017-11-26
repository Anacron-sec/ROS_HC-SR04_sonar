#include <ros.h> // Robot Operating System (ROS) official library
#include <ArduinoHardware.h> // Arduino library for non Arduino IDE compatibility
#include <std_msgs/Int32.h> // Integer messages for ROS
#include <NewPing.h> // Library for HC-SR04 https://playground.arduino.cc/Code/NewPing

// HC-SR04 values
#define TRIGGER_PIN 9 
#define ECHO_PIN 10
#define MAX_DISTANCE 400 // Max distance in centimeters.

// Declare a sonar Object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Setup ros node and publisher
std_msgs::Int32 sonar_msg;
ros::Publisher pub_sonar("sonar", &sonar_msg);
ros::NodeHandle nh;

int SetDistance = 0;
int cm_distance = 0;

void setup() {
  nh.initNode();
  nh.advertise(pub_sonar);
}

void loop() {
  delay(50);
  unsigned int micro_seconds = sonar.ping();
  cm_distance = micro_seconds / US_ROUNDTRIP_CM;

  sonar_msg.data = cm_distance;
  pub_sonar.publish(&sonar_msg); // Publishes data on 

  nh.spinOnce();
  
}
