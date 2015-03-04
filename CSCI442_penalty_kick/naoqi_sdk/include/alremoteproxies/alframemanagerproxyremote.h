// Generated for ALFrameManager version 1.14

#ifndef ALFRAMEMANAGERPROXYREMOTE_H_
#define ALFRAMEMANAGERPROXYREMOTE_H_
#include <alremoteproxies/alframemanagerproxyposthandlerremote.h>

namespace AL
{

/// <summary>Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.</summary>
class ALFrameManagerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALFrameManagerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALFrameManager", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALFrameManagerProxyPostHandlerRemote post;


    /// <summary>
    /// Stop playing any behavior in FrameManager, and delete all of them.
    /// </summary>
    void cleanBehaviors()
    {

        callVoidRemote("cleanBehaviors");
    }


    /// <summary>
    /// It will play a behavior and block until the behavior is finished. Note that it can block forever if the behavior output is never called.
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    void completeBehavior(const std::string& id)
    {

        callVoidRemote("completeBehavior" , id);
    }


    /// <summary>
    /// Creates and play completely a timeline
    /// </summary>
    /// <param name="xmlFile"> The choregraphe project (in plain text for the moment). </param>
    /// <returns> return a unique identifier for the created box that contains the timeline. You must call deleteBehavior on it at some point. DEPRECATED since 1.14 </returns>
    std::string createAndPlayTimeline(const std::string& xmlFile)
    {

        return callRemote<std::string >("createAndPlayTimeline" , xmlFile);
    }


    /// <summary>
    /// Deletes a behavior (meaning a box). Stop the whole behavior contained in this box first.
    /// </summary>
    /// <param name="id"> The id of the box to delete. </param>
    void deleteBehavior(const std::string& id)
    {

        callVoidRemote("deleteBehavior" , id);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Exit the reading of a timeline contained in a given box
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    void exitBehavior(const std::string& id)
    {

        callVoidRemote("exitBehavior" , id);
    }


    /// <summary>
    /// Returns a playing behavior absolute path.
    /// </summary>
    /// <param name="id"> The id of the behavior. </param>
    /// <returns> Returns the absolute path of given behavior. </returns>
    std::string getBehaviorPath(const std::string& id)
    {

        return callRemote<std::string >("getBehaviorPath" , id);
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
    /// Returns in seconds, the duration of a given movement stored in a box. Returns 0 if the behavior has no motion layers.  DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> Returns the time in seconds. </returns>
    float getMotionLength(const std::string& id)
    {

        return callRemote<float >("getMotionLength" , id);
    }


    /// <summary>
    /// Gets the FPS of a given timeline. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the timeline. </param>
    /// <returns> Returns the timeline's FPS. </returns>
    int getTimelineFps(const std::string& id)
    {

        return callRemote<int >("getTimelineFps" , id);
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
    /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    void gotoAndPlay(const std::string& id, const std::string& frame)
    {

        callVoidRemote("gotoAndPlay" , id, frame);
    }


    /// <summary>
    /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    void gotoAndPlay(const std::string& id, const int& frame)
    {

        callVoidRemote("gotoAndPlay" , id, frame);
    }


    /// <summary>
    /// Goes to a certain frame and pause. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    void gotoAndStop(const std::string& id, const std::string& frame)
    {

        callVoidRemote("gotoAndStop" , id, frame);
    }


    /// <summary>
    /// Goes to a certain frame and pause. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    void gotoAndStop(const std::string& id, const int& frame)
    {

        callVoidRemote("gotoAndStop" , id, frame);
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
    /// Creates a new behavior, from a box found in an xml file. Note that you have to give the xml file contents, so this method is not very user friendly. You have to open the file, and send the string that matches the file contents if you are working from a file. You probably want to use newBehaviorFromFile instead. DEPRECATED since 1.14
    /// </summary>
    /// <param name="path"> The path to reach the box to instantiate in the project (\"\" if root). </param>
    /// <param name="xmlFile"> The choregraphe project (in plain text for the moment). </param>
    /// <returns> return a unique identifier for the created box. </returns>
    std::string newBehavior(const std::string& path, const std::string& xmlFile)
    {

        return callRemote<std::string >("newBehavior" , path, xmlFile);
    }


    /// <summary>
    /// Creates a new behavior, from the current Choregraphe behavior 0(uploaded to /tmp/currentChoregrapheBehavior/behavior.xar). DEPRECATED since 1.14
    /// </summary>
    /// <returns> return a unique identifier for the created behavior </returns>
    std::string newBehaviorFromChoregraphe()
    {

        return callRemote<std::string >("newBehaviorFromChoregraphe");
    }


    /// <summary>
    /// Creates a new behavior, from a box found in an xml file stored in the robot.
    /// </summary>
    /// <param name="xmlFilePath"> Path to Xml file, ex : \"/home/youhou/mybehavior.xar\". </param>
    /// <param name="behName">  </param>
    /// <returns> return a unique identifier for the created box, that can be used by playBehavior </returns>
    std::string newBehaviorFromFile(const std::string& xmlFilePath, const std::string& behName)
    {

        return callRemote<std::string >("newBehaviorFromFile" , xmlFilePath, behName);
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
    /// Starts a behavior
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    void playBehavior(const std::string& id)
    {

        callVoidRemote("playBehavior" , id);
    }


    /// <summary>
    /// Starts playing a timeline contained in a given box. If the box is a flow diagram, it will look for the first onStart input of type Bang, and stimulate it ! DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    void playTimeline(const std::string& id)
    {

        callVoidRemote("playTimeline" , id);
    }


    /// <summary>
    /// enable the deprecation warning
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setDeprecationWarningEnabled(const bool& arg1)
    {

        callVoidRemote("setDeprecationWarningEnabled" , arg1);
    }


    /// <summary>
    /// Sets the FPS of a given timeline. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the timeline. </param>
    /// <param name="fps"> The FPS to set. </param>
    void setTimelineFps(const std::string& id, const int& fps)
    {

        callVoidRemote("setTimelineFps" , id, fps);
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
    /// Stops playing a timeline contained in a given box, at the current frame. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    void stopTimeline(const std::string& id)
    {

        callVoidRemote("stopTimeline" , id);
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
#endif // ALFRAMEMANAGERPROXY_H_
