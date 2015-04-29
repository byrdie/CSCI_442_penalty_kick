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

    motion.setStiffnesses("Body", 0.9);
    pose.goToPosture("Stand", 0.9);
    motion.setAngles("HeadPitch", 0.05, 0.9);
}

/*Use openCV to find the ball and move towards it*/
void move_to_ball() {

    /** Create an cv::Mat header to wrap into an opencv image.*/
    Mat img = Mat(cv::Size(320, 240), CV_8UC3);

    /*list to store last few points recorded*/
    list<Point> traject;

    double head_yaw_deg = 0.0;
    int count = 0;
    int lost_count = 0;
    int lost = 0;

    /** Main loop. Exit when pressing ESC.*/
    while ((char) cv::waitKey(30) != 27 || count < 100) {

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
        if (ball_loc.x != 0 && ball_loc.y != 0) {

            double head_norm_x = abs((ball_loc.y / (double) VER_RES) - 1.0);
            double head_norm_y = (1.0 - 2 * ball_loc.x / (double) HOR_RES);

            head_yaw_deg += 15.0 * head_norm_y;
            double head_yaw_rad = head_yaw_deg * 0.017453;
            motion.setAngles("HeadYaw", head_yaw_rad, 0.8);

            //            if (!motion.walkIsActive()) {
            if (head_yaw_deg > 4.0) {

                //                    motion.post.moveTo(0.0, 0.05, 0.0);
                motion.setWalkTargetVelocity(0.01, 0.7, 0.0, 1.0);

            } else if (head_yaw_deg < -4.0) {
                //                    motion.post.moveTo(0.0, -0.05, 0.0);
                motion.setWalkTargetVelocity(0.01, -0.7, 0.0, 1.0);
            } else {
                //                    motion.post.moveTo(0.1, 0.0, 0.0);
                motion.setWalkTargetVelocity(1.0, 0.0, 0.0, 1.0);

            }
            //            }


            //            std::cout << "X-coordinate " << ball_loc.x << std::endl;
            std::cout << "Y-velocity " << head_norm_y << std::endl;
            //            std::cout << "Angle = " << head_yaw_deg << std::endl;;

            lost = 0;


        } else {
            //            motion.setAngles("HeadYaw", 0.0, 0.8);
            if (lost_count < 3) {
                motion.setWalkTargetVelocity(1.0, 0.0, 0.0, 1.0);
            } else {
                break;
            }
            if (lost > 5) {
                lost_count++;
            }
            lost++;

        }


        count++;

        cv::imshow("images", img);


    }

    motion.stopMove();


}

void step_around_ball() {
    motion.moveTo(-0.02, -0.2, 0.0);
    motion.moveTo(0.23, 0.05, PI/12);
//    motion.moveTo(0.01, 0.25, 0.0);
    motion.setWalkTargetVelocity(0.0, 0.2, 0.0, 1.0);
    usleep(12000000);
    motion.moveTo(-0.4, 0.0, -PI/6);
    motion.moveTo(0.0, 0.2, PI/50);


}

void move_forward(){
    motion.moveTo(0.0, 0.1, 0.0);
    motion.moveTo(0.4, 0.0, 0.0);
    motion.moveTo(0.0, -0.3, 0.0);
}

