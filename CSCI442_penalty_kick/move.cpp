#include "move.h"

ALVideoDeviceProxy camProxy(robotIp, 9559);
AL::ALMotionProxy motion(robotIp, 9559);
AL::ALRobotPostureProxy pose(robotIp, 9559);

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
    
    /** Main loop. Exit when pressing ESC.*/
    while ((char) cv::waitKey(30) != 27) {

        /* Retrieve an image from the camera. */
        ALValue image = camProxy.getImageRemote(clientName);

        /** Access the image buffer (6th field) and assign it to the opencv image container. */
        img.data = (uchar*) image[6].GetBinary();

        /** Tells to ALVideoDevice that it can give back the image buffer to the
         * driver. Optional after a getImageRemote but MANDATORY after a getImageLocal.*/
        camProxy.releaseImage(clientName);
        
        /*find the location of the ball using openCV*/
        Point ball_loc = find_ball(img);
        
        if(!motion.moveIsActive()){
            motion.moveTo(ball_loc.x, ball_loc.y, 0);
        }
        
        cv::imshow("images", img);
        
        
    }

    motion.moveInit();

    motion.move(1.0, 0.0, 0.0);

    sleep(4);

    motion.stopMove();


}

/* Once we're done with everything, go into crouch position and take off stiffness*/
void robot_cleanup() {

    pose.goToPosture("Crouch", 1.0);

    motion.setStiffnesses("Body", 0.0);

}