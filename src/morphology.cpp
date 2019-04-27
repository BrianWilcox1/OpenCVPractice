#include <morphology.h>

cv::Mat Morphology::dilation(const cv::Mat& image, const int dilation_type, const int dilation_size){
    cv::Mat struct_el = cv::getStructuringElement(dilation_type, cv::Size(2*dilation_size + 1, 2*dilation_size + 1),
                                            cv::Point(dilation_size, dilation_size));
    cv::Mat dilation_out;
    cv::dilate(image, dilation_out, struct_el);
    return dilation_out;   
}
cv::Mat Morphology::erosion(const cv::Mat& image, const int erosion_type, const int erosion_size){
    cv::Mat struct_el = cv::getStructuringElement(erosion_type, cv::Size(2*erosion_size + 1, 2*erosion_size + 1),
                                            cv::Point(erosion_size, erosion_size));    
    cv::Mat erosion_out;
    cv::erode(image, erosion_out, struct_el);
    return erosion_out;   
}
