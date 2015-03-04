// Generated for ALVideoDevice version 1.14


#ifndef ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_
#define ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALVideoDeviceProxyRemote;

/// <summary>ALVideoDevice, formerly called Video Input systemis architectured in order to provide every module related to vision, called vision module, a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).</summary>
class ALVideoDeviceProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALVideoDeviceProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALVideoDevice, formerly called Video Input systemis architectured in order to provide every module related to vision, called vision module, a direct access to raw images from video source, or an access to images transformed in the requested format.
    ///
    ///   Extension name of the methods providing images depends on wether modules are local (dynamic library) or remote (executable).
    /// ALVideoDevicePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALVideoDeviceProxyPostHandlerRemote() : fParent(NULL)
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
    /// Callback when client is disconnected
    /// </summary>
    /// <param name="eventName"> The echoed event name </param>
    /// <param name="eventContents"> The name of the client that has disconnected </param>
    /// <param name="message"> The message give when subscribing. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onClientDisconnected(const std::string& eventName, const AL::ALValue& eventContents, const std::string& message)
    {
      return fParent->pCall("onClientDisconnected" , eventName, eventContents, message);
    }




















    /// <summary>
    /// Sets the value of a specific parameter for the video source.
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <param name="pNewValue"> value requested. </param>
    /// <param name="pCameraIndex"> Camera requested. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParam(const int& pParam, const int& pNewValue, const int& pCameraIndex)
    {
      return fParent->pCall("setParam" , pParam, pNewValue, pCameraIndex);
    }

    /// <summary>
    /// Sets the value of a specific parameter for the video source.
    /// </summary>
    /// <param name="pParam"> Camera parameter requested. </param>
    /// <param name="pNewValue"> value requested. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParam(const int& pParam, const int& pNewValue)
    {
      return fParent->pCall("setParam" , pParam, pNewValue);
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParamDefault(const int& arg1)
    {
      return fParent->pCall("setParamDefault" , arg1);
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







    /// <summary>
    /// 
    /// </summary>
    /// <param name="nameId"> Name under which the vision module is known from ALVideoDevice. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& nameId)
    {
      return fParent->pCall("unsubscribe" , nameId);
    }

    /// <summary>
    /// Used to unsubscribe all instances for a given G.V.M. (e.g. VisionModule and VisionModule_5) from ALVideoDevice.
    /// </summary>
    /// <param name="id"> Root name of the G.V.M. (e.g. with the example above this will be VisionModule). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribeAllInstances(const std::string& id)
    {
      return fParent->pCall("unsubscribeAllInstances" , id);
    }



};

}
#endif // ALVIDEODEVICEPROXYPOSTHANDLERREMOTE_H_

