// Generated for ALVisualCompass version 1.14


#ifndef ALVISUALCOMPASSPROXYPOSTHANDLERREMOTE_H_
#define ALVISUALCOMPASSPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALVisualCompassProxyRemote;

/// <summary></summary>
class ALVisualCompassProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALVisualCompassProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// 
    /// ALVisualCompassPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALVisualCompassProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// 
    /// </summary>
    /// <param name="refresh"> True if the reference is automatically refreshed at extractor startup; false to use the manually set reference image. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableReferenceRefresh(const bool& refresh)
    {
      return fParent->pCall("enableReferenceRefresh" , refresh);
    }

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }






















    /// <summary>
    /// Changes the pause status of the extractor
    /// </summary>
    /// <param name="paused"> New pause satus </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int pause(const bool& paused)
    {
      return fParent->pCall("pause" , paused);
    }




    /// <summary>
    /// DEPRECATED: Sets pause and resolution
    /// </summary>
    /// <param name="paramName"> Name of the parameter to set </param>
    /// <param name="value"> New value </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setParameter(const std::string& paramName, const AL::ALValue& value)
    {
      return fParent->pCall("setParameter" , paramName, value);
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
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name, const int& period, const float& precision)
    {
      return fParent->pCall("subscribe" , name, period, precision);
    }

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int subscribe(const std::string& name)
    {
      return fParent->pCall("subscribe" , name);
    }

    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int unsubscribe(const std::string& name)
    {
      return fParent->pCall("unsubscribe" , name);
    }

    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePeriod(const std::string& name, const int& period)
    {
      return fParent->pCall("updatePeriod" , name, period);
    }

    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int updatePrecision(const std::string& name, const float& precision)
    {
      return fParent->pCall("updatePrecision" , name, precision);
    }



};

}
#endif // ALVISUALCOMPASSPROXYPOSTHANDLERREMOTE_H_

