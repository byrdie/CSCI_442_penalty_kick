/**
 *
 * This example demonstrates how to get images from the robot remotely and how
 * to display them on your screen using opencv.
 *
 * Copyright Aldebaran Robotics
 */

// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#include <iostream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>

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

    /** Subscribe a client image requiring 320*240 and BGR colorspace.*/
    const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

    /** Create an cv::Mat header to wrap into an opencv image.*/
    cv::Mat img = cv::Mat(cv::Size(320, 240), CV_8UC3);

    /** Create a OpenCV window to display the images. */
    cv::namedWindow("images");

    /*create image buffers*/
    cv::Mat hsv = img.clone();

    /*HSV values for the YELLOW tennis ball*/
    int iLowH = 170; // Hue
    int iHighH = 179;
    int iLowS = 150; // Saturation
    int iHighS = 255;
    int iLowV = 60; // value
    int iHighV = 255;

    //Create trackbars in "Control" window
    cv::createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    cv::createTrackbar("HighH", "Control", &iHighH, 179);

    cv::createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cv::createTrackbar("HighS", "Control", &iHighS, 255);

    cv::createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cv::createTrackbar("HighV", "Control", &iHighV, 255);


    /** Main loop. Exit when pressing ESC.*/
    while ((char) cv::waitKey(30) != 27) {
        /** Retrieve an image from the camera.
         * The image is returned in the form of a container object, with the
         * following fields:
         * 0 = width
         * 1 = height
         * 2 = number of layers
         * 3 = colors space index (see alvisiondefinitions.h)
         * 4 = time stamp (seconds)
         * 5 = time stamp (micro seconds)
         * 6 = image buffer (size of width * height * number of layers)
         */
        ALValue img = camProxy.getImageRemote(clientName);

        /** Access the image buffer (6th field) and assign it to the opencv image
         * container. */
        //        img.data = (uchar*) img[6].GetBinary();
        img = (uchar*) img[6].GetBinary();


        /** Tells to ALVideoDevice that it can give back the image buffer to the
         * driver. Optional after a getImageRemote but MANDATORY after a getImageLocal.*/
        camProxy.releaseImage(clientName);

        /*Here is where we start doing the ball detection*/

        /*convert BGR to HSV*/
//        cv::cvtColor(img, hsv, CV_BGR2HSV);
        //
        //        /*Threshold image for color detection*/
        //        Mat imgThresholded;
        //        inRange(hsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
        //
        //        /** Display the iplImage on screen.*/
        cv::imshow("images", img);
        //        imshow("Thresholded Image", imgThresholded); //show the thresholded image
    }

    /** Cleanup.*/
    camProxy.unsubscribe(clientName);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage 'getimages robotIp'" << std::endl;
        return 1;
    }

    const std::string robotIp(argv[1]);

    try {
        showImages(robotIp);
    } catch (const AL::ALError& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }

    return 0;
}

