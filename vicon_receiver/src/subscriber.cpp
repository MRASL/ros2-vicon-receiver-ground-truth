#include <functional>
#include <memory>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/position.hpp"
#include "vicon_receiver/publisher.hpp"

using std::placeholders::_1;
using namespace std;
using Eigen::MatrixXd;
using Eigen::MatrixXf;
using namespace Eigen;
static int n=0;
class GroundTruth : public rclcpp::Node
{
public:
    GroundTruth()
    : Node("ground_truth_reader")
    {
        subscription_ = this->create_subscription<vicon_receiver::msg::Position>(
            "/vicon/create_robot/create_robot",10, std::bind(&GroundTruth::topic_callback, this, _1));
    }

private:
    MatrixXd position = MatrixXd(1,2); //ground truth location
    void topic_callback(const vicon_receiver::msg::Position::SharedPtr msg)
    {
        cout<<"in callback"<<endl;
        Eigen::MatrixXd pose = Eigen::MatrixXd(1,2);
        Eigen::MatrixXd euler = Eigen::MatrixXd(1,3);
        double q0, q1, q2, q3;
        q0 = msg->x_rot; // xi
        q1 = msg->y_rot; // yj
        q2 = msg->z_rot; // zk
        q3 = msg->w; // w
        pose(0) = msg->x_trans; // x
        pose(1) = msg->y_trans; // y
        /*Quaternionf q(q3,q0,q1,q2);
        auto euler = q.toRotationMatrix().eulerAngles(0,1,2);*/
        double siny_cosp = 2 * (q3 * q2 + q0 * q1);
        double cosy_cosp = 1 - 2 * (q1 * q1 + q2 * q2);
        euler(2) = atan2 (siny_cosp, cosy_cosp);
        cout<<"Pose: "<<pose<<" Yaw: "<<euler(2)<<endl;
        ofstream f("pose_" + to_string(n) + ".csv");
        f<< pose(0)/1000 << "," << pose(1)/1000 << "," << euler(2) << endl;
        f.close();
        n++;
        cin.get();
    }

    rclcpp::Subscription<vicon_receiver::msg::Position>::SharedPtr subscription_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GroundTruth>());
  rclcpp::shutdown();
  return 0;
} 
