// Generated for ALVideoDevice version 1.14

#ifndef ALVIDEODEVICEPROXYREMOTE_H_
#define ALVIDEODEVICEPROXYREMOTE_H_
#include <alremoteproxies/alvideodeviceproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALVideoDevice, formerly called Video Input systemis architectured in order to provide every module related to vision, called vision module, a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).</summary>
class ALVideoDeviceProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALVideoDeviceProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALVideoDevice", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALVideoDeviceProxyPostHandlerRemote post;


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    int getActiveCamera(const std::string& name)
    {

        return callRemote<int >("getActiveCamera" , name);
    }


    /// <summary>
    /// Tells if top camera is active
    /// </summary>
    /// <returns> 0: top camera - 1: bottom camera </returns>
    int getActiveCamera()
    {

        return callRemote<int >("getActiveCamera");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    AL::ALValue getActiveCameras(const std::string& name)
    {

        return callRemote<AL::ALValue >("getActiveCameras" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getAngPosFromImgPos(const std::vector<float>& arg1)
    {

        return callRemote<std::vector<float> >("getAngPosFromImgPos" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getAngSizeFromImgSize(const std::vector<float>& arg1)
    {

        return callRemote<std::vector<float> >("getAngSizeFromImgSize" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getAngularPositionFromImagePosition(const int& arg1, const std::vector<float>& arg2)
    {

        return callRemote<std::vector<float> >("getAngularPositionFromImagePosition" , arg1, arg2);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getAngularSizeFromImageSize(const int& arg1, const std::vector<float>& arg2)
    {

        return callRemote<std::vector<float> >("getAngularSizeFromImageSize" , arg1, arg2);
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
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns> 1(kOV7670): VGA camera - 2(kMT9M114): HD camera </returns>
    int getCameraModel(const int& cameraIndex)
    {

        return callRemote<int >("getCameraModel" , cameraIndex);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <returns>  </returns>
    int getCameraModelID()
    {

        return callRemote<int >("getCameraModelID");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <returns>  </returns>
    int getCameraParameter(const std::string& name, const int& parameterId)
    {

        return callRemote<int >("getCameraParameter" , name, parameterId);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <returns>  </returns>
    AL::ALValue getCamerasParameter(const std::string& name, const int& parameterId)
    {

        return callRemote<AL::ALValue >("getCamerasParameter" , name, parameterId);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    int getColorSpace(const int& cameraIndex)
    {

        return callRemote<int >("getColorSpace" , cameraIndex);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    int getColorSpace(const std::string& name)
    {

        return callRemote<int >("getColorSpace" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    AL::ALValue getColorSpaces(const std::string& name)
    {

        return callRemote<AL::ALValue >("getColorSpaces" , name);
    }




    /// <summary>
    /// Fills an ALValue with data coming directly from raw buffer (no format conversion).
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getDirectRawImageRemote(const std::string& name)
    {

        return callRemote<AL::ALValue >("getDirectRawImageRemote" , name);
    }




    /// <summary>
    /// Fills an ALValue with data coming directly from raw buffer (no format conversion).
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getDirectRawImagesRemote(const std::string& name)
    {

        return callRemote<AL::ALValue >("getDirectRawImagesRemote" , name);
    }


    /// <summary>
    /// called by the simulator to know expected image parameters
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns> ALValue of expected parameters, [int resolution, int framerate] </returns>
    AL::ALValue getExpectedImageParameters(const int& cameraIndex)
    {

        return callRemote<AL::ALValue >("getExpectedImageParameters" , cameraIndex);
    }


    /// <summary>
    /// called by the simulator to know expected image parameters
    /// </summary>
    /// <returns> ALValue of expected parameters, [int resolution, int framerate] </returns>
    AL::ALValue getExpectedImageParameters()
    {

        return callRemote<AL::ALValue >("getExpectedImageParameters");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    int getFrameRate(const int& cameraIndex)
    {

        return callRemote<int >("getFrameRate" , cameraIndex);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    int getFrameRate(const std::string& name)
    {

        return callRemote<int >("getFrameRate" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    int getGVMColorSpace(const std::string& arg1)
    {

        return callRemote<int >("getGVMColorSpace" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    int getGVMFrameRate(const std::string& arg1)
    {

        return callRemote<int >("getGVMFrameRate" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    int getGVMResolution(const std::string& arg1)
    {

        return callRemote<int >("getGVMResolution" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImageInfoFromAngularInfo(const int& arg1, const std::vector<float>& arg2)
    {

        return callRemote<std::vector<float> >("getImageInfoFromAngularInfo" , arg1, arg2);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <param name="arg3"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImageInfoFromAngularInfoWithResolution(const int& arg1, const std::vector<float>& arg2, const int& arg3)
    {

        return callRemote<std::vector<float> >("getImageInfoFromAngularInfoWithResolution" , arg1, arg2, arg3);
    }




    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImagePositionFromAngularPosition(const int& arg1, const std::vector<float>& arg2)
    {

        return callRemote<std::vector<float> >("getImagePositionFromAngularPosition" , arg1, arg2);
    }


    /// <summary>
    /// Applies transformations to the last image from video source and fills pFrameOut.
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getImageRemote(const std::string& name)
    {

        return callRemote<AL::ALValue >("getImageRemote" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImageSizeFromAngularSize(const int& arg1, const std::vector<float>& arg2)
    {

        return callRemote<std::vector<float> >("getImageSizeFromAngularSize" , arg1, arg2);
    }




    /// <summary>
    /// Applies transformations to the last image from video source and fills pFrameOut.
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> Array containing image informations : 
    ///
    ///     [0] : width;
    ///
    ///     [1] : height;
    ///
    ///     [2] : number of layers;
    ///
    ///     [3] : ColorSpace;
    ///
    ///     [4] : time stamp (highest 32 bits);
    ///
    ///     [5] : time stamp (lowest 32 bits);
    ///
    ///     [6] : array of size height * width * nblayers containing image data;
    ///
    ///     [7] : cameraID;
    ///
    ///     [8] : left angle;
    ///
    ///     [9] : top angle;
    ///
    ///     [10] : right angle;
    ///
    ///     [11] : bottom angle; </returns>
    AL::ALValue getImagesRemote(const std::string& name)
    {

        return callRemote<AL::ALValue >("getImagesRemote" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImgInfoFromAngInfo(const std::vector<float>& arg1)
    {

        return callRemote<std::vector<float> >("getImgInfoFromAngInfo" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImgInfoFromAngInfoWithRes(const std::vector<float>& arg1, const int& arg2)
    {

        return callRemote<std::vector<float> >("getImgInfoFromAngInfoWithRes" , arg1, arg2);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImgPosFromAngPos(const std::vector<float>& arg1)
    {

        return callRemote<std::vector<float> >("getImgPosFromAngPos" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    std::vector<float> getImgSizeFromAngSize(const std::vector<float>& arg1)
    {

        return callRemote<std::vector<float> >("getImgSizeFromAngSize" , arg1);
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
    /// 
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <param name="pCameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    int getParam(const int& pParam, const int& pCameraIndex)
    {

        return callRemote<int >("getParam" , pParam, pCameraIndex);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <returns>  </returns>
    int getParam(const int& pParam)
    {

        return callRemote<int >("getParam" , pParam);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    int getResolution(const int& cameraIndex)
    {

        return callRemote<int >("getResolution" , cameraIndex);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    int getResolution(const std::string& name)
    {

        return callRemote<int >("getResolution" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns>  </returns>
    AL::ALValue getResolutions(const std::string& name)
    {

        return callRemote<AL::ALValue >("getResolutions" , name);
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
    /// 
    /// </summary>
    /// <returns>  </returns>
    int getVIMColorSpace()
    {

        return callRemote<int >("getVIMColorSpace");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <returns>  </returns>
    int getVIMFrameRate()
    {

        return callRemote<int >("getVIMFrameRate");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <returns>  </returns>
    int getVIMResolution()
    {

        return callRemote<int >("getVIMResolution");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    bool isFrameGrabberOff(const int& cameraIndex)
    {

        return callRemote<bool >("isFrameGrabberOff" , cameraIndex);
    }


    /// <summary>
    /// Advanced method that asks if the framegrabber is off.
    /// </summary>
    /// <returns> true if off </returns>
    int isFrameGrabberOff()
    {

        return callRemote<int >("isFrameGrabberOff");
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
    /// Callback when client is disconnected
    /// </summary>
    /// <param name="eventName"> The echoed event name </param>
    /// <param name="eventContents"> The name of the client that has disconnected </param>
    /// <param name="message"> The message give when subscribing. </param>
    void onClientDisconnected(const std::string& eventName, const AL::ALValue& eventContents, const std::string& message)
    {

        callVoidRemote("onClientDisconnected" , eventName, eventContents, message);
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
    /// Allow image buffer pushing
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <param name="width"> int width of image among 1280*960, 640*480, 320*240, 240*160 </param>
    /// <param name="height"> int height of image </param>
    /// <param name="imageBuffer"> Image buffer in bitmap form </param>
    /// <returns> true if the put succeeded </returns>
    bool putImage(const int& cameraIndex, const int& width, const int& height, const AL::ALValue& imageBuffer)
    {

        return callRemote<bool >("putImage" , cameraIndex, width, height, imageBuffer);
    }


    /// <summary>
    /// Allow image buffer pushing
    /// </summary>
    /// <param name="imageBuffer"> Image buffer in bitmap form </param>
    /// <returns> true if the put succeeded </returns>
    bool putImage(const AL::ALValue& imageBuffer)
    {

        return callRemote<bool >("putImage" , imageBuffer);
    }


    /// <summary>
    /// Background record of an .arv raw format video from the images processed by a vision module
    ///
    /// Actualy it take picture each time the vision module call getDirectRawImageRemote().
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from the V.I.M. </param>
    /// <param name="path"> path/name of the video to be recorded </param>
    /// <param name="totalNumber"> number of images to be recorded. 0xFFFFFFFF for \"unlimited\" </param>
    /// <param name="period"> one image recorded every pPeriod images </param>
    /// <returns> true if success </returns>
    bool recordVideo(const std::string& id, const std::string& path, const int& totalNumber, const int& period)
    {

        return callRemote<bool >("recordVideo" , id, path, totalNumber, period);
    }






    /// <summary>
    /// Release image buffer locked by getImageLocal().
    ///
    /// If G.V.M. had no locked image buffer, does nothing.
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> true if success </returns>
    bool releaseImage(const std::string& name)
    {

        return callRemote<bool >("releaseImage" , name);
    }


    /// <summary>
    /// Release image buffer locked by getImageLocal().
    ///
    /// If G.V.M. had no locked image buffer, does nothing.
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <returns> true if success </returns>
    AL::ALValue releaseImages(const std::string& name)
    {

        return callRemote<AL::ALValue >("releaseImages" , name);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns>  </returns>
    AL::ALValue resolutionToSizes(const int& arg1)
    {

        return callRemote<AL::ALValue >("resolutionToSizes" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    bool setActiveCamera(const std::string& name, const int& cameraIndex)
    {

        return callRemote<bool >("setActiveCamera" , name, cameraIndex);
    }


    /// <summary>
    /// Set the active camera
    /// </summary>
    /// <param name="activeCamera"> 0: top camera - 1: bottom camera </param>
    /// <returns>  </returns>
    bool setActiveCamera(const int& activeCamera)
    {

        return callRemote<bool >("setActiveCamera" , activeCamera);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="cameraIndexes"> Cameras requested. </param>
    /// <returns>  </returns>
    AL::ALValue setActiveCameras(const std::string& name, const AL::ALValue& cameraIndexes)
    {

        return callRemote<AL::ALValue >("setActiveCameras" , name, cameraIndexes);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <param name="value"> value requested. </param>
    /// <returns>  </returns>
    bool setCameraParameter(const std::string& name, const int& parameterId, const int& value)
    {

        return callRemote<bool >("setCameraParameter" , name, parameterId, value);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <returns>  </returns>
    bool setCameraParameterToDefault(const std::string& name, const int& parameterId)
    {

        return callRemote<bool >("setCameraParameterToDefault" , name, parameterId);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <param name="values"> values requested. </param>
    /// <returns>  </returns>
    AL::ALValue setCamerasParameter(const std::string& name, const int& parameterId, const AL::ALValue& values)
    {

        return callRemote<AL::ALValue >("setCamerasParameter" , name, parameterId, values);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="parameterId"> Camera parameter requested. </param>
    /// <returns>  </returns>
    AL::ALValue setCamerasParameterToDefault(const std::string& name, const int& parameterId)
    {

        return callRemote<AL::ALValue >("setCamerasParameterToDefault" , name, parameterId);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="colorSpace"> Color Space requested. </param>
    /// <returns>  </returns>
    bool setColorSpace(const std::string& name, const int& colorSpace)
    {

        return callRemote<bool >("setColorSpace" , name, colorSpace);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="colorSpaces"> Color Spaces requested. </param>
    /// <returns>  </returns>
    AL::ALValue setColorSpaces(const std::string& name, const AL::ALValue& colorSpaces)
    {

        return callRemote<AL::ALValue >("setColorSpaces" , name, colorSpaces);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="frameRate"> Frame Rate requested. </param>
    /// <returns>  </returns>
    bool setFrameRate(const std::string& name, const int& frameRate)
    {

        return callRemote<bool >("setFrameRate" , name, frameRate);
    }


    /// <summary>
    /// Sets the value of a specific parameter for the video source.
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <param name="pNewValue"> value requested. </param>
    /// <param name="pCameraIndex"> Camera requested. </param>
    void setParam(const int& pParam, const int& pNewValue, const int& pCameraIndex)
    {

        callVoidRemote("setParam" , pParam, pNewValue, pCameraIndex);
    }


    /// <summary>
    /// Sets the value of a specific parameter for the video source.
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <param name="pNewValue"> value requested. </param>
    void setParam(const int& pParam, const int& pNewValue)
    {

        callVoidRemote("setParam" , pParam, pNewValue);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setParamDefault(const int& arg1)
    {

        callVoidRemote("setParamDefault" , arg1);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="resolution"> Resolution requested. </param>
    /// <returns>  </returns>
    bool setResolution(const std::string& name, const int& resolution)
    {

        return callRemote<bool >("setResolution" , name, resolution);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="resolutions"> Resolutions requested. </param>
    /// <returns>  </returns>
    AL::ALValue setResolutions(const std::string& name, const AL::ALValue& resolutions)
    {

        return callRemote<AL::ALValue >("setResolutions" , name, resolutions);
    }


    /// <summary>
    /// called by the simulator to know expected image parameters
    /// </summary>
    /// <param name="width"> int width of image among 1280*960, 640*480, 320*240, 240*160 </param>
    /// <param name="height"> int height of image among 1280*960, 640*480, 320*240, 240*160 </param>
    /// <returns> true if setSize worked </returns>
    bool setSimCamInputSize(const int& width, const int& height)
    {

        return callRemote<bool >("setSimCamInputSize" , width, height);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <param name="arg2"> arg </param>
    /// <returns>  </returns>
    int sizesToResolution(const int& arg1, const int& arg2)
    {

        return callRemote<int >("sizesToResolution" , arg1, arg2);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    bool startFrameGrabber(const int& cameraIndex)
    {

        return callRemote<bool >("startFrameGrabber" , cameraIndex);
    }


    /// <summary>
    /// Advanced method that opens and initialize video source device if it was not before.
    ///
    /// Note that the first module subscribing to ALVideoDevice will launch it automatically.
    /// </summary>
    /// <returns> true if success </returns>
    bool startFrameGrabber()
    {

        return callRemote<bool >("startFrameGrabber");
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
    /// 
    /// </summary>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <returns>  </returns>
    bool stopFrameGrabber(const int& cameraIndex)
    {

        return callRemote<bool >("stopFrameGrabber" , cameraIndex);
    }


    /// <summary>
    /// Advanced method that close video source device.
    ///
    /// Note that the last module unsubscribing to ALVideoDevice will launch it automatically.
    /// </summary>
    /// <returns> true if success </returns>
    bool stopFrameGrabber()
    {

        return callRemote<bool >("stopFrameGrabber");
    }


    /// <summary>
    /// Stop writing the video sequence
    /// </summary>
    /// <param name="id"> Name under which the G.V.M. is known from ALVideoDevice. </param>
    /// <returns> true if success </returns>
    bool stopVideo(const std::string& id)
    {

        return callRemote<bool >("stopVideo" , id);
    }


    /// <summary>
    /// Register to ALVideoDevice (formerly Video Input Module/V.I.M.). When a General Video Module(G.V.M.) registers to ALVideoDevice, a buffer of the requested image format is added to the buffers list.
    ///
    /// Returns the name under which the G.V.M. is registered to ALVideoDevice (useful when two G.V.M. try to register using the same name
    /// </summary>
    /// <param name="gvmName"> Name of the subscribing G.V.M. </param>
    /// <param name="resolution"> Resolution requested. { 0 = kQQVGA, 1 = kQVGA, 2 = kVGA } </param>
    /// <param name="colorSpace"> Colorspace requested. { 0 = kYuv, 9 = kYUV422, 10 = kYUV, 11 = kRGB, 12 = kHSY, 13 = kBGR } </param>
    /// <param name="fps"> Fps (frames per second) requested. { 5, 10, 15, 30 } </param>
    /// <returns> Name under which the G.V.M. is known from ALVideoDevice, 0 if failed. </returns>
    std::string subscribe(const std::string& gvmName, const int& resolution, const int& colorSpace, const int& fps)
    {

        return callRemote<std::string >("subscribe" , gvmName, resolution, colorSpace, fps);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="cameraIndex"> Camera requested. </param>
    /// <param name="resolution"> Resolution requested.{0=kQQVGA, 1=kQVGA, 2=kVGA, 3=k4VGA} </param>
    /// <param name="colorSpace"> Colorspace requested.{0=kYuv, 9=kYUV422, 10=kYUV, 11=kRGB, 12=kHSY, 13=kBGR} </param>
    /// <param name="fps"> Fps (frames per second) requested.{5, 10, 15, 30} </param>
    /// <returns> Name under which the vision module is known from ALVideoDevice </returns>
    std::string subscribeCamera(const std::string& name, const int& cameraIndex, const int& resolution, const int& colorSpace, const int& fps)
    {

        return callRemote<std::string >("subscribeCamera" , name, cameraIndex, resolution, colorSpace, fps);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"> Name of the subscribing vision module </param>
    /// <param name="cameraIndexes"> Cameras requested. </param>
    /// <param name="resolutions"> Resolutions requested.{0=kQQVGA, 1=kQVGA, 2=kVGA, 3=k4VGA} </param>
    /// <param name="colorSpaces"> Colorspaces requested.{0=kYuv, 9=kYUV422, 10=kYUV, 11=kRGB, 12=kHSY, 13=kBGR} </param>
    /// <param name="fps"> Fps (frames per second) requested.{5, 10, 15, 30} </param>
    /// <returns> Name under which the vision module is known from ALVideoDevice </returns>
    std::string subscribeCameras(const std::string& name, const AL::ALValue& cameraIndexes, const AL::ALValue& resolutions, const AL::ALValue& colorSpaces, const int& fps)
    {

        return callRemote<std::string >("subscribeCameras" , name, cameraIndexes, resolutions, colorSpaces, fps);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="nameId"> Name under which the vision module is known from ALVideoDevice. </param>
    void unsubscribe(const std::string& nameId)
    {

        callVoidRemote("unsubscribe" , nameId);
    }


    /// <summary>
    /// Used to unsubscribe all instances for a given G.V.M. (e.g. VisionModule and VisionModule_5) from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Root name of the G.V.M. (e.g. with the example above this will be VisionModule). </param>
    void unsubscribeAllInstances(const std::string& id)
    {

        callVoidRemote("unsubscribeAllInstances" , id);
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
#endif // ALVIDEODEVICEPROXY_H_
