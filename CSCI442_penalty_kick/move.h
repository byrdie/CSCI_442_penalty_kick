/* 
 * File:   move.h
 * Author: byrdie
 *
 * Created on March 12, 2015, 2:31 PM
 */

#ifndef MOVE_H
#define	MOVE_H

#include "main.h"

/*Allocate global proxies*/
extern AL::ALVideoDeviceProxy camProxy;
extern AL::ALMotionProxy motion;
extern AL::ALRobotPostureProxy pose;

extern const std::string clientName;

void robot_init();
void move_to_ball();
void robot_cleanup();

#endif	/* MOVE_H */

