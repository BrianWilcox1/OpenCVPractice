#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <image_operations.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: dft.out <Image_Path>\n");
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	// check for null pointer in data implying invalid file path	
	if (!image.data){
		printf("No image data \n");
		return -1;
	}

    auto img_ops = ImageOperations();
    auto fourier_output = img_ops.discreteFT(image, cv::COLOR_BGR2GRAY);
    

	cv::imwrite("dft_image.jpg", fourier_output);
	
    return 0; 	
}	
