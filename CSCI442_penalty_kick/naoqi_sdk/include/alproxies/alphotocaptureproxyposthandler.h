// Generated for ALPhotoCapture version 1.14

#ifndef ALPHOTOCAPTUREPROXYPOSTHANDLER_H_
#define ALPHOTOCAPTUREPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALPhotoCaptureProxy;

/// <summary>
/// This module provides methods to take pictures and store them on disk.
/// ALPhotoCapturePostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALPhotoCaptureProxyPostHandler
{
  friend class ALPhotoCaptureProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module provides methods to take pictures and store them on disk.
  /// ALPhotoCapturePostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALPhotoCaptureProxyPostHandler();

  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Sets camera ID.
  /// </summary>
  /// <param name="cameraID"> ID of the camera to use. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setCameraID(const int& cameraID);
  /// <summary>
  /// Sets delay between two captures.
  /// </summary>
  /// <param name="captureInterval"> New delay (in ms) between two pictures. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setCaptureInterval(const int& captureInterval);
  /// <summary>
  /// Sets color space.
  /// </summary>
  /// <param name="colorSpace"> New color space. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setColorSpace(const int& colorSpace);
  /// <summary>
  /// Sets picture extension.
  /// </summary>
  /// <param name="pictureFormat"> New extension used to save pictures. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setPictureFormat(const std::string& pictureFormat);
  /// <summary>
  /// Sets resolution.
  /// </summary>
  /// <param name="resolution"> New frame resolution. </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setResolution(const int& resolution);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALPHOTOCAPTUREPROXYPOSTHANDLER_H_

