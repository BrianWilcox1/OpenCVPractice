#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

class Drawing{
    public:
        void drawLine(cv::Mat& image, const cv::Point& pt1, const cv::Point& pt2,
                      const cv::Scalar& color, const int thickness, const int line_type);
        void drawRectangle(cv::Mat& image, const cv::Point& pt1, const cv::Point& pt2,
                      const cv::Scalar& color, const int thickness, const int line_type);
        void drawEllipse(cv::Mat& image, const cv::Point center, const cv::Size axes,
                         const double angle, const cv::Scalar& color, const int thickness,
                         const int line_type);
        void addMarker(cv::Mat& image, cv::Point position, const cv::Scalar& color, 
                        const int marker_type, const int marker_size, const int thickness,
                        const int line_type);
        void drawCircle(cv::Mat& image, const cv::Point Center, const int radius,
                        const cv::Scalar& color, const int thickness, const int line_type);

};
