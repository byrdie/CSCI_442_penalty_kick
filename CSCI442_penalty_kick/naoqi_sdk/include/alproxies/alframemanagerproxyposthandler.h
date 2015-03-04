// Generated for ALFrameManager version 1.14

#ifndef ALFRAMEMANAGERPROXYPOSTHANDLER_H_
#define ALFRAMEMANAGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALFrameManagerProxy;

/// <summary>
/// Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.
/// ALFrameManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALFrameManagerProxyPostHandler
{
  friend class ALFrameManagerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Frame manager is used to play choregraphe projects in naoqi. It needs Choregraphe projects in input and will return an ID for each project. It can also only read a given box/timeline in a complex behavior.
  /// ALFrameManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALFrameManagerProxyPostHandler();

  /// <summary>
  /// Stop playing any behavior in FrameManager, and delete all of them.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int cleanBehaviors();
  /// <summary>
  /// It will play a behavior and block until the behavior is finished. Note that it can block forever if the behavior output is never called.
  /// </summary>
  /// <param name="id"> The id of the box. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int completeBehavior(const std::string& id);
  /// <summary>
  /// Deletes a behavior (meaning a box). Stop the whole behavior contained in this box first.
  /// </summary>
  /// <param name="id"> The id of the box to delete. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int deleteBehavior(const std::string& id);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Exit the reading of a timeline contained in a given box
  /// </summary>
  /// <param name="id"> The id of the box. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exitBehavior(const std::string& id);
  /// <summary>
  /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box containing the box. </param>
  /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int gotoAndPlay(const std::string& id, const std::string& frame);
  /// <summary>
  /// Goes to a certain frame and continue playing. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box containing the box. </param>
  /// <param name="frame"> The frame we want the timeline to go to. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int gotoAndPlay(const std::string& id, const int& frame);
  /// <summary>
  /// Goes to a certain frame and pause. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box containing the box. </param>
  /// <param name="frame"> The behavior frame name we want the timeline to go to. If will jump to the starting index of the name given. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int gotoAndStop(const std::string& id, const std::string& frame);
  /// <summary>
  /// Goes to a certain frame and pause. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box containing the box. </param>
  /// <param name="frame"> The frame we want the timeline to go to. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int gotoAndStop(const std::string& id, const int& frame);
  /// <summary>
  /// Starts a behavior
  /// </summary>
  /// <param name="id"> The id of the box. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playBehavior(const std::string& id);
  /// <summary>
  /// Starts playing a timeline contained in a given box. If the box is a flow diagram, it will look for the first onStart input of type Bang, and stimulate it ! DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int playTimeline(const std::string& id);
  /// <summary>
  /// enable the deprecation warning
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setDeprecationWarningEnabled(const bool& arg1);
  /// <summary>
  /// Sets the FPS of a given timeline. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the timeline. </param>
  /// <param name="fps"> The FPS to set. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setTimelineFps(const std::string& id, const int& fps);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Stops playing a timeline contained in a given box, at the current frame. DEPRECATED since 1.14
  /// </summary>
  /// <param name="id"> The id of the box. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopTimeline(const std::string& id);
};

}
#endif // ALFRAMEMANAGERPROXYPOSTHANDLER_H_

