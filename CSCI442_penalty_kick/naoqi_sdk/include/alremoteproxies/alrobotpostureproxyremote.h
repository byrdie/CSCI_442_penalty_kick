// Generated for ALRobotPosture version 1.14

#ifndef ALROBOTPOSTUREPROXYREMOTE_H_
#define ALROBOTPOSTUREPROXYREMOTE_H_
#include <alremoteproxies/alrobotpostureproxyposthandlerremote.h>

namespace AL
{

/// <summary>Use ALRobotPosture module to make the robot go tothe asked posture.</summary>
class ALRobotPostureProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALRobotPostureProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALRobotPosture", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALRobotPostureProxyPostHandlerRemote post;


    /// <summary>
    /// Set the angle of the joints of the  robot to the choosen posture.
    /// </summary>
    /// <param name="postureName"> Name of the desired posture. Use getPostureList to get the list of posture name available. </param>
    /// <param name="maxSpeedFraction"> A fraction. </param>
    /// <returns> Returns if the posture was reached or not. </returns>
    bool applyPosture(const std::string& postureName, const float& maxSpeedFraction)
    {

        return callRemote<bool >("applyPosture" , postureName, maxSpeedFraction);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Returns the posture family for example Standing, LyingBelly,...
    /// </summary>
    /// <returns> Returns the posture family, e.g. Standing. </returns>
    std::string getPostureFamily()
    {

        return callRemote<std::string >("getPostureFamily");
    }


    /// <summary>
    /// Get the list of posture family names available.
    /// </summary>
    /// <returns>  </returns>
    std::vector<std::string> getPostureFamilyList()
    {

        return callRemote<std::vector<std::string> >("getPostureFamilyList");
    }


    /// <summary>
    /// Get the list of posture names available.
    /// </summary>
    /// <returns>  </returns>
    std::vector<std::string> getPostureList()
    {

        return callRemote<std::vector<std::string> >("getPostureList");
    }


    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Make the robot go to the choosenposture.
    /// </summary>
    /// <param name="postureName"> Name of the desired posture. Use getPostureList to get the list of posture name available. </param>
    /// <param name="maxSpeedFraction"> A fraction. </param>
    /// <returns> Returns if the posture was reached or not. </returns>
    bool goToPosture(const std::string& postureName, const float& maxSpeedFraction)
    {

        return callRemote<bool >("goToPosture" , postureName, maxSpeedFraction);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Set maximum of tries on goToPosture fail.
    /// </summary>
    /// <param name="pMaxTryNumber"> Number of retry if goToPosture fail. </param>
    void setMaxTryNumber(const int& pMaxTryNumber)
    {

        callVoidRemote("setMaxTryNumber" , pMaxTryNumber);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Stop the posture move.
    /// </summary>
    void stopMove()
    {

        callVoidRemote("stopMove");
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALROBOTPOSTUREPROXY_H_
