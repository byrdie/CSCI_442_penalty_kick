/* 
 * File:   main.h
 * Author: byrdie
 *
 * Created on March 12, 2015, 1:09 PM
 */

#ifndef MAIN_H
#define	MAIN_H


// Standard includes
#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <list>

// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>
#include <alproxies/alledsproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace AL;
using namespace cv;

/*HSV values for the YELLOW tennis ball*/;
int iLowH = 19; // Hue
int iHighH = 39;
int iLowS = 109; // Saturation
int iHighS = 255;
int iLowV = 55; // value
int iHighV = 255;

const std::string robotIp("153.90.197.249");


Point find_ball(Mat img);
void ball_track(const std::string& robotIp);


#endif	/* MAIN_H */

