
/* 
 * File:   main.cpp
 * Author: Roy Smart, Zach Fisher
 *
 * Created on March 4, 2015, 6:29 AM
 */

#include "main.h"



/** Create an cv::Mat header to wrap into an opencv image.*/
Mat img = Mat(cv::Size(320, 240), CV_8UC3);

int main(int argc, char* argv[]) {

    std::cout << "OpenCV version: " << CV_VERSION << std::endl;


    try {
        //        ball_track(robotIp);





    } catch (const AL::ALError& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }
    AL::ALMotionProxy motion(robotIp, 9559);
    AL::ALRobotPostureProxy pose(robotIp, 9559);

    //    motion.setStiffnesses("Body", 0.9);
    pose.goToPosture("Stand", 1.0);
    
    motion.moveInit();
    
    motion.move(1.0, 0.0, 0.0);
    
    sleep(4);
    
    motion.stopMove();
    
    pose.goToPosture("Crouch", 1.0);
    
    motion.setStiffnesses("Body", 0.0);

    return 0;
}

/**
 * \brief Shows images retrieved from the robot.
 *
 * \param robotIp the IP adress of the robot
 */
void ball_track(const std::string& robotIp) {
    /** Create a proxy to ALVideoDevice on the robot.*/
    ALVideoDeviceProxy camProxy(robotIp, 9559);

    /*Create proxy for controlling LEDs*/
    AL::ALLedsProxy leds(robotIp, 9559);
    std::string right = "RightFaceLedsGreen";
    std::string left = "LeftFaceLedsGreen";
    std::string both = "FaceLeds";

    /** Subscribe a client image requiring 320*240 and BGR colorspace.*/
    const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

    /** Create a OpenCV window to display the images. */
    //    cv::namedWindow("Thresholded Image", CV_WINDOW_KEEPRATIO);
    cv::namedWindow("images", CV_WINDOW_KEEPRATIO);
    //    cv::namedWindow("Averages", CV_WINDOW_KEEPRATIO);

    /*create vector of points to store trajectory of ball, only store last 100 points*/

    const int max_points = 20;
    std::list<Point> traject; // final decision of ball location

    /*create image buffers*/

    Mat imgLines = Mat::zeros(img.size(), CV_8UC3);


    //Create trackbars in "Control" window
    //This is for adjusting the HSV values to match the tennis ball properly
    //    cv::createTrackbar("LowH", "Thresholded Image", &iLowH, 179); //Hue (0 - 179)
    //    cv::createTrackbar("HighH", "Thresholded Image", &iHighH, 179);
    //
    //    cv::createTrackbar("LowS", "Thresholded Image", &iLowS, 255); //Saturation (0 - 255)
    //    cv::createTrackbar("HighS", "Thresholded Image", &iHighS, 255);
    //
    //    cv::createTrackbar("LowV", "Thresholded Image", &iLowV, 255); //Value (0 - 255)
    //    cv::createTrackbar("HighV", "Thresholded Image", &iHighV, 255);

    unsigned int index = 0; // index to track which frame we're at

    leds.off(both); // turn off leds in between sessions

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

        Point next_traject = find_ball(img);
        if (next_traject.x != 0 && next_traject.y != 0) {

            /*put next point into list of points*/
            traject.push_back(next_traject);

            /*If there are more points in traject than the max size, delete the first item*/
            if (traject.size() > max_points) {
                traject.pop_front();
            }
        }

        /*draw the trjectory of the ball*/
        Mat imgLines = Mat::zeros(img.size(), CV_8UC3); // allocate new memory
        std::list<Point>::const_iterator iterate;
        for (iterate = traject.begin(); iterate != traject.end(); ++iterate) {

            /*skip the first point, because we need two points to make a line*/
            if (iterate != traject.begin()) {
                Point this_point = *iterate;
                Point last_point = *(--iterate);
                ++iterate; // hack this together (infinite loop))
                line(imgLines, this_point, last_point, Scalar(0, 0, 255), 2);
            }
        }

        /*find the average direction*/
        Point first_point = traject.front(); //first point in current trajctory
        Point final_point = traject.back();
        double sumX = final_point.x - first_point.x;
        double sumY = final_point.y - first_point.y;
        double distance = sqrt(sumX * sumX + sumY * sumY);

        /*draw average direction in blue*/
        line(imgLines, first_point, final_point, Scalar(255, 0, 0), 2);

        std::cout << "sumX is " << sumX << "    ";
        std::cout << "sumY is " << sumY << "    ";

        /*use the average to find the angle theta at which the ball is moving*/
        double theta = 450.0;
        if (sumX != 0) {
            theta = atan(sumY / sumX) * 180 / 3.1415; // find angle of trajectory and convert to degrees
        }

        std::cout << "Theta is " << theta << std::endl;

        /*direction decision*/
        if (distance > 15) {
            if (sumX > 0) { // Quadrants I and IV of unit circle, ball is going left or straight
                if (theta > -90 && theta < 45.0) { //moving left
                    leds.off(both);
                    leds.on(right);
                } else if (theta >= 45.0 && theta < 90.0) { //moving straight
                    leds.on(both);
                } else {
                    std::cout << "wtf?" << std::endl;
                }

            } else { // quandrant II and III, ball is moving right or straight
                if (theta < 90 && theta > -45.0) { //moving right 
                    leds.off(both);
                    leds.on(left);
                } else if (theta <= 45.0 && theta > -90.0) { //moving straight
                    leds.on(both);
                } else {
                    std::cout << "wtf?" << std::endl;
                }
            }
        } else {
            leds.off(both);
        }


        /*add decay factor for keeping points*/
        if (index % 2 == 0 && !traject.empty()) {
            traject.pop_front();
        }
        index++; // increment index

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

Point find_ball(Mat img) {

    /*allocate image buffers*/
    cv::Mat hsv = cv::Mat(cv::Size(320, 240), CV_8UC3);
    cv::Mat run_ave = cv::Mat(img.size(), CV_8UC3);
    cv::Mat weightedFrame = cv::Mat(img.size(), CV_32FC3);

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
    Point hough;
    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // circle center
        circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
        // circle outline
        circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);

        /*select the first circle as the thing we want: the ball*/
        if (i == 0) {
            hough = center; // set the coordinate in the center as the location of the ball
        }
    }

    /*calculate moments of the thresholded image*/
    Moments mom = moments(thresh);
    double dM01 = mom.m01;
    double dM10 = mom.m10;
    double dA = mom.m00;

    /*If the area is greater than a thousand, we'll say the image contains an object to track*/
    Point com;
    if (dA > 1000) {

        /*calculate position of the ball*/
        com.x = dM10 / dA;
        com.y = dM01 / dA;
    } else {
        //            continue;
    }

    /*make sure points are within bounds of the image*/
    Point next_traject = Point(0, 0);
    if (com.x > 0 && com.y > 0 && hough.x > 0 && hough.y > 0) {

        /*calculate the distance between point reported by houghs and center of mass*/
        int dX = hough.x - com.x;
        int dY = hough.y - com.y;
        double dist_squared = dX * dX + dY * dY;

        if (dist_squared < 20) { // 20 is the threshold value for how much disagreement there can be between houghs and center of mass

            /*If the two are close, set the final trajectory as the average between the two*/
            next_traject.x = com.x + dX;
            next_traject.y = com.y + dY;

        } else {
            std::cout << "Houghs and COM disagreement!" << std::endl;
            //                continue;
        }

    } else {
        //            std::cout << "Points equal to zero!" << std::endl;
        //            continue;
    }

    return next_traject;
}
