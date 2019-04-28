#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

class Morphology{
    public:
        cv::Mat dilation(const cv::Mat& image, const int dilation_type, const int dilation_size);
	cv::Mat erosion(const cv::Mat& image, const int erosion_type, const int erosion_size);
        cv::Mat morphologyAdvanced(const cv::Mat& image, const int morph_elem, 
                                   const int operation, const int size);
};
