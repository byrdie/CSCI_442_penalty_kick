// Generated for ALNavigation version 1.14

#ifndef ALNAVIGATIONPROXYREMOTE_H_
#define ALNAVIGATIONPROXYREMOTE_H_
#include <alremoteproxies/alnavigationproxyposthandlerremote.h>

namespace AL
{

/// <summary>Use ALNavigation module to make the robot go safely to the asked pose2D.</summary>
class ALNavigationProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALNavigationProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALNavigation", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALNavigationProxyPostHandlerRemote post;


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
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
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
    /// Makes the robot move at the given position.This is a blocking call.
    /// </summary>
    /// <param name="x"> The position along x axis [m]. </param>
    /// <param name="y"> The position along y axis [m]. </param>
    /// <param name="theta"> The angle around z axis [rad]. </param>
    /// <returns>  </returns>
    bool moveTo(const float& x, const float& y, const float& theta)
    {

        return callRemote<bool >("moveTo" , x, y, theta);
    }


    /// <summary>
    /// Makes the robot move at the given position.This is a blocking call.
    /// </summary>
    /// <param name="x"> The position along x axis [m]. </param>
    /// <param name="y"> The position along y axis [m]. </param>
    /// <param name="theta"> The angle around z axis [rad]. </param>
    /// <param name="moveConfig"> An ALValue with custom move configuration. </param>
    /// <returns>  </returns>
    bool moveTo(const float& x, const float& y, const float& theta, const AL::ALValue& moveConfig)
    {

        return callRemote<bool >("moveTo" , x, y, theta, moveConfig);
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
    /// Distance in meters fromwhich the robot should stop if there is an obstacle.
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setSecurityDistance(const float& arg1)
    {

        callVoidRemote("setSecurityDistance" , arg1);
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
#endif // ALNAVIGATIONPROXY_H_
