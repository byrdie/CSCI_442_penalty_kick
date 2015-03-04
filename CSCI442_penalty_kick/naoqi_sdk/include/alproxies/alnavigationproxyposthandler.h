// Generated for ALNavigation version 1.14

#ifndef ALNAVIGATIONPROXYPOSTHANDLER_H_
#define ALNAVIGATIONPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALNavigationProxy;

/// <summary>
/// Use ALNavigation module to make the robot go safely to the asked pose2D.
/// ALNavigationPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALNavigationProxyPostHandler
{
  friend class ALNavigationProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// Use ALNavigation module to make the robot go safely to the asked pose2D.
  /// ALNavigationPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALNavigationProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Distance in meters fromwhich the robot should stop if there is an obstacle.
  /// </summary>
  /// <param name="arg1"> arg </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setSecurityDistance(const float& arg1);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALNAVIGATIONPROXYPOSTHANDLER_H_

