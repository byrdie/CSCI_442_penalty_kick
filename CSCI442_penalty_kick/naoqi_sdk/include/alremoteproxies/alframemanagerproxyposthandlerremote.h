// Generated for ALFrameManager version 1.14


#ifndef ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_
#define ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALFrameManagerProxyRemote;

/// <summary>Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.</summary>
class ALFrameManagerProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALFrameManagerProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.
    /// ALFrameManagerPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALFrameManagerProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Stop playing any behavior in FrameManager, and delete all of them.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int cleanBehaviors()
    {
      return fParent->pCall("cleanBehaviors");
    }

    /// <summary>
    /// It will play a behavior and block until the behavior is finished. Note that it can block forever if the behavior output is never called.
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int completeBehavior(const std::string& id)
    {
      return fParent->pCall("completeBehavior" , id);
    }


    /// <summary>
    /// Deletes a behavior (meaning a box). Stop the whole behavior contained in this box first.
    /// </summary>
    /// <param name="id"> The id of the box to delete. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int deleteBehavior(const std::string& id)
    {
      return fParent->pCall("deleteBehavior" , id);
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
    /// Exit the reading of a timeline contained in a given box
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exitBehavior(const std::string& id)
    {
      return fParent->pCall("exitBehavior" , id);
    }









    /// <summary>
    /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndPlay(const std::string& id, const std::string& frame)
    {
      return fParent->pCall("gotoAndPlay" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndPlay(const std::string& id, const int& frame)
    {
      return fParent->pCall("gotoAndPlay" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and pause. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndStop(const std::string& id, const std::string& frame)
    {
      return fParent->pCall("gotoAndStop" , id, frame);
    }

    /// <summary>
    /// Goes to a certain frame and pause. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box containing the box. </param>
    /// <param name="frame"> The frame we want the timeline to go to. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int gotoAndStop(const std::string& id, const int& frame)
    {
      return fParent->pCall("gotoAndStop" , id, frame);
    }






    /// <summary>
    /// Starts a behavior
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playBehavior(const std::string& id)
    {
      return fParent->pCall("playBehavior" , id);
    }

    /// <summary>
    /// Starts playing a timeline contained in a given box. If the box is a flow diagram, it will look for the first onStart input of type Bang, and stimulate it ! DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int playTimeline(const std::string& id)
    {
      return fParent->pCall("playTimeline" , id);
    }

    /// <summary>
    /// enable the deprecation warning
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setDeprecationWarningEnabled(const bool& arg1)
    {
      return fParent->pCall("setDeprecationWarningEnabled" , arg1);
    }

    /// <summary>
    /// Sets the FPS of a given timeline. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the timeline. </param>
    /// <param name="fps"> The FPS to set. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setTimelineFps(const std::string& id, const int& fps)
    {
      return fParent->pCall("setTimelineFps" , id, fps);
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
    /// Stops playing a timeline contained in a given box, at the current frame. DEPRECATED since 1.14
    /// </summary>
    /// <param name="id"> The id of the box. </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stopTimeline(const std::string& id)
    {
      return fParent->pCall("stopTimeline" , id);
    }



};

}
#endif // ALFRAMEMANAGERPROXYPOSTHANDLERREMOTE_H_

