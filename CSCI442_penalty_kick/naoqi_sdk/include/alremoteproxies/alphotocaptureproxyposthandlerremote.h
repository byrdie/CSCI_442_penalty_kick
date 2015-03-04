// Generated for ALPhotoCapture version 1.14


#ifndef ALPHOTOCAPTUREPROXYPOSTHANDLERREMOTE_H_
#define ALPHOTOCAPTUREPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALPhotoCaptureProxyRemote;

/// <summary>This module provides methods to take pictures and store them on disk.</summary>
class ALPhotoCaptureProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALPhotoCaptureProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// This module provides methods to take pictures and store them on disk.
    /// ALPhotoCapturePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALPhotoCaptureProxyPostHandlerRemote() : fParent(NULL)
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
    /// Sets delay between two captures.
    /// </summary>
    /// <param name="captureInterval"> New delay (in ms) between two pictures. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setCaptureInterval(const int& captureInterval)
    {
      return fParent->pCall("setCaptureInterval" , captureInterval);
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
    /// Sets picture extension.
    /// </summary>
    /// <param name="pictureFormat"> New extension used to save pictures. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setPictureFormat(const std::string& pictureFormat)
    {
      return fParent->pCall("setPictureFormat" , pictureFormat);
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
#endif // ALPHOTOCAPTUREPROXYPOSTHANDLERREMOTE_H_

