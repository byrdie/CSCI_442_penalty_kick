// Generated for ALPhotoCapture version 1.14

#ifndef ALPHOTOCAPTUREPROXYREMOTE_H_
#define ALPHOTOCAPTUREPROXYREMOTE_H_
#include <alremoteproxies/alphotocaptureproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module provides methods to take pictures and store them on disk.</summary>
class ALPhotoCaptureProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALPhotoCaptureProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALPhotoCapture", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALPhotoCaptureProxyPostHandlerRemote post;


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
    /// Returns current delay between captures.
    /// </summary>
    /// <returns> Current delay (in ms) between two pictures. </returns>
    int getCaptureInterval()
    {

        return callRemote<int >("getCaptureInterval");
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
    /// Returns current picture format.
    /// </summary>
    /// <returns> Current picture format. </returns>
    std::string getPictureFormat()
    {

        return callRemote<std::string >("getPictureFormat");
    }


    /// <summary>
    /// Returns current resolution.
    /// </summary>
    /// <returns> Current frame resolution. </returns>
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
    /// Sets delay between two captures.
    /// </summary>
    /// <param name="captureInterval"> New delay (in ms) between two pictures. </param>
    void setCaptureInterval(const int& captureInterval)
    {

        callVoidRemote("setCaptureInterval" , captureInterval);
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
    /// Sets picture extension.
    /// </summary>
    /// <param name="pictureFormat"> New extension used to save pictures. </param>
    void setPictureFormat(const std::string& pictureFormat)
    {

        callVoidRemote("setPictureFormat" , pictureFormat);
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
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Takes one picture.
    /// </summary>
    /// <param name="folderPath"> Folder where the picture is saved. </param>
    /// <param name="fileName"> Filename used to save the picture. </param>
    /// <returns> Full file name of the picture saved on the disk: [filename] </returns>
    AL::ALValue takePicture(const std::string& folderPath, const std::string& fileName)
    {

        return callRemote<AL::ALValue >("takePicture" , folderPath, fileName);
    }


    /// <summary>
    /// Takes one picture.
    /// </summary>
    /// <param name="folderPath"> Folder where the picture is saved. </param>
    /// <param name="fileName"> Filename used to save the picture. </param>
    /// <param name="overwrite"> If false and the filename already exists, an error is thrown. </param>
    /// <returns> Full file name of the picture saved on the disk: [filename] </returns>
    AL::ALValue takePicture(const std::string& folderPath, const std::string& fileName, const bool& overwrite)
    {

        return callRemote<AL::ALValue >("takePicture" , folderPath, fileName, overwrite);
    }


    /// <summary>
    /// Takes several pictures as quickly as possible
    /// </summary>
    /// <param name="numberOfPictures"> Number of pictures to take </param>
    /// <param name="folderPath"> Folder where the pictures are saved. </param>
    /// <param name="fileName"> Filename used to save the pictures. </param>
    /// <returns> List of all saved files: [[filename1, filename2...]] </returns>
    AL::ALValue takePictures(const int& numberOfPictures, const std::string& folderPath, const std::string& fileName)
    {

        return callRemote<AL::ALValue >("takePictures" , numberOfPictures, folderPath, fileName);
    }


    /// <summary>
    /// Takes several pictures as quickly as possible
    /// </summary>
    /// <param name="numberOfPictures"> Number of pictures to take </param>
    /// <param name="folderPath"> Folder where the pictures are saved. </param>
    /// <param name="fileName"> Filename used to save the pictures. </param>
    /// <param name="overwrite"> If false and the filename already exists, an error is thrown. </param>
    /// <returns> List of all saved files: [[filename1, filename2...]] </returns>
    AL::ALValue takePictures(const int& numberOfPictures, const std::string& folderPath, const std::string& fileName, const bool& overwrite)
    {

        return callRemote<AL::ALValue >("takePictures" , numberOfPictures, folderPath, fileName, overwrite);
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
#endif // ALPHOTOCAPTUREPROXY_H_
