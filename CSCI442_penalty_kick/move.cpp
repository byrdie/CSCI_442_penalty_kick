#include "move.h"

ALVideoDeviceProxy camProxy(robotIp, 9559);
AL::ALMotionProxy motion(robotIp, 9559);
AL::ALRobotPostureProxy pose(robotIp, 9559);
AL::ALNavigationProxy navigate(robotIp, 9559);

/** Subscribe a client image requiring 320*240 and BGR colorspace.*/
const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

/* Get robot ready for action by stiffening the joints and standing him up */
void robot_init() {
    /** Create a OpenCV window to display the images. */
    cv::namedWindow("images", CV_WINDOW_KEEPRATIO);

    motion.setStiffnesses("Body", 1.0);
    pose.goToPosture("Stand", 0.9);
}

/*Use openCV to find the ball and move towards it*/
void move_to_ball() {

    /** Create an cv::Mat header to wrap into an opencv image.*/
    Mat img = Mat(cv::Size(320, 240), CV_8UC3);

    /*list to store last few points recorded*/
    list<Point> traject;

    double head_yaw_deg = 0.0;

    /** Main loop. Exit when pressing ESC.*/
    while ((char) cv::waitKey(30) != 27) {

        /* Retrieve an image from the camera. */
        ALValue image = camProxy.getImageRemote(clientName);
        camProxy.setParam(18, 1); // use chin camera

        /** Access the image buffer (6th field) and assign it to the opencv image container. */
        img.data = (uchar*) image[6].GetBinary();

        /** Tells to ALVideoDevice that it can give back the image buffer to the
         * driver. Optional after a getImageRemote but MANDATORY after a getImageLocal.*/
        camProxy.releaseImage(clientName);

        /*find the location of the ball in image space using openCV*/
        Point ball_loc = find_ball(img);
        Point vel = normalize_velocity(ball_loc);
        if (ball_loc.x != 0 && ball_loc.y != 0) {

            head_yaw_deg = head_yaw_deg + vel.y;
            double head_yaw_rad = head_yaw_deg * 0.017453;
            //            if (abs(vel.y) > 0.1) {
            //                motion.setWalkTargetVelocity(0.0, vel.y, 0.0, 1.0);
            motion.setAngles("HeadYaw", head_yaw_rad, 0.5);
            //            } 
            //            else {
            //                motion.setWalkTargetVelocity(vel.x, vel.y, 0.0, 1.0);
            //            }

        } else {
            motion.setWalkTargetVelocity(0.0, 0.0, 0.0, 1.0);
        }

        std::cout << "got here!" << std::endl;


        cv::imshow("images", img);


    }

    motion.stopMove();


}

/*normalize and flip components, since x is forward in robot's frame*/
Point normalize_velocity(Point cam) {
    Point norm;
    norm.x = abs((cam.y / VER_RES) - 1.0);
    norm.y = -1 * (2 * cam.x / HOR_RES);
    return norm;
}

/* Once we're done with everything, go into crouch position and take off stiffness*/
void robot_cleanup() {

    camProxy.unsubscribe(clientName);

    pose.goToPosture("Crouch", 1.0);

    motion.setStiffnesses("Body", 0.0);

}