void kick_ball_left() {
    AL::ALValue names;
    AL::ALValue times;
    AL::ALValue keys;
    AL::ALValue Tnames;
    AL::ALValue Ttimes;
    AL::ALValue Tkeys;

    names = "HeadPitch";
    times = AL::ALValue::array(1.16000, 2.68000, 3.20000, 4.24000, 5.12000, 6.12000);
    keys = AL::ALValue::array(0.04363, 0.26180, 0.17453, -0.27925, -0.26180, -0.24241);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "HeadYaw";
    times = AL::ALValue::array(1.16000, 2.68000, 3.20000, 4.24000, 5.12000, 6.12000);
    keys = AL::ALValue::array(0.00464, -0.00149, 0.00311, -0.04905, -0.03371, -0.02459);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RAnklePitch";
    times = AL::ALValue::array(1.04000, 1.76000, 2.56000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.03226, 0.01745, 0.01745, 0.03491, 0.03491, 0.11501);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RAnkleRoll";
    times = AL::ALValue::array(1.04000, 1.76000, 2.56000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(-0.33161, -0.36652, -0.36652, -0.36652, -0.34732, 0.08433);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RElbowRoll";
    times = AL::ALValue::array(1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000);
    keys = AL::ALValue::array(0.74096, 1.03396, 1.36990, 1.02015, 0.70722, 0.37732);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RElbowYaw";
    times = AL::ALValue::array(1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000);
    keys = AL::ALValue::array(-1.15353, -0.95411, -0.90809, -1.23023, -1.55697, -1.14441);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    //names="RHand"
    //times=AL::ALValue::array( 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000)
    //keys=AL::ALValue::array( 0.00317, 0.00328, 0.00329, 0.00317, 0.00325, 0.00187)

    names = "RHipPitch";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.23159, 0.10580, 0.12217, 0.08433, 0.09046, 0.19171, 0.21020);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RHipRoll";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.34366, 0.36820, 0.36820, 0.36513, 0.36667, 0.36513, -0.10129);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RHipYawPitch";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(-0.18097, -0.25307, -0.06285, -0.05058, -0.18711, -0.24386, -0.31903);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RKneePitch";
    times = AL::ALValue::array(1.04000, 1.76000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(-0.08727, -0.08727, -0.09235, -0.07973, -0.07973, -0.07819, -0.07666, -0.09208);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RShoulderPitch";
    times = AL::ALValue::array(1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000);
    keys = AL::ALValue::array(1.48649, 1.35917, 1.41746, 1.59847, 1.63835, 1.50021);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "RShoulderRoll";
    times = AL::ALValue::array(1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000);
    keys = AL::ALValue::array(-0.02305, -0.01998, -0.13197, -0.11816, -0.02305, -0.03524);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    //names="RWristYaw"
    //times=AL::ALValue::array( 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000)
    //keys=AL::ALValue::array( 0.24435, 0.23935, 0.22094, 0.20253, 0.19026, -0.12736)

    names = "LAnklePitch";
    times = AL::ALValue::array(1.04000, 1.32000, 1.76000, 2.56000, 2.84000, 3.36000, 3.68000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.08727, -0.08727, -0.59341, 0.12217, -0.05236, 0.24435, -0.12217, -0.64403, -0.21991, 0.11356);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LAnkleRoll";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(-0.40143, -0.10887, -0.13802, -0.00000, -0.18097, -0.34558, -0.05066);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LElbowRoll";
    times = AL::ALValue::array(1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000);
    keys = AL::ALValue::array(-0.64117, -1.15353, -1.38056, -1.36062, -0.96024, -0.45564);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LElbowYaw";
    times = AL::ALValue::array(1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000);
    keys = AL::ALValue::array(0.99714, 0.86368, 0.90970, 0.63205, 0.84834, 1.49714);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    //names="LHand"
    //times=AL::ALValue::array( 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000)
    //keys=AL::ALValue::array( 0.00129, 0.00136, 0.00132, 0.00128, 0.00133, 0.00391)

    names = "LHipPitch";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.16265, -0.39726, -1.11876, -1.11978, -0.78540, -0.29142, 0.21318);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LHipRoll";
    times = AL::ALValue::array(1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(0.47124, 0.54001, 0.32218, 0.12276, 0.36360, 0.41713, 0.05825);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LKneePitch";
    times = AL::ALValue::array(1.04000, 2.56000, 2.84000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000);
    keys = AL::ALValue::array(-0.08901, 1.97575, 1.97222, 1.23918, 0.24435, 1.53589, 0.62430, -0.07666);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LShoulderPitch";
    times = AL::ALValue::array(1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000);
    keys = AL::ALValue::array(1.52782, 1.46033, 1.47413, 1.24096, 1.51862, 1.54938);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);


    names = "LShoulderRoll";
    times = AL::ALValue::array(1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000);
    keys = AL::ALValue::array(0.12268, 0.04138, 0.14569, 0.13955, 0.14722, 0.03993);
    Tnames.arrayPush(names);
    Ttimes.arrayPush(times);
    Tkeys.arrayPush(keys);

    //names.push_back("LWristYaw")
    //times.push_back([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
    //keys.push_back([ -0.08727, -0.07359, -0.05058, -0.06285, 0.05680, 0.00149])
    motion.moveTo(0.0, -0.033, 0.0);
    pose.goToPosture("Stand", 0.9);
    motion.angleInterpolation(Tnames, Tkeys, Ttimes, true);

}

/*normalize and flip components, since x is forward in robot's frame*/
//void normalize_velocity(Point cam, double * norm) {
//    norm[0] = abs((cam.y / VER_RES) - 1.0);
//    //    norm.y = -1.0 * (-1.0 + (2 * cam.x / HOR_RES));
//    norm[1] = (cam.x / HOR_RES);
//
//    return;
//}

/* Once we're done with everything, go into crouch position and take off stiffness*/
void robot_cleanup() {

    camProxy.unsubscribe(clientName);

    pose.goToPosture("Crouch", 1.0);

    motion.setStiffnesses("Body", 0.1);

}
