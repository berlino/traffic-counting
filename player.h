#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/StaticFrameDifferenceBGS.h"
#include "package_bgs/WeightedMovingMeanBGS.h"
#include "package_bgs/WeightedMovingVarianceBGS.h"
#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/MixtureOfGaussianV1BGS.h"
#include "package_bgs/GMG.h"
#include "package_bgs/jmo/MultiLayerBGS.h"
#include "package_bgs/pt/PixelBasedAdaptiveSegmenter.h"

#include "package_tracking/BlobTracking.h"

#include <boost/config/user.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>
#include "package_tracking/cvblob/cvblob.h"

using namespace cv;
enum LaneOrientation
{
  LO_NONE       = 0,
  LO_HORIZONTAL = 1,
  LO_VERTICAL   = 2
};

enum VehiclePosition
{
  VP_NONE = 0,
  VP_A  = 1,
  VP_B  = 2
};

class Player : public QThread
{    Q_OBJECT
 private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture *capture;
    Mat RGBframe;
    QImage img;
    BlobTracking* blobTracking;
    IBGS *bgs;

     bool firstTime;
     bool showOutput;
     int key;
     cv::Mat img_input;
     cvb::CvTracks tracks;
     std::map<cvb::CvID, std::vector<CvPoint2D64f> > points;
     LaneOrientation LaneOrientation;
     std::map<cvb::CvID, VehiclePosition> positions;
     long countAB;
     long countBA;
     int img_w;
     int img_h;
     int showAB;
     VehiclePosition getVehiclePosition(const CvPoint2D64f centroid);
      void saveConfig();
      void loadConfig();

 signals:
 //Signal to output frame to be displayed
      void processedImage(const QImage &image);

 protected:
     void run();
     void msleep(int ms);
 public:
    //Constructor
    Player(QObject *parent = 0);
    //Destructor
    ~Player();
    //Load a video from memory
    bool loadVideo(string filename);
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped
    bool isStopped() const;
    //set video properties
    void setCurrentFrame( int frameNumber);
    //Get video properties
    double getFrameRate();
    double getCurrentFrame();
    double getNumberOfFrames();

     void setInput(const cv::Mat &i);
     void setTracks(const cvb::CvTracks &t);
     void process();
      String filename;
};
#endif // VIDEOPLAYER_H
