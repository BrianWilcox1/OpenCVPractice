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

cv::Mat ImageOperations::blendImages(const cv::Mat& image1, const cv::Mat& image2, const double alpha){
    cv::Mat res;
    cv::addWeighted(image1, alpha, image2, (1.0-alpha), 0.0, res);
    return res;
}

cv::Mat ImageOperations::discreteFT(const cv::Mat& image, const int conv_type){
    cv::Mat gray = grayscale(image, conv_type);    
    auto m = cv::getOptimalDFTSize(gray.rows);
    auto n = cv::getOptimalDFTSize(gray.cols);
   

    //Pad for DFT
    cv::Mat padded; 
    cv::copyMakeBorder(gray, padded, 0, m-gray.rows, 0, n-gray.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
    //Setup Real and IMaginary Planes for DFT
    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complex_image;
    cv::merge(planes, 2, complex_image);
    
    cv::dft(complex_image, complex_image);
    
    //Split the Complex Image into channelwise planes
    cv::split(complex_image, planes);
    
    //Get Log Magnitude
    cv::magnitude(planes[0], planes[1], planes[0]); //inplace magnitude compute
    cv::Mat mag = planes[0]; 
    mag += cv::Scalar::all(1);
    cv::log(mag, mag);
    mag = mag(cv::Rect(0, 0, mag.cols & -2, mag.rows & -2));
    
    //Index mag Mat header to get quadrants
    int cx = mag.cols/2;
    int cy = mag.rows/2;
    cv::Mat q0(mag, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(mag, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(mag, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(mag, cv::Rect(cx, cy, cx, cy));


    //temp quadrant for swaps
    cv::Mat temp;
    
    //Swap upper left and bottom right quadrants
    q0.copyTo(temp);
    q3.copyTo(q0);
    temp.copyTo(q3);
  
    //Swap upper right and bottom left quadrants
    q1.copyTo(temp);  
    q2.copyTo(q1);
    temp.copyTo(q2);
    
    cv::normalize(mag, mag, 0, 255, cv::NORM_MINMAX);
    return mag;
}
