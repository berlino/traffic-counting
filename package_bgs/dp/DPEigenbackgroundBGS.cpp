#include "DPEigenbackgroundBGS.h"

DPEigenbackgroundBGS::DPEigenbackgroundBGS() : firstTime(true), frameNumber(0), showOutput(true), threshold(225), historySize(20), embeddedDim(10)
{
  std::cout << "DPEigenbackgroundBGS()" << std::endl;
}

DPEigenbackgroundBGS::~DPEigenbackgroundBGS()
{
  std::cout << "~DPEigenbackgroundBGS()" << std::endl;
}

void DPEigenbackgroundBGS::process(const cv::Mat &img_input, cv::Mat &img_output)
{
  if(img_input.empty())
    return;

  loadConfig();

  if(firstTime)
    saveConfig();

  frame = new IplImage(img_input);
  
  if(firstTime)
    frame_data.ReleaseMemory(false);
  frame_data = frame;

  if(firstTime)
  {
    int width	= img_input.size().width;
    int height = img_input.size().height;

    lowThresholdMask = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    lowThresholdMask.Ptr()->origin = IPL_ORIGIN_BL;

    highThresholdMask = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    highThresholdMask.Ptr()->origin = IPL_ORIGIN_BL;

    params.SetFrameSize(width, height);
    params.LowThreshold() = threshold; //15*15;
    params.HighThreshold() = 2*params.LowThreshold();	// Note: high threshold is used by post-processing 
    //params.HistorySize() = 100;
    params.HistorySize() = historySize;
    //params.EmbeddedDim() = 20;
    params.EmbeddedDim() = embeddedDim;

    bgs.Initalize(params);
    bgs.InitModel(frame_data);
  }

  bgs.Subtract(frameNumber, frame_data, lowThresholdMask, highThresholdMask);
  lowThresholdMask.Clear();
  bgs.Update(frameNumber, frame_data, lowThresholdMask);
  
  cv::Mat foreground(highThresholdMask.Ptr());

  if(showOutput)
    cv::imshow("Eigenbackground (Oliver)", foreground);

  foreground.copyTo(img_output);

  delete frame;
  firstTime = false;
  frameNumber++;
}

void DPEigenbackgroundBGS::saveConfig()
{
  CvFileStorage* fs = cvOpenFileStorage("./config/DPEigenbackgroundBGS.xml", 0, CV_STORAGE_WRITE);

  cvWriteInt(fs, "threshold", threshold);
  cvWriteInt(fs, "historySize", historySize);
  cvWriteInt(fs, "embeddedDim", embeddedDim);
  cvWriteInt(fs, "showOutput", showOutput);

  cvReleaseFileStorage(&fs);
}

void DPEigenbackgroundBGS::loadConfig()
{
  CvFileStorage* fs = cvOpenFileStorage("./config/DPEigenbackgroundBGS.xml", 0, CV_STORAGE_READ);
  
  threshold = cvReadIntByName(fs, 0, "threshold", 225);
  historySize = cvReadIntByName(fs, 0, "historySize", 20);
  embeddedDim = cvReadIntByName(fs, 0, "embeddedDim", 10);
  showOutput = cvReadIntByName(fs, 0, "showOutput", true);

  cvReleaseFileStorage(&fs);
}