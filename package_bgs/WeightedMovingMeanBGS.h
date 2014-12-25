#pragma once

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "IBGS.h"

class WeightedMovingMeanBGS : public IBGS
{
private:
  bool firstTime;
  cv::Mat img_input_prev_1;
  cv::Mat img_input_prev_2;
  bool enableWeight;
  bool enableThreshold;
  int threshold;
  bool showOutput;
  bool showBackground;

public:
  WeightedMovingMeanBGS();
  ~WeightedMovingMeanBGS();

  void process(const cv::Mat &img_input, cv::Mat &img_output);

private:
  void saveConfig();
  void loadConfig();
};

