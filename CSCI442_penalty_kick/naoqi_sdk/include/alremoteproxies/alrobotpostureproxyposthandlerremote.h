// Generated for ALRobotPosture version 1.14


#ifndef ALROBOTPOSTUREPROXYPOSTHANDLERREMOTE_H_
#define ALROBOTPOSTUREPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALRobotPostureProxyRemote;

/// <summary>Use ALRobotPosture module to make the robot go tothe asked posture.</summary>
class ALRobotPostureProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALRobotPostureProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Use ALRobotPosture module to make the robot go tothe asked posture.
    /// ALRobotPosturePostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALRobotPostureProxyPostHandlerRemote() : fParent(NULL)
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
    /// Set maximum of tries on goToPosture fail.
    /// </summary>
    /// <param name="pMaxTryNumber"> Number of retry if goToPosture fail. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setMaxTryNumber(const int& pMaxTryNumber)
    {
      return fParent->pCall("setMaxTryNumber" , pMaxTryNumber);
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
    /// Stop the posture move.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopMove()
    {
      return fParent->pCall("stopMove");
    }



};

}
#endif // ALROBOTPOSTUREPROXYPOSTHANDLERREMOTE_H_

