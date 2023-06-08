/*
 *
 *
 *
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

	cv::Mat img(cv::imread(std::string(argv[1]), cv::IMREAD_GRAYSCALE));
	if(img.empty())
		FATAL("Failed to load image");

	double score = laplacian::CalculateBlur(img);	

	std::cout << "Image score: " << score << std::endl;

	return EXIT_SUCCESS;
}
