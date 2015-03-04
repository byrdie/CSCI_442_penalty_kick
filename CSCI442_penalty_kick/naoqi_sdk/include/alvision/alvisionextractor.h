/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2011, 2012 All Rights Reserved
 */


#ifndef ALVISIONEXTRACTOR_H
#define ALVISIONEXTRACTOR_H

#include <alvision/alvisiondefinitions.h>
#include <alvision/alimage.h>
#include <alcommon/albroker.h>
#include <alextractor/alextractor.h>
#include <qi/macro.hpp>

namespace AL {

class ALValue;
class ALVisionExtractorPrivate;

/**
  * \class ALVisionExtractor alvisionextractor.h <alvision/alvisionextractor.h>
  * \brief ALVisionExtractor is a generic vision extractor.
  *
  * ALVisionExtractor is an extractor dedicated to vision processing. It
  * retrieves images from one of NAO's cameras, and gives them as input to a
  * callback method process(). This method will be called each time an image is
  * retrieved.
  *
  * The parameters concerning the image retrieval (resolution, colorspace, camera
  * and framerate) can be set either at the construction (which is recommended) if
  * you do not have to change them, or on the fly using dedicated method.
  *
  */

class ALVisionExtractor : public ALExtractor {

public:
  /**
    * \brief Create a generic vision extractor.
    * \param resolution Resolution of the images the extractor will process at
    *        module startup. Default value is 1 (QVGA resolution).
    * \param colorspace Colorspace of the images the extractor will process at
    *        module startup. Default value is BGR colorspace.
    * \param framerate Framerate of the images the extractor will process at
    *        module startup. Default value is 30.
    */
  ALVisionExtractor(boost::shared_ptr<ALBroker> pBroker,
                    const std::string& pName,
                    int resolution=kQVGA, int colorspace=kBGRColorSpace,
                    int framerate=30);

  virtual ~ALVisionExtractor();

  /**
    * \brief Sets processed image colorspace on the fly.
    * \param colorspace Desired colorspace.
    * \return True if the colorspace has been successfully set.
    */
  bool setColorSpace(const int& colorSpace);

  /**
    * \brief Sets extractor framerate on the fly.
    * \param framerate Desired extractor framerate.
    * \return True if the framerate has been successfully set.
    */
  bool setFrameRate(const int& framerate);

  /**
  * \brief Sets processed image resolution on the fly.
  * \param resolution Desired resolution.
  * \return True if the resolution has been successfully set.
  */
  bool setResolution(const int& resolution);

  /**
  * \brief Sets the camera from which the image is taken.
  * \param resolution Desired camera ID.
  * \return True if the camera has been successfully set.
  */
  bool setActiveCamera(const int& cameraId);


  int getColorSpace();

  int getFrameRate();

  int getResolution();

  int getActiveCamera();

  bool isPaused();
  bool isProcessing();


  /**
    * \brief Set parameter value for resolution and pause.
    * \param paramName Name of the parameter to set ("resolution" or "pause")
    * \param paramValue ALValue array of the value to be set.
    * \deprecated Use setResolution or pause instead.
    */
  QI_API_DEPRECATED void setParameter(const std::string& paramName,
                                      const ALValue& paramValue);

  /**
    * \brief Method which will be called before each subscription to the extractor.
    */
  virtual void start() = 0;

  /**
    * \brief Method which will be called each time the extractor gets an image.
    * \param img Pointer to the image class, which is retrieved according to the
    *        extractor parameters (colorspace, framerate, resolution, camera).
    */
  virtual void process(ALImage* img) = 0;

  /**
    * \brief Pause the extractor, without calling the stop method.
    * \param paused true if the extractor must be paused, false else.
    */
  void pause(const bool& paused);

  /**
    * \brief Method which will be called when the module is unsubscribed.
    */
  virtual void stop() = 0;


private:

  //intentionnally undefined.
  ALVisionExtractor(const ALVisionExtractor& extractor);
  //intentionnally undefined.
  ALVisionExtractor& operator =(const ALVisionExtractor& extractor);

  void xStartDetection(const int pPeriod, const float pPrecision);
  void xStopDetection();
  void xUpdateParameters(const int pPeriod, const float pPrecision);

  void xRun();

  ALVisionExtractorPrivate* _pImpl;

};

} // namespace AL.

#endif // ALVISIONEXTRACTOR_H
