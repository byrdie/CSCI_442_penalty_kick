// Generated for ALVisualCompass version 1.14

#ifndef ALVISUALCOMPASSPROXY_H_
#define ALVISUALCOMPASSPROXY_H_
#include <alproxies/alvisualcompassproxyposthandler.h>

#include <alproxies/api.h>



namespace AL
{
class ALBroker;
class ALProxy;

class ALVisualCompassProxyImpl;

/// <summary></summary>
/// \ingroup ALProxies
class ALPROXIES_API ALVisualCompassProxy
{
  private:
    boost::shared_ptr<ALVisualCompassProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALVisualCompassProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALVisualCompassProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Explicit Proxy Constructor. Create a specialised proxy from a generic proxy.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALVisualCompassProxy(boost::shared_ptr<ALProxy> proxy);


    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALVisualCompassProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALVisualCompassProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// 
    /// </summary>
    /// <param name="refresh"> True if the reference is automatically refreshed at extractor startup; false to use the manually set reference image. </param>
    void enableReferenceRefresh(const bool& refresh);

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// Gets extractor active camera
    /// </summary>
    /// <returns> Id of the current active camera of the extractor </returns>
    int getActiveCamera();

    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

    /// <summary>
    /// Returns an ALValue containing the current image used to compute the deviation.
    /// </summary>
    /// <returns> Current image (formatted as the ALValue from getImageRemote of ALVideoDevice) </returns>
    AL::ALValue getCurrentImage();

    /// <summary>
    /// Gets the current period.
    /// </summary>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getCurrentPeriod();

    /// <summary>
    /// Gets the current precision.
    /// </summary>
    /// <returns> Precision of the extractor. </returns>
    float getCurrentPrecision();

    /// <summary>
    /// Gets extractor framerate
    /// </summary>
    /// <returns> Current value of the framerate of the extractor </returns>
    int getFrameRate();

    /// <summary>
    /// Returns the reliability of the matching and the compass deviation computations.
    /// </summary>
    /// <returns> [0]: Percentage of the matched keypoints that are used to compute the deviation (significant if over 50%) 
    ///
    ///  [1]: Number of keypoints matching. </returns>
    AL::ALValue getMatchingQuality();

    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName);

    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList();

    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp();

    /// <summary>
    /// Gets the period for a specific subscription.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getMyPeriod(const std::string& name);

    /// <summary>
    /// Gets the precision for a specific subscription.
    /// </summary>
    /// <param name="name"> name of the module which has subscribed </param>
    /// <returns> precision of the extractor </returns>
    float getMyPrecision(const std::string& name);

    /// <summary>
    /// Get the list of values updated in ALMemory.
    /// </summary>
    /// <returns> Array of values updated by this extractor in ALMemory </returns>
    std::vector<std::string> getOutputNames();

    /// <summary>
    /// Returns an ALValue containing the image used as a reference.
    /// </summary>
    /// <returns> Reference image (formatted as the ALValue from getImageRemote of ALVideoDevice) </returns>
    AL::ALValue getReferenceImage();

    /// <summary>
    /// Returns the number of reference keypoints.
    /// </summary>
    /// <returns> Number of reference keypoints. </returns>
    int getReferenceQuality();

    /// <summary>
    /// Gets extractor resolution
    /// </summary>
    /// <returns> Current value of the resolution of the extractor </returns>
    int getResolution();

    /// <summary>
    /// Gets the parameters given by the module.
    /// </summary>
    /// <returns> Array of names and parameters of all subscribers. </returns>
    AL::ALValue getSubscribersInfo();

    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name);

    /// <summary>
    /// Gets extractor pause status
    /// </summary>
    /// <returns> True if the extractor is paused, False if not </returns>
    bool isPaused();

    /// <summary>
    /// Gets extractor running status
    /// </summary>
    /// <returns> True if the extractor is currently processing images, False if not </returns>
    bool isProcessing();

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// Changes the pause status of the extractor
    /// </summary>
    /// <param name="paused"> New pause satus </param>
    void pause(const bool& paused);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Sets extractor active camera
    /// </summary>
    /// <param name="cameraId"> Id of the camera that will become the active camera </param>
    /// <returns> True if the update succeeded, False if not </returns>
    bool setActiveCamera(const int& cameraId);

    /// <summary>
    /// Sets extractor framerate
    /// </summary>
    /// <param name="framerate"> New framerate </param>
    /// <returns> True if the update succeeded, False if not </returns>
    bool setFrameRate(const int& framerate);

    /// <summary>
    /// DEPRECATED: Sets pause and resolution
    /// </summary>
    /// <param name="paramName"> Name of the parameter to set </param>
    /// <param name="value"> New value </param>
    void setParameter(const std::string& paramName, const AL::ALValue& value);

    /// <summary>
    /// Sets the reference image for the compass.
    /// </summary>
    /// <returns> True if the reference image has been successfully set </returns>
    bool setReferenceImage();

    /// <summary>
    /// Sets extractor resolution
    /// </summary>
    /// <param name="resolution"> New resolution </param>
    /// <returns> True if the update succeeded, False if not </returns>
    bool setResolution(const int& resolution);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    void subscribe(const std::string& name, const int& period, const float& precision);

    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    void subscribe(const std::string& name);

    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    void unsubscribe(const std::string& name);

    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    void updatePeriod(const std::string& name, const int& period);

    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    void updatePrecision(const std::string& name, const float& precision);

    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version();

    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod);

};

}
#endif // ALVISUALCOMPASSPROXY_H_

