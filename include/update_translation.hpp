#ifndef UPDATE_TRANSLATION_H
#define UPDATE_TRANSLATION_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

void update_map_translation_x(cv::Mat map_x, cv::Mat map_y, int px);

void update_map_translation_y(cv::Mat map_x, cv::Mat map_y, int py);

void update_map_translation_xy(cv::Mat map_x, cv::Mat map_y, int px, int py);

#endif
