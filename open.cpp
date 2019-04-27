#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <morphology.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: open.out <Image_Path>\n");
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

    auto eroded_output = morph_ops.erosion(image, erosion_type, erosion_size);
    auto opened_output = morph_ops.dilation(eroded_output, dilation_type, dilation_size); 
    
	cv::imwrite("opened_image.jpg", opened_output);

	return 0; 	
}	
