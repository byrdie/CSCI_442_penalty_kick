// Generated for ALVideoRecorder version 1.14

#ifndef ALVIDEORECORDERPROXYREMOTE_H_
#define ALVIDEORECORDERPROXYREMOTE_H_
#include <alremoteproxies/alvideorecorderproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module provides methods to record videos and store them on disk.</summary>
class ALVideoRecorderProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALVideoRecorderProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALVideoRecorder", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALVideoRecorderProxyPostHandlerRemote post;


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
    /// Returns current camera ID.
    /// </summary>
    /// <returns> Current camera ID. </returns>
    int getCameraID()
    {

        return callRemote<int >("getCameraID");
    }


    /// <summary>
    /// Returns current color space.
    /// </summary>
    /// <returns> Current color space. </returns>
    int getColorSpace()
    {

        return callRemote<int >("getColorSpace");
    }


    /// <summary>
    /// Returns current frame rate.
    /// </summary>
    /// <returns> Current frame rate. </returns>
    int getFrameRate()
    {

        return callRemote<int >("getFrameRate");
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
    /// Returns current resolution.
    /// </summary>
    /// <returns> Current resolution. </returns>
    int getResolution()
    {

        return callRemote<int >("getResolution");
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
    /// Returns current video format.
    /// </summary>
    /// <returns> Current video format. </returns>
    std::string getVideoFormat()
    {

        return callRemote<std::string >("getVideoFormat");
    }


    /// <summary>
    /// Are we currently recording a video
    /// </summary>
    /// <returns> True/False </returns>
    bool isRecording()
    {

        return callRemote<bool >("isRecording");
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
    /// Sets camera ID.
    /// </summary>
    /// <param name="cameraID"> ID of the camera to use. </param>
    void setCameraID(const int& cameraID)
    {

        callVoidRemote("setCameraID" , cameraID);
    }


    /// <summary>
    /// Sets color space.
    /// </summary>
    /// <param name="colorSpace"> New color space. </param>
    void setColorSpace(const int& colorSpace)
    {

        callVoidRemote("setColorSpace" , colorSpace);
    }


    /// <summary>
    /// Sets frame rate.
    /// </summary>
    /// <param name="frameRate"> New frame rate. </param>
    void setFrameRate(const float& frameRate)
    {

        callVoidRemote("setFrameRate" , frameRate);
    }


    /// <summary>
    /// Sets resolution.
    /// </summary>
    /// <param name="resolution"> New frame resolution. </param>
    void setResolution(const int& resolution)
    {

        callVoidRemote("setResolution" , resolution);
    }


    /// <summary>
    /// Sets video format.
    /// </summary>
    /// <param name="videoFormat"> New video format. </param>
    void setVideoFormat(const std::string& videoFormat)
    {

        callVoidRemote("setVideoFormat" , videoFormat);
    }


    /// <summary>
    /// Starts recording a video. Please note that only one record at a time can be made.
    /// </summary>
    /// <param name="folderPath"> Folder where the video is saved. </param>
    /// <param name="fileName"> Filename used to save the video. </param>
    void startRecording(const std::string& folderPath, const std::string& fileName)
    {

        callVoidRemote("startRecording" , folderPath, fileName);
    }


    /// <summary>
    /// Starts recording a video. Please note that only one record at a time can be made.
    /// </summary>
    /// <param name="folderPath"> Folder where the video is saved. </param>
    /// <param name="fileName"> Filename used to save the video. </param>
    /// <param name="overwrite"> If false and the filename already exists, an error is thrown. </param>
    void startRecording(const std::string& folderPath, const std::string& fileName, const bool& overwrite)
    {

        callVoidRemote("startRecording" , folderPath, fileName, overwrite);
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
    /// Stops a video record that was launched with startRecording(). The function returns the number of frames that were recorded, as well as the video absolute file name.
    /// </summary>
    /// <returns> Array of two elements [numRecordedFrames, recordAbsolutePath] </returns>
    AL::ALValue stopRecording()
    {

        return callRemote<AL::ALValue >("stopRecording");
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
#endif // ALVIDEORECORDERPROXY_H_
