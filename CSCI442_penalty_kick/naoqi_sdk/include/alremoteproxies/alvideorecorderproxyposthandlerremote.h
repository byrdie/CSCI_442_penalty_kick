// Generated for ALVideoRecorder version 1.14


#ifndef ALVIDEORECORDERPROXYPOSTHANDLERREMOTE_H_
#define ALVIDEORECORDERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALVideoRecorderProxyRemote;

/// <summary>This module provides methods to record videos and store them on disk.</summary>
class ALVideoRecorderProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALVideoRecorderProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module provides methods to record videos and store them on disk.
    /// ALVideoRecorderPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALVideoRecorderProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }














    /// <summary>
    /// Sets camera ID.
    /// </summary>
    /// <param name="cameraID"> ID of the camera to use. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setCameraID(const int& cameraID)
    {
      return fParent->pCall("setCameraID" , cameraID);
    }

    /// <summary>
    /// Sets color space.
    /// </summary>
    /// <param name="colorSpace"> New color space. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setColorSpace(const int& colorSpace)
    {
      return fParent->pCall("setColorSpace" , colorSpace);
    }

    /// <summary>
    /// Sets frame rate.
    /// </summary>
    /// <param name="frameRate"> New frame rate. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setFrameRate(const float& frameRate)
    {
      return fParent->pCall("setFrameRate" , frameRate);
    }

    /// <summary>
    /// Sets resolution.
    /// </summary>
    /// <param name="resolution"> New frame resolution. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setResolution(const int& resolution)
    {
      return fParent->pCall("setResolution" , resolution);
    }

    /// <summary>
    /// Sets video format.
    /// </summary>
    /// <param name="videoFormat"> New video format. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setVideoFormat(const std::string& videoFormat)
    {
      return fParent->pCall("setVideoFormat" , videoFormat);
    }

    /// <summary>
    /// Starts recording a video. Please note that only one record at a time can be made.
    /// </summary>
    /// <param name="folderPath"> Folder where the video is saved. </param>
    /// <param name="fileName"> Filename used to save the video. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startRecording(const std::string& folderPath, const std::string& fileName)
    {
      return fParent->pCall("startRecording" , folderPath, fileName);
    }

    /// <summary>
    /// Starts recording a video. Please note that only one record at a time can be made.
    /// </summary>
    /// <param name="folderPath"> Folder where the video is saved. </param>
    /// <param name="fileName"> Filename used to save the video. </param>
    /// <param name="overwrite"> If false and the filename already exists, an error is thrown. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int startRecording(const std::string& folderPath, const std::string& fileName, const bool& overwrite)
    {
      return fParent->pCall("startRecording" , folderPath, fileName, overwrite);
    }

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }




};

}
#endif // ALVIDEORECORDERPROXYPOSTHANDLERREMOTE_H_

