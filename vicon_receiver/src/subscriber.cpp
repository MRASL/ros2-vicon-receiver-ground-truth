#include <functional>
#include <memory>
#include <eigen3/Eigen/Dense>
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/position.hpp"
#include "vicon_receiver/publisher.hpp"

using std::placeholders::_1;
using namespace std;
using Eigen::MatrixXd;
using Eigen::MatrixXf;

class GroundTruth : public rclcpp::Node
{
public:
    GroundTruth()
    : Node("reading_ground_truth")
    {
        subscription_ = this->create_subscription<vicon_receiver::msg::Position>(
            "/vicon/create_robot_test/create_robot_test", std::bind(&GroundTruth::topic_callback, this, _1));
    }

private:
    MatrixXd position = MatrixXd(1,2); //ground truth location
    void topic_callback(const vicon_receiver::msg::Position::SharedPtr msg)
    {
        //position(0) = msg-> 
        //position(1) = msg-> 
    }

    rclcpp::Subscription<vicon_receiver::msg::Position>::SharedPtr subscription;    

}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GroundTruth>());
  rclcpp::shutdown();
  return 0;
} 
