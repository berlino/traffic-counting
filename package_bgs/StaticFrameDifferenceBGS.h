#pragma once

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "IBGS.h"

class StaticFrameDifferenceBGS : public IBGS
{
private:
  bool firstTime;
  cv::Mat img_background;
  cv::Mat img_foreground;
  bool enableThreshold;
  int threshold;
  bool showOutput;

public:
  StaticFrameDifferenceBGS();
  ~StaticFrameDifferenceBGS();

  void process(const cv::Mat &img_input, cv::Mat &img_output);

private:
  void saveConfig();
  void loadConfig();
};

