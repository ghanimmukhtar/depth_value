cmake_minimum_required(VERSION 2.8.3)
project(depth_value)

find_package(catkin REQUIRED COMPONENTS
  pcl_ros
  roscpp
  rospy
  sensor_msgs
  std_msgs
  pcl_conversions
)
find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenCV REQUIRED COMPONENTS features2d nonfree)
find_package(VTK REQUIRED)
find_package(PCL 1.7 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS}
        ${Eigen_INCLUDE_DIRS}
        /usr/local/include/image_processing
        /usr/local/include/rgbd_utils)

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
link_directories(/usr/local/lib)


set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES rgbd_utils
  CATKIN_DEPENDS pcl_ros roscpp rospy sensor_msgs std_msgs pcl_conversions 
)

include_directories(include
/usr/local/include/cafer_core)
include_directories(
  ${catkin_INCLUDE_DIR}
)

add_executable(depth_value src/depth_value.cpp)
target_link_libraries(depth_value ${catkin_LIBRARIES} image_processing )
