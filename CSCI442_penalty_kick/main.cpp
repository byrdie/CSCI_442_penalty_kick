/* 
 * File:   main.cpp
 * Author: Roy Smart, Zach Fisher
 *
 * Created on March 4, 2015, 6:29 AM
 */

// Standard includes
#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <string>


// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace AL;
using namespace cv;

//extern "C" {

/**
 * \brief Shows images retrieved from the robot.
 *
 * \param robotIp the IP adress of the robot
 */
void showImages(const std::string& robotIp) {
    /** Create a proxy to ALVideoDevice on the robot.*/
    ALVideoDeviceProxy camProxy(robotIp, 9559);

    /** Subscribe a client image requiring 320*240 and BGR colorspace.*/
    const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

    /** Create an cv::Mat header to wrap into an opencv image.*/
    cv::Mat img = cv::Mat(cv::Size(320, 240), CV_8UC3);
    cv::Mat run_ave = cv::Mat(img.size(), CV_8UC3);
    cv::Mat weightedFrame = cv::Mat(img.size(), CV_32FC3);

    /** Create a OpenCV window to display the images. */
    cv::namedWindow("images", CV_WINDOW_KEEPRATIO);
    cv::namedWindow("Thresholded Image", CV_WINDOW_KEEPRATIO);
    cv::namedWindow("Averages", CV_WINDOW_KEEPRATIO);

    /*create vector of points to store trajectory of ball*/
    vector<Point> traject(100); // only track the last 100 points

    /*create image buffers*/
    cv::Mat hsv = cv::Mat(cv::Size(320, 240), CV_8UC3);
    Mat imgLines = Mat::zeros(hsv.size(), CV_8UC3);
    ;

    /*HSV values for the YELLOW tennis ball*/;
    int iLowH = 19; // Hue
    int iHighH = 39;
    int iLowS = 109; // Saturation
    int iHighS = 255;
    int iLowV = 55; // value
    int iHighV = 255;

    //Create trackbars in "Control" window
    //This is for adjusting the HSV values to match the tennis ball properly
    cv::createTrackbar("LowH", "Thresholded Image", &iLowH, 179); //Hue (0 - 179)
    cv::createTrackbar("HighH", "Thresholded Image", &iHighH, 179);

    cv::createTrackbar("LowS", "Thresholded Image", &iLowS, 255); //Saturation (0 - 255)
    cv::createTrackbar("HighS", "Thresholded Image", &iHighS, 255);

    cv::createTrackbar("LowV", "Thresholded Image", &iLowV, 255); //Value (0 - 255)
    cv::createTrackbar("HighV", "Thresholded Image", &iHighV, 255);

    unsigned int i = 0; // index to track which frame we're at
    unsigned int oldi = 100; // last index

    /** Main loop. Exit when pressing ESC.*/
    while ((char) cv::waitKey(30) != 27) {
        /* Retrieve an image from the camera. */

        ALValue image = camProxy.getImageRemote(clientName);

        /** Access the image buffer (6th field) and assign it to the opencv image
         * container. */
        img.data = (uchar*) image[6].GetBinary();



        /** Tells to ALVideoDevice that it can give back the image buffer to the
         * driver. Optional after a getImageRemote but MANDATORY after a getImageLocal.*/
        camProxy.releaseImage(clientName);

        /*Here is where we start doing the ball detection*/

        /*blur frame and take average*/
        cv::GaussianBlur(img, run_ave, Size(5, 5), 0, 0);
        cv::accumulateWeighted(run_ave, weightedFrame, 0.80);
        cv::convertScaleAbs(weightedFrame, run_ave, 1.0, 0.0);

        /*convert BGR to HSV*/
        cvtColor(run_ave, hsv, CV_BGR2HSV);

        /*Threshold image for color detection*/
        Mat thresh;
        inRange(hsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), thresh); //Threshold the image

        /*morphological opening, removes small objects from the foreground*/
        erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
        dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));

        /*morphological closing, removes small holes from foreground*/
        dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
        erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));

        /*Hough transform*/
        GaussianBlur(thresh, thresh, Size(15, 15), 0, 0); // blur before tranform 
        vector<Vec3f> circles;
        HoughCircles(thresh, circles, CV_HOUGH_GRADIENT, 2, thresh.rows, 200, 20, 0, 0);
        
        /*draw circles detected by Hough transform*/
        for (size_t j = 0; j < circles.size(); j++) {
            Point center(cvRound(circles[j][0]), cvRound(circles[j][1]));
            int radius = cvRound(circles[j][2]);
            // circle center
            circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
            // circle outline
            circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
        }

        /*calculate moments of the thresholded image*/
        Moments mom = moments(thresh);
        double dM01 = mom.m01;
        double dM10 = mom.m10;
        double dA = mom.m00;

        /*If the area is greater than a thousand, we'll say the image contains an object to track*/
        if (dA > 1000) {

            /*calculate position of the ball*/
            traject[i].x = dM10 / dA;
            traject[i].y = dM01 / dA;

            /*make sure points are within bounds of the image*/
            if (traject[oldi].x >= 0 && traject[oldi].y >= 0 && traject[i].x >= 0 && traject[i].y >= 0) {
                //Draw a red line from the previous point to the current point
                line(imgLines, traject[i], traject[oldi], Scalar(0, 0, 255), 2);
            }

            /*increment indices*/
            oldi = i;
            i = (i + 1) % 100;           

        }

        /*add lines to original image*/
        img = img + imgLines;
        

        /** Display the iplImage on screen.*/
        cv::imshow("images", img);
//        cv::imshow("Averages", run_ave);
//        imshow("Thresholded Image", thresh); //show the thresholded image
    }

    /** Cleanup.*/
    camProxy.unsubscribe(clientName);
}

int main(int argc, char* argv[]) {

    const std::string robotIp("153.90.197.238");

    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    try {
        showImages(robotIp);
    } catch (const AL::ALError& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }

    return 0;
}

//} // extern "C"

