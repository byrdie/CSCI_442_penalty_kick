// Generated for ALSentinel version 1.14


#ifndef ALSENTINELPROXYPOSTHANDLERREMOTE_H_
#define ALSENTINELPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALSentinelProxyRemote;

/// <summary>ALSentinel (ex-ALWatchDog) is a module that implements vital services for Nao:
    ///
    /// 	- Check Vitality of naoqi.
    ///
    /// 	- Check Battery.
    ///
    /// 	- Check press on chest Button (soft power off).
    ///
    /// 	- Warn about motor heating.
    ///
    /// ...</summary>
class ALSentinelProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALSentinelProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// ALSentinel (ex-ALWatchDog) is a module that implements vital services for Nao:
    ///
    /// 	- Check Vitality of naoqi.
    ///
    /// 	- Check Battery.
    ///
    /// 	- Check press on chest Button (soft power off).
    ///
    /// 	- Warn about motor heating.
    ///
    /// ...
    /// ALSentinelPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALSentinelProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int batteryPowerPluggedChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {
      return fParent->pCall("batteryPowerPluggedChanged" , dataName, data, message);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  check the battery information, voltage and alarm flag
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableBatteryMeasure(const bool& enable)
    {
      return fParent->pCall("enableBatteryMeasure" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  check the remaining physical memory
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable (default: true) </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableCheckRemainingRam(const bool& enable)
    {
      return fParent->pCall("enableCheckRemainingRam" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  enable or disable the \"ouch\" action after two pushes.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableDefaultActionDoubleClick(const bool& enable)
    {
      return fParent->pCall("enableDefaultActionDoubleClick" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14.
    ///
    /// enable or disable the \"hello, i'm nao...\" after one short push of the Power button. In both cases the ALMemory ALSentinel/SimpleClickOccured key will be set to true, so users can read/registerOnChange it, then reset to false after handling the event.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableDefaultActionSimpleClick(const bool& enable)
    {
      return fParent->pCall("enableDefaultActionSimpleClick" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  enable or disable the \"restart naoqi\" action after three pushes.
    /// </summary>
    /// <param name="enable"> true of false to respectively enable or disable </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableDefaultActionTripleClick(const bool& enable)
    {
      return fParent->pCall("enableDefaultActionTripleClick" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  Enable or Disable heat monitoring.
    /// </summary>
    /// <param name="enable"> true to enable, false to disable, default: true </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enableHeatMonitoring(const bool& enable)
    {
      return fParent->pCall("enableHeatMonitoring" , enable);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  Enable or Disable power monitoring.
    /// </summary>
    /// <param name="enable"> true to enable, false to disable, default: true </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int enablePowerMonitoring(const bool& enable)
    {
      return fParent->pCall("enablePowerMonitoring" , enable);
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
    /// DEPRECATED since 1.14
    ///
    ///  exit naoqi (warning: it will really exit Naoqi)
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exitNaoqi()
    {
      return fParent->pCall("exitNaoqi");
    }










    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  callback for internal use.
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onBatteryMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {
      return fParent->pCall("onBatteryMeasure" , dataName, data, message);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  callback for change in battery power level. (internal use).
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onMotorError(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {
      return fParent->pCall("onMotorError" , dataName, data, message);
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  callback for change in battery power level. (internal use).
    /// </summary>
    /// <param name="dataName"> Name of the modified data </param>
    /// <param name="data"> value of the data </param>
    /// <param name="message"> associate message. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int onTemperatureMeasure(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {
      return fParent->pCall("onTemperatureMeasure" , dataName, data, message);
    }


    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  Launch a small presentation of Nao: name, ip, battery. It's the default behavior launched when user press on the chest
    /// </summary>
    /// <param name="enableFastCheckJoints"> if true, Nao will quickly check that his joints are moving properly. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int presentation(const bool& enableFastCheckJoints)
    {
      return fParent->pCall("presentation" , enableFastCheckJoints);
    }

    /// <summary>
    /// Monitors buttons and Battery.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int run()
    {
      return fParent->pCall("run");
    }

    /// <summary>
    /// DEPRECATED since 1.14
    ///
    ///  Change the power threshold; below it, Nao will sit down and remove power from his motors.
    /// </summary>
    /// <param name="powerLimit"> power limit in percent, default: 0.07; 0.00 to disable this feature. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setPowerLimit(const float& powerLimit)
    {
      return fParent->pCall("setPowerLimit" , powerLimit);
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
#endif // ALSENTINELPROXYPOSTHANDLERREMOTE_H_

