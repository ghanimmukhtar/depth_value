#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <image_processing/pcl_types.h>
#include <pcl_conversions/pcl_conversions.h>

static float x;
static float y;

using namespace image_processing;

void callback(const sensor_msgs::PointCloud2ConstPtr &cloud){
  PointCloudT ptcl;
  pcl::fromROSMsg(*cloud,ptcl);
  float x_val = ptcl.at((int) x+(int) y*ptcl.width).x;
  float y_val = ptcl.at((int) x+(int) y*ptcl.width).y;
  std::cout << "at " << x << " " << y << " depth value = " << ptcl.at((int) x+(int) y*ptcl.width).z
            << " coords "  << x_val << " " << y_val << std::endl;
}

int main(int argc, char** argv){

  if(argc < 3){
      std::cout << "usage : 2 floats" << std::endl;
      return 1;
    }

  ros::init(argc,argv,"depth_value");
  ros::NodeHandle nodeHandle;

  x = atof(argv[1]);
  y = atof(argv[2]);

  ros::Subscriber sub = nodeHandle.subscribe<sensor_msgs::PointCloud2>("/camera/depth_registered/points",1,callback);

  ros::spin();

  return 0;
}
