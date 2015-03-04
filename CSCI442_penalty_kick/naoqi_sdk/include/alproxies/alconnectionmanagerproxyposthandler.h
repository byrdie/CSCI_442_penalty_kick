// Generated for ALConnectionManager version 1.14

#ifndef ALCONNECTIONMANAGERPROXYPOSTHANDLER_H_
#define ALCONNECTIONMANAGERPROXYPOSTHANDLER_H_
#include <boost/shared_ptr.hpp>
#include <alvalue/alvalue.h>
#include <string>
#include <vector>

namespace AL
{
class ALProxy;
class ALConnectionManagerProxy;

/// <summary>
/// This module is used to manage available connections
/// ALConnectionManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
/// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
/// </summary>
/// \ingroup ALProxies
class ALConnectionManagerProxyPostHandler
{
  friend class ALConnectionManagerProxy;

  protected:
  boost::shared_ptr<ALProxy> fParent;

  private:
  void setParent(boost::shared_ptr<ALProxy> pParent);

  public:
  /// <summary>
  /// This module is used to manage available connections
  /// ALConnectionManagerPostHandler gives acces to all bound methods of the module, using a thread around each call.
  /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
  /// </summary>
  ALConnectionManagerProxyPostHandler();

  /// <summary>
  /// Request a connection to the service. If some input is needed for the connection to succeed, an event will be raised
  /// </summary>
  /// <param name="serviceId"> Service identifier </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int connect(const std::string& serviceId);
  /// <summary>
  /// Destroy the Access Point created on a given technology
  /// </summary>
  /// <param name="technology"> The technology to disable tethering </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int disableTethering(const std::string& technology);
  /// <summary>
  /// Disconnect a service
  /// </summary>
  /// <param name="serviceId"> Service identifier </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int disconnect(const std::string& serviceId);
  /// <summary>
  /// Create a Network Access Point on a given technology and share internet connection if any
  /// </summary>
  /// <param name="technology"> Technology on which enabling tethering </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableTethering(const std::string& technology);
  /// <summary>
  /// Create a Network Access Point on a given technology and share internet connection if any
  /// </summary>
  /// <param name="technology"> The technology on which enabling tethering </param>
  /// <param name="name"> The name of the network to create </param>
  /// <param name="Passphrase"> The WPA2 passphrase to connect to the created network </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int enableTethering(const std::string& technology, const std::string& name, const std::string& Passphrase);
  /// <summary>
  /// Exits and unregisters the module.
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int exit();
  /// <summary>
  /// Forget stored information about the service
  /// </summary>
  /// <param name="serviceId"> Service identifier </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int forget(const std::string& serviceId);
  /// <summary>
  /// scan all available services on registered technologies
  /// </summary>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int scan();
  /// <summary>
  /// scan for available services on a given technology
  /// </summary>
  /// <param name="technology"> The type of technology to scan </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int scan(const std::string& technology);
  /// <summary>
  /// Set the service configuration
  /// </summary>
  /// <param name="service"> The service to configure </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setServiceConfiguration(const AL::ALValue& service);
  /// <summary>
  /// provide input for pending connection
  /// </summary>
  /// <param name="reply"> The required input requested by the connection manager to finalize the pending connection </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int setServiceInput(const AL::ALValue& reply);
  /// <summary>
  /// returns true if the method is currently running
  /// </summary>
  /// <param name="id"> the ID of the method to wait for </param>
  /// <returns> brokerTaskID : The ID of the task assigned to it by the broker.</returns>
  int stop(const int& id);
};

}
#endif // ALCONNECTIONMANAGERPROXYPOSTHANDLER_H_

