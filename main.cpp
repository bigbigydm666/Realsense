/*
 * @Author: your name
 * @Date: 2020-12-15 17:01:23
 * @LastEditTime: 2020-12-15 17:19:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /RSDRIVER/main.cpp
 */
#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include <librealsense2/rsutil.h>
#include <iostream>

using namespace cv;
using namespace std;
using namespace rs2;
#define Width 1920
#define Height 1080



int main()
{
//-------------------------------------------------线内代码勿动--------------------------------------------------------------------//
   pipeline pipe;
   config pipe_config;
   pipe_config.enable_stream(RS2_STREAM_COLOR,Width,Height,RS2_FORMAT_BGR8,30);
   pipeline_profile profile = pipe.start(pipe_config);
   frameset frameset = pipe.wait_for_frames();
   frame color_frame = frameset.get_color_frame();

   const int color_w=color_frame.as<video_frame>().get_width();
   const int color_h=color_frame.as<video_frame>().get_height();

   Mat color_image(Size(color_w,color_h),
                        CV_8UC3,(void*)color_frame.get_data(),Mat::AUTO_STEP);
   //---------------------------------------------分割线---------------------------------------------------------------//
   imshow("111", color_image);
   waitKey(0);

   return 0;
}

