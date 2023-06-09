/*
 * laplacian-test
 * laplacian-test.cpp
 *
 * Matthew Geiger
 *
 * By calculating the variation of an image with an applied laplacian filter
 * you can calculate how blurry an image is.
 */

#include "laplacian.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>

#define FATAL(x, ...) do { fprintf(stderr, x "\n", ##__VA_ARGS__); exit(EXIT_FAILURE); } while(0)

void usage(const char *arg0) {
	std::cout << "USAGE: " << arg0 << " [IMG_PATH]" << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	std::cout << "Laplacian score tester" << std::endl;

	if(argc != 2)
		usage(argv[0]);

	std::string imgfile(argv[1]);

	// Load image into memory
	cv::Mat img(cv::imread(imgfile, cv::IMREAD_GRAYSCALE));
	if(img.empty())
		FATAL("Failed to load image");

	// Record time before function call
	auto profile_start = std::chrono::steady_clock::now();

	// Calculate blur score	
	double score = laplacian::CalculateBlur(img);	
	
	// Calculate function runtime
	auto profile_end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_time = profile_end-profile_start;

	// Output results
	std::cout << "Image score: " << score << std::endl;
	std::cout << "Elapsed time: " << elapsed_time.count() << std::endl;

	return EXIT_SUCCESS;
}
