#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <morphology.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: blackhat.out <Image_Path>\n");
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	// check for null pointer in data implying invalid file path	
	if (!image.data){
		printf("No image data \n");
		return -1;
	}
	
    
    // Initialize Class
    auto morph_ops = Morphology();
    

    //Set up variables
    int dilation_type;
    int erosion_type;
    dilation_type = erosion_type = cv::MORPH_RECT;
    int dilation_size;
    int erosion_size;
    dilation_size=erosion_size = 3;

    auto dilated_output = morph_ops.dilation(image, dilation_type, dilation_size);
    auto closed_output = morph_ops.erosion(dilated_output, erosion_type, erosion_size); 
    cv::Mat res;
    cv::subtract(closed_output, image, res);

    cv::imwrite("blackhat_image.jpg", res);
    
    return 0; 	
}	
