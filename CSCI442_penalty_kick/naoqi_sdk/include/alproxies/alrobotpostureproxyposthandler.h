// Generated for ALRobotPosture version 1.14

#ifndef ALROBOTPOSTUREPROXYPOSTHANDLER_H_
#define ALROBOTPOSTUREPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALRobotPostureProxy;

/// <summary>
/// Use ALRobotPosture module to make the robot go tothe asked posture.
/// ALRobotPosturePostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALRobotPostureProxyPostHandler
{
  friend class ALRobotPostureProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Use ALRobotPosture module to make the robot go tothe asked posture.
  /// ALRobotPosturePostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALRobotPostureProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Set maximum of tries on goToPosture fail.
  /// </summary>
  /// <param name="pMaxTryNumber"> Number of retry if goToPosture fail. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setMaxTryNumber(const int& pMaxTryNumber);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
  /// <summary>
  /// Stop the posture move.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stopMove();
};

}
#endif // ALROBOTPOSTUREPROXYPOSTHANDLER_H_

