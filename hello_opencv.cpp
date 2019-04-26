#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: hello_opencv.out <Image_Path>\n");
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	// check for null pointer in data implying invalid file path	
	if (!image.data){
		printf("No image data \n");
		return -1;
	}

	cv::namedWindow("Test Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Test Image", image);

	cv::waitKey(0);

	return 0; 	
}	
