#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <drawing.h>

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: draw.out <Image_Path>\n");
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
    auto draw_ops = Drawing();
    
    
    //Some consts for drawing
    const cv::Point pt1(0, 0);
    const cv::Point pt2(100, 100);
    const cv::Point pt3(200, 200);
    const cv::Point pt4(0, 100);    
    const cv::Point pt5(100, 0);    
    
    const cv::Scalar color1(0, 255, 127); 
    const cv::Scalar color2(255, 127, 127); 
    const cv::Scalar color3(255, 50, 50); 
    const cv::Scalar color4(0, 255, 50); 
    const cv::Scalar color5(127, 127, 255); 
    
    const cv::Size axes(16, 26);
    
    const int line_type = 4;
    const int thickness = 5;
    const double angle = 45.0;
    const int radius = 20;
    const int marker_type = cv::MARKER_CROSS;
    const int marker_size = 10;
    

    draw_ops.drawRectangle(image, pt1, pt2, color1, -1, line_type);
    draw_ops.drawLine(image, pt2, pt3, color2, thickness, line_type);
    draw_ops.drawEllipse(image, pt2, axes, angle, color3, -1, line_type); 
    draw_ops.drawCircle(image, pt4, radius, color4, -1, line_type); 
    draw_ops.addMarker(image, pt5, color5, marker_type, marker_size, thickness, line_type); 

    
    cv::imwrite("drawn-on_image.jpg", image);

    return 0; 	
}	
