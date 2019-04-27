#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <filtering.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: filters.out <Image_Path>\n");
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	// check for null pointer in data implying invalid file path	
	if (!image.data){
		printf("No image data \n");
		return -1;
	}

    //Call Filters Class
    Filters filter_ops = Filters();

    cv::Mat sharpened_out = filter_ops.sharpen(image);


    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0
                                             -1, 5, -1,
                                              0, -1, 0);
    cv::Mat conv_out = filter_ops.conv2D(image, kernel);
	cv::imwrite("sharpened_image.jpg", sharpened_out);
	cv::imwrite("convolved_image.jpg", conv_out);

	return 0; 	
}	
