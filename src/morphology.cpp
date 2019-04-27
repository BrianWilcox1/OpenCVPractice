#include <morphology.h>

cv::Mat Morphology::dilation(const cv::Mat& image, const int dilation_type, const int dilation_size){
    cv::Mat struct_el = cv::getStructuringElement(dilation_type, 
                                           cv::Size(2*dilation_size + 1, 2*dilation_size + 1),
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

cv::Mat morphologyAdvanced(const cv::Mat& image, const int morph_elem, const int operation, const int size){
    cv::Mat struct_el = cv::getStructuringElement(morph_elem, cv::Size(2*size + 1, 2*size + 1), cv::Point(size, size));    
    cv::Mat morph_out;
    cv::morphologyEx(image, morph_out, operation, struct_el);
    return morph_out;
}
