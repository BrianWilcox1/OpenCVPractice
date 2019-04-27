#include <image_operations.h>

cv::Mat ImageOperations::grayscale(const cv::Mat& image, const int conversion_type){
   cv::Mat res;
   cv::cvtColor(image, res, conversion_type);
   return res;
}

cv::Mat ImageOperations::sobel(const cv::Mat& image, const int conv_type, const int dx, const int dy){
    cv::Mat gray, res;
    gray = grayscale(image, conv_type);
    cv::Sobel(gray, res, CV_32F, dx, dy);
    return res;
}
        
cv::Mat ImageOperations::normalizeToGrayscale(const cv::Mat& image){
    cv::Mat res;
    double minVal, maxVal;
    cv::minMaxLoc(image, &minVal, &maxVal);
    auto scale = 255.0f/(maxVal-minVal);
    image.convertTo(res, CV_8U, scale, -minVal*scale);
    return res;
}
