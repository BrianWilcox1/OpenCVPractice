#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <image_operations.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: grayscale.out <Image_Path>\n");
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	// check for null pointer in data implying invalid file path	
	if (!image.data){
		printf("No image data \n");
		return -1;
	}
    auto image_ops = ImageOperations();
    auto gray = image_ops.grayscale(image, cv::COLOR_BGR2GRAY);

	cv::imwrite("grayscale_image.jpg", gray);
	cv::waitKey(0);

	return 0; 	
}	
