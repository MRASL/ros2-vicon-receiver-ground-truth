# Vicon receiver for ROS2 ![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/andreacamisa/ros2-vicon-receiver)

**ros2-vicon-receiver** is a ROS2 package, written in C++, that retrieves data from Vicon software and publishes it on ROS2 topics. The code is partly derived from a mixture of [Vicon-ROS2](https://github.com/aheuillet/Vicon-ROS2) and [Vicon bridge](https://github.com/ethz-asl/vicon_bridge).

This is NOT an official ROS2 package and is not supported. The package has been successfully tested with ROS2 Dashing Diademata, ROS2 Foxy and ROS2 Galactic on the operating systems Ubuntu 18.04 Bionic Beaver, Ubuntu 20.04 Focal Fossa and MacOS 10.13 High Sierra.

## Requirements

### Installation of dependencies

If you are using Ubuntu 18.04 Bionic Beaver, you can install all the dependencies by simply `cd`'ing into the main project folder and then running
```
$ ./install_ubuntu_bionic.sh
```

Otherwise, proceed as follows. Make sure you have ROS2 installed (follow the instructions at the [ROS2 website](https://index.ros.org/doc/ros2/Installation/)).

Then, install [Colcon](https://colcon.readthedocs.io/en/released/index.html) and [CMake](https://cmake.org/) :
```
$ sudo apt install -y python3-colcon-common-extensions cmake
```

### Installation of Datastream SDK and other libraries

The Datastream SDK libraries are required to be installed in the system. You can find them on [the official website](https://www.vicon.com/software/datastream-sdk/?section=downloads).

This package is shipped with Datastream SDK 10.1 (the latest version at the time of writing). If you are running Linux x64 and you want to install this version, simply `cd` into the main project folder and issue the command
```
$ ./install_libs.sh
```

## Quick start

### Building the package

:warning: Do not forget to source the ROS2 workspace: `source /opt/ros/dashing/setup.bash`

Enter the project folder and build the executable
```
$ cd vicon_receiver
$ colcon build --symlink-install
```

### Running the program

Open a new terminal and source the project workspace:
```
$ source vicon_receiver/install/setup.bash
```

To run the program, use the [launch file template](vicon_receiver/launch/client.launch.py) provided in the package. First, open the file and edit the parameters, change the `hostname` to **192.168.1.200**, which is the IP address of the vicon server. Running `colcon build` is not needed because of the `--symlink-install` option previously used.

Now you can the program with
```
$ ros2 launch vicon_receiver client.launch.py
```

Exit the program with CTRL+C.

### Information on ROS2 topics and messages

The **ros2-vicon-receiver** package creates a topic for each segment in each subject with the pattern `namespace/subject_name/segment_name`. Information is published on the topics as soon as new data is available from the vicon client (typically at the vicon client frequency). The message type [Position](vicon_receiver/msg/Position.msg) is used.

Example: I named the object as `create_robot` with four segments each (`create_robot_1`, `create_robot_2`, `create_robot_3`, and `create_robot_4`). Then **ros2-vicon-receiver** will publish [Position](vicon_receiver/msg/Position.msg) messages on the following topics:
```
vicon/create_robot/create_robot_1
vicon/create_robot/create_robot_2
vicon/create_robot/create_robot_3
vicon/create_robot/create_robot_4
```
## Code modifications
In order to get the customized data from the topic, we only save x-position, y-position, and angle from the topdown (angle with respect to the z-axis) into the `pose` matrix.

## Constributors
**ros2-vicon-receiver** is developed by
[Andrea Camisa](https://www.unibo.it/sitoweb/a.camisa),
[Andrea Testa](https://www.unibo.it/sitoweb/a.testa) and
[Giuseppe Notarstefano](https://www.unibo.it/sitoweb/giuseppe.notarstefano)
