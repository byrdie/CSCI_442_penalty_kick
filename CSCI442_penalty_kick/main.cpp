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
#include <math.h>

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
#include <vector>


using namespace AL;
using namespace cv;

/**
 * \brief Shows images retrieved from the robot.
 *
 * \param robotIp the IP adress of the robot
 */
void showImages(const std::string& robotIp) {
    /** Create a proxy to ALVideoDevice on the robot.*/
    ALVideoDeviceProxy camProxy(robotIp, 9559);

    /*Create proxy for controlling LEDs*/
    AL::ALLedsProxy leds(robotIp, 9559);
    std::string right = "RightFaceLedsGreen";
    std::string left = "LeftFaceLedsGreen";
    std::string both = "FaceLeds";

    /** Subscribe a client image requiring 320*240 and BGR colorspace.*/
    const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

    /** Create an cv::Mat header to wrap into an opencv image.*/
    cv::Mat img = cv::Mat(cv::Size(320, 240), CV_8UC3);
    cv::Mat run_ave = cv::Mat(img.size(), CV_8UC3);
    cv::Mat weightedFrame = cv::Mat(img.size(), CV_32FC3);
    Mat imgLines = Mat::zeros(img.size(), CV_8UC3);
    cv::Mat hsv = cv::Mat(cv::Size(320, 240), CV_8UC3);

    /** Create a OpenCV window to display the images. */
    cv::namedWindow("images", CV_WINDOW_KEEPRATIO);
    cv::namedWindow("Thresholded Image", CV_WINDOW_KEEPRATIO);
    //    cv::namedWindow("Averages", CV_WINDOW_KEEPRATIO);

    /*create vector of points to store trajectory of ball, only store last 100 points*/
    unsigned int vec_sz = 20;
    vector<Point> com(vec_sz); // ball location according to center of mass
    vector<Point> hough(vec_sz); //ball location according to houghs transform
    vector<Point> traject(vec_sz); // final decision of ball location

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

    unsigned int index = 0; // index to track which frame we're at
    unsigned int oldi = vec_sz; // index to track which frame we're at

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
        cv::accumulateWeighted(run_ave, weightedFrame, 0.90);
        cv::convertScaleAbs(weightedFrame, run_ave, 1.0, 0.0);

        /*convert BGR to HSV*/
        cvtColor(run_ave, hsv, CV_BGR2HSV);

        /*Threshold image for color detection*/
        Mat thresh;
        inRange(hsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), thresh); //Threshold the image

        /*morphological opening, removes small objects from the foreground*/
        erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(7, 7)));
        dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(7, 7)));

        /*morphological closing, removes small holes from foreground*/
        dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
        erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));

        /*Hough transform*/
        GaussianBlur(thresh, thresh, Size(15, 15), 0, 0); // blur before tranform 
        vector<Vec3f> circles;
        HoughCircles(thresh, circles, CV_HOUGH_GRADIENT, 2, thresh.rows, 200, 20, 0, 0);

        /*draw circles detected by Hough transform*/
        for (size_t i = 0; i < circles.size(); i++) {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // circle center
            circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
            // circle outline
            circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);

            /*select the first circle as the thing we want: the ball*/
            if (i == 0) {
                hough[index] = center; // set the coordinate in the center as the location of the ball
            }
        }

        /*calculate moments of the thresholded image*/
        Moments mom = moments(thresh);
        double dM01 = mom.m01;
        double dM10 = mom.m10;
        double dA = mom.m00;

        /*If the area is greater than a thousand, we'll say the image contains an object to track*/
        if (dA > 1000) {

            /*calculate position of the ball*/
            com[index].x = dM10 / dA;
            com[index].y = dM01 / dA;
        }

        /*make sure points are within bounds of the image*/
        if (com[index].x > 0 || com[index].y > 0 || hough[index].x > 0 || hough[index].y > 0) {

            /*calculate the distance between point reported by houghs and center of mass*/
            int dX = hough[index].x - com[index].x;
            int dY = hough[index].y - com[index].y;
            double dist_squared = dX * dX + dY * dY;
            std::cout << "Distance squared is" << dist_squared << std::endl;

            if (dist_squared < 30) { // 10 is the threshold value for how much disagreement there can be between houghs and center of mass

                /*If the two are close, set the final trajectory as the average between the two*/
                traject[index].x = com[index].x + dX;
                traject[index].y = com[index].y + dY;

                //Draw a red line from the previous point to the current point
                line(imgLines, traject[index], traject[oldi], Scalar(255, 0, 0), 2);

                /*increment indices only if we have found a good ball location*/
                oldi = index;
                index = (index + 1) % (traject.size() - 1);

            } else {
                std::cout << "Houghs and COM disagreement!" << std::endl;
            }

        } else {
            std::cout << "Points equal to zero!" << std::endl;
        }

        /*allocate memory for trajectory line*/
        Mat trajectLines = Mat::zeros(img.size(), CV_8UC3);

        /*add all points in the traject vector to find average direction*/
        Point first_point = traject[index];
        Point last_point = first_point;
        for (int i = traject.size(); i > 0; i--) {
            int j = (i + index) % traject.size();
            if (traject[j].x > 0 && traject[j].y > 0) {
                last_point = traject[j];
            }
        }

        /*draw a line between points*/
        line(trajectLines, first_point, last_point, Scalar(0, 0, 255), 2);

        /*use the average to find the angle theta at which the ball is moving*/
        double theta = 400.0;
        int difX = first_point.x - last_point.x;
        int difY = first_point.y - last_point.y;
        if (difX > 0 && difY > 0) {
            theta = atan(difY / difX) * 180 / 3.1415;
        } else {
            std::cout << "No change" << std::endl;
        }


        /*direction decision*/
        if (theta < 45.0) { //Right
            leds.on(right);
            leds.off(left);
        } else if (theta >= 45.0 && theta < 135.0) { // towards
            leds.on(both);
        } else if (theta >= 135.0 && theta < 270.0) { //left
            leds.on(left);
            leds.off(right);
        } else if (theta >= 270.0 && theta < 360.0) { //right again
            leds.on(right);
            leds.off(left);
        } else {
            leds.off(both);
            std::cout << "wtf?" << std::endl;
        }

        /*add lines to original image*/
        img = img + imgLines;
        img = img + trajectLines;




        /** Display the iplImage on screen.*/
        cv::imshow("images", img);
        //        cv::imshow("Averages", run_ave);
        imshow("Thresholded Image", thresh); //show the thresholded image
    }

    /** Cleanup.*/
    camProxy.unsubscribe(clientName);
}

int main(int argc, char* argv[]) {

    const std::string robotIp("153.90.197.185");

    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    try {
        showImages(robotIp);
    } catch (const AL::ALError& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }

    return 0;
}

