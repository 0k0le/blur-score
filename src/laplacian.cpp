/*
 *
 *
 */

#include "laplacian.hpp"

#include <opencv2/highgui.hpp>

namespace laplacian {
	double CalculateBlur(cv::Mat &img) {
		cv::Mat dst;
		double score = 0.0;
		double mean = 0.0;

		if(img.depth() != CV_8U) {
			return 0; // TODO: replace with exception
		}

		// Calculate the laplacian		
		cv::Laplacian(img, dst, img.depth());
		
		cv::imshow(std::string("Laplacian"), dst);
		cv::waitKey(0);
		cv::destroyAllWindows();

		// Determine the mean
		mean = CalculateMean(dst);

		// Determine the variance
		score = CalculateVariance(dst, mean);

		return score;
	}

	double CalculateMean(cv::Mat &img) {
		double mean = 0.0;
		int temp = 0;
		auto imgsize = img.size();

		// Calculate mean	
		for(int i = 0; i < imgsize.height; i++) {
			const unsigned char *row = img.ptr(i);

			for(int j = 0; j < imgsize.width; j++) {
				temp += row[j];
			}	
		}

		mean = static_cast<double>(temp) / (imgsize.height * imgsize.width);

		return mean;
	}

	double CalculateVariance(cv::Mat &img, double mean) {
		double variance = static_cast<double>(img.ptr(0)[0]);
		auto imgsize = img.size();
		double imgsizebytes = static_cast<double>(imgsize.width * imgsize.height);

		// Calculate variance
		for(int i = 0; i < imgsize.height; i++) {
			const unsigned char *row = img.ptr(i);

			for(int j = 0; j < imgsize.width-1; j++) {
				double temp = static_cast<double>(row[j+1]);	
				variance += ((temp - mean)*(temp - mean) / (imgsizebytes - 1.0));
			}
		}

		return variance;	
	}
}


