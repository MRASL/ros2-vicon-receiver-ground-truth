#include "vicon_receiver/publisher.hpp"
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <cmath>

using namespace Eigen;
using namespace std;


Publisher::Publisher(std::string topic_name, rclcpp::Node* node)
{
    position_publisher_ = node->create_publisher<vicon_receiver::msg::Position>(topic_name, 10);
    is_ready = true;
}

void Publisher::publish(PositionStruct p)
{
    auto msg = std::make_shared<vicon_receiver::msg::Position>();
    // auto euler = p.rotation.toRotationMatrix().eulerAngles(0, 1, 2);
    
    msg->x_trans = p.translation[0];
    msg->y_trans = p.translation[1];
    msg->z_trans = p.translation[2];
    msg->x_rot = p.rotation[0];
    msg->y_rot = p.rotation[1];
    msg->z_rot = p.rotation[2];
    msg->w = p.rotation[3];
    msg->subject_name = p.subject_name;
    msg->segment_name = p.segment_name;
    msg->frame_number = p.frame_number;
    msg->translation_type = p.translation_type;
    position_publisher_->publish(*msg);

    q0 = p.rotation[0]; // xi
    q1 = p.rotation[1]; // yj
    q2 = p.rotation[2]; // zk
    q3 = p.rotation[3]; // w
    pose(0) = p.translation[0]; // x
    pose(1) = p.translation[1]; // y

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q3 * q0 + q1 * q2);
    double cosr_cosp = 1 - 2 * (q0 * q0 + q1 * q1);
    euler(0) = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (q3 * q1 - q2 * q0);
    if (std::abs(sinp) >= 1)
        euler(1) = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        euler(1) = asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q3 * q2 + q0 * q1);
    double cosy_cosp = 1 - 2 * (q1 * q1 + q2 * q2); 
    euler(2) = (atan2 (siny_cosp, cosy_cosp) * 180 / M_PI); // angle from the topdown (deg)
    pose (2) = (atan2 (siny_cosp, cosy_cosp) * 180 / M_PI); // angle from the topdown (deg)
    
    // angle from the topdown (deg)
    /*if (pose(2) >= 90 && pose(2) <=180)
        pose(2) = pose(2) - 90;
    else
        pose(2) = pose(2) + 270;*/
    
    // angle from the topdown (rad)
    // pose (2) = (atan2 (siny_cosp, cosy_cosp)) + (M_PI / 4); 
    //if (pose(2) >= (M_PI/4) && pose(2) <= (M_PI/2))
      //  pose(2) = pose(2) - (M_PI / 4); 
    //else
      //  pose(2) = pose(2) + (1.5 * M_PI);

    cout << "Ground Truth: " << pose << endl;
}
