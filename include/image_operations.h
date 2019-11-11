#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

class ImageOperations {
public:
  cv::Mat grayscale(const cv::Mat &image, const int conversion_type);
  cv::Mat sobel(const cv::Mat &image, const int conv_type, const int dx,
                const int dy);
  cv::Mat normalizeToGrayscale(const cv::Mat &image);
  cv::Mat blendImages(const cv::Mat &image1, const cv::Mat &image2,
                      const double alpha);
  cv::Mat discreteFT(const cv::Mat &image, const int conv_type);
};
