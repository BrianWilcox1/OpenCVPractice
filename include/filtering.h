#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
class Filters {
public:
  cv::Mat sharpen(const cv::Mat &image);
  cv::Mat conv2D(const cv::Mat &image, const cv::Mat &kernel);
};
