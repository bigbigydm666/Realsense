/*
 * @Author: your name
 * @Date: 2020-12-15 17:01:23
 * @LastEditTime: 2020-12-18 21:25:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /RSDRIVER/main.cpp
 */
#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include <librealsense2/rsutil.h>
#include <iostream>
#include "Realsense.hpp"
using namespace cv;
using namespace std;
using namespace rs2;





int main()
{


   Realsense d435;
   d435.setSize(960, 540);
   d435.init();
   d435.setSensor(BLUE);
   
   Mat src;
   while(true)
   {
      src = d435.getimg();

      imshow("111", src);
      waitKey(1); 
   }
   return 0;
}

