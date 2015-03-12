/* 
 * File:   main.h
 * Author: byrdie
 *
 * Created on March 12, 2015, 1:09 PM
 */

#ifndef MAIN_H
#define	MAIN_H

//#ifdef	__cplusplus
//extern "C" {
//#endif

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

    // Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace AL;
using namespace cv;

    Point find_ball(Mat img);


//#ifdef	__cplusplus
//}
//#endif

#endif	/* MAIN_H */

