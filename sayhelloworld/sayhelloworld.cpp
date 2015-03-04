
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/alledsproxy.h>

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: say NAO_IP" << std::endl;
    exit(2);
  }
  /** The desired phrase to be said. */
  //const std::string phraseToSay = "Hello world";
  try
  {
    /** Create an ALLedsProxy for leds
    * Arguments for the constructor are:
    *  - IP of the robot
    *  - port on which NAOqi is listening. Default is 9559
    */

    AL::ALLedsProxy leds(argv[1], 9559);

    std::string right  = "RightFaceLedsGreen";
    std::string left = "LeftFaceLedsGreen";
    std::string both = "FaceLeds";
	int x = 0;
	for(x = 0; x<4; x++) {
		if(x == 0) { //ball moving to right
			leds.on(right);
			leds.off(left);
			sleep(2);
		}
		else if(x == 1) { //ball moving to left
			leds.on(left);
			leds.off(right);
			sleep(2);
		}
		else if(x == 2) { //ball coming to center
			leds.on(both);
			sleep(2);
		}
		else {
			leds.off(both);
			sleep(2);
		}
	}
/*
    leds.off(right);
    leds.off(left);
    //leds.on(right);
    //leds.on(left);
    leds.on(both);

    float duration = 3.0f;
    //leds.rasta(duration);
*/
    //rleds.rasta(duration);
  }

  catch (const AL::ALError& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }


  exit(0);
}
