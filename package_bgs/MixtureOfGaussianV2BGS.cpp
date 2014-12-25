#include "MixtureOfGaussianV2BGS.h"

MixtureOfGaussianV2BGS::MixtureOfGaussianV2BGS() : firstTime(true), alpha(0.05), enableThreshold(true), threshold(15), showOutput(true)
{
  std::cout << "MixtureOfGaussianV2BGS()" << std::endl;
}

MixtureOfGaussianV2BGS::~MixtureOfGaussianV2BGS()
{
  std::cout << "~MixtureOfGaussianV2BGS()" << std::endl;
}

void MixtureOfGaussianV2BGS::process(const cv::Mat &img_input, cv::Mat &img_output)
{
  if(img_input.empty())
    return;

  loadConfig();

  if(firstTime)
    saveConfig();

  //------------------------------------------------------------------
  // BackgroundSubtractorMOG2
  // http://opencv.itseez.com/modules/video/doc/motion_analysis_and_object_tracking.html#backgroundsubtractormog2
  //
  // Gaussian Mixture-based Backbround/Foreground Segmentation Algorithm.
  //
  // The class implements the Gaussian mixture model background subtraction described in:
  //  (1) Z.Zivkovic, Improved adaptive Gausian mixture model for background subtraction, International Conference Pattern Recognition, UK, August, 2004, 
  //  The code is very fast and performs also shadow detection. Number of Gausssian components is adapted per pixel.
  //
  //  (2) Z.Zivkovic, F. van der Heijden, Efficient Adaptive Density Estimation per Image Pixel for the Task of Background Subtraction, 
  //  Pattern Recognition Letters, vol. 27, no. 7, pages 773-780, 2006. 
  //  The algorithm similar to the standard Stauffer&Grimson algorithm with additional selection of the number of the Gaussian components based on: 
  //    Z.Zivkovic, F.van der Heijden, Recursive unsupervised learning of finite mixture models, IEEE Trans. on Pattern Analysis and Machine Intelligence, 
  //    vol.26, no.5, pages 651-656, 2004.
  //------------------------------------------------------------------

  mog(img_input, img_foreground, alpha);

  if(enableThreshold)
    cv::threshold(img_foreground, img_foreground, threshold, 255, cv::THRESH_BINARY);

  if(showOutput)
    cv::imshow("Gaussian Mixture Model (Zivkovic&Heijden)", img_foreground);

  img_foreground.copyTo(img_output);

  firstTime = false;
}

void MixtureOfGaussianV2BGS::saveConfig()
{
  CvFileStorage* fs = cvOpenFileStorage("./config/MixtureOfGaussianV2BGS.xml", 0, CV_STORAGE_WRITE);

  cvWriteReal(fs, "alpha", alpha);
  cvWriteInt(fs, "enableThreshold", enableThreshold);
  cvWriteInt(fs, "threshold", threshold);
  cvWriteInt(fs, "showOutput", showOutput);

  cvReleaseFileStorage(&fs);
}

void MixtureOfGaussianV2BGS::loadConfig()
{
  CvFileStorage* fs = cvOpenFileStorage("./config/MixtureOfGaussianV2BGS.xml", 0, CV_STORAGE_READ);
  
  alpha = cvReadRealByName(fs, 0, "alpha", 0.05);
  enableThreshold = cvReadIntByName(fs, 0, "enableThreshold", true);
  threshold = cvReadIntByName(fs, 0, "threshold", 15);
  showOutput = cvReadIntByName(fs, 0, "showOutput", true);

  cvReleaseFileStorage(&fs);
}
