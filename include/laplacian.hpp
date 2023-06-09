/*
 * laplacian.hpp
 *
 * Laplacian helper functions
 */

#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

namespace laplacian {
	double CalculateBlur(cv::Mat &img);
	double CalculateMean(cv::Mat &img);
	double CalculateVariance(cv::Mat &img, double mean);
}
