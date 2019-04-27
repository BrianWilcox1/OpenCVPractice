#include <image_operations.h>

cv::Mat ImageOperations::grayscale(const cv::Mat& image, const int conversion_type){
   cv::Mat res;
   cv::cvtColor(image, res, conversion_type);
   return res;
}
