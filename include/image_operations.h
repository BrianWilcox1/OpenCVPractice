#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class ImageOperations{
    public:
        cv::Mat grayscale(const cv::Mat& image, const int conversion_type);
};
