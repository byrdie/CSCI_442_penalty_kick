// Generated for ALConnectionManager version 1.14

#ifndef ALCONNECTIONMANAGERPROXYREMOTE_H_
#define ALCONNECTIONMANAGERPROXYREMOTE_H_
#include <alremoteproxies/alconnectionmanagerproxyposthandlerremote.h>

namespace AL
{

/// <summary>This module is used to manage available connections</summary>
class ALConnectionManagerProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALConnectionManagerProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALConnectionManager", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALConnectionManagerProxyPostHandlerRemote post;


    /// <summary>
    /// Request a connection to the service. If some input is needed for the connection to succeed, an event will be raised
    /// </summary>
    /// <param name="serviceId"> Service identifier </param>
    void connect(const std::string& serviceId)
    {

        callVoidRemote("connect" , serviceId);
    }


    /// <summary>
    /// Destroy the Access Point created on a given technology
    /// </summary>
    /// <param name="technology"> The technology to disable tethering </param>
    void disableTethering(const std::string& technology)
    {

        callVoidRemote("disableTethering" , technology);
    }


    /// <summary>
    /// Disconnect a service
    /// </summary>
    /// <param name="serviceId"> Service identifier </param>
    void disconnect(const std::string& serviceId)
    {

        callVoidRemote("disconnect" , serviceId);
    }


    /// <summary>
    /// Create a Network Access Point on a given technology and share internet connection if any
    /// </summary>
    /// <param name="technology"> Technology on which enabling tethering </param>
    void enableTethering(const std::string& technology)
    {

        callVoidRemote("enableTethering" , technology);
    }


    /// <summary>
    /// Create a Network Access Point on a given technology and share internet connection if any
    /// </summary>
    /// <param name="technology"> The technology on which enabling tethering </param>
    /// <param name="name"> The name of the network to create </param>
    /// <param name="Passphrase"> The WPA2 passphrase to connect to the created network </param>
    void enableTethering(const std::string& technology, const std::string& name, const std::string& Passphrase)
    {

        callVoidRemote("enableTethering" , technology, name, Passphrase);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Forget stored information about the service
    /// </summary>
    /// <param name="serviceId"> Service identifier </param>
    void forget(const std::string& serviceId)
    {

        callVoidRemote("forget" , serviceId);
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="technology"> The technology </param>
    /// <returns> Return whether tethering mode is enabled for the given technology. </returns>
    bool getTetheringEnable(const std::string& technology)
    {

        return callRemote<bool >("getTetheringEnable" , technology);
    }


    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// scan all available services on registered technologies
    /// </summary>
    void scan()
    {

        callVoidRemote("scan");
    }


    /// <summary>
    /// scan for available services on a given technology
    /// </summary>
    /// <param name="technology"> The type of technology to scan </param>
    void scan(const std::string& technology)
    {

        callVoidRemote("scan" , technology);
    }


    /// <summary>
    /// Return the service properties
    /// </summary>
    /// <param name="serviceId"> Service identifier </param>
    /// <returns> Return the service properties </returns>
    AL::ALValue service(const std::string& serviceId)
    {

        return callRemote<AL::ALValue >("service" , serviceId);
    }


    /// <summary>
    /// Return the list of all network services with their properties
    /// </summary>
    /// <returns> An array of NetworkInfo </returns>
    AL::ALValue services()
    {

        return callRemote<AL::ALValue >("services");
    }


    /// <summary>
    /// Set the service configuration
    /// </summary>
    /// <param name="service"> The service to configure </param>
    void setServiceConfiguration(const AL::ALValue& service)
    {

        callVoidRemote("setServiceConfiguration" , service);
    }


    /// <summary>
    /// provide input for pending connection
    /// </summary>
    /// <param name="reply"> The required input requested by the connection manager to finalize the pending connection </param>
    void setServiceInput(const AL::ALValue& reply)
    {

        callVoidRemote("setServiceInput" , reply);
    }


    /// <summary>
    /// Return the current global state of the connection manager
    /// </summary>
    /// <returns> A string containing the current state </returns>
    std::string state()
    {

        return callRemote<std::string >("state");
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// return the list of all available technologies
    /// </summary>
    /// <returns> An AL::Value containing an array of string </returns>
    AL::ALValue technologies()
    {

        return callRemote<AL::ALValue >("technologies");
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="technology"> The technology </param>
    /// <returns> The name of the network used by the tethering mode </returns>
    std::string tetheringName(const std::string& technology)
    {

        return callRemote<std::string >("tetheringName" , technology);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="technology"> The technology </param>
    /// <returns> The passphrase of the network used by the tethering mode </returns>
    std::string tetheringPassphrase(const std::string& technology)
    {

        return callRemote<std::string >("tetheringPassphrase" , technology);
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALCONNECTIONMANAGERPROXY_H_
