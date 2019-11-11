#include <drawing.h>

void Drawing::drawLine(cv::Mat &image, const cv::Point &pt1,
                       const cv::Point &pt2, const cv::Scalar &color,
                       const int thickness, const int line_type) {
  cv::line(image, pt1, pt2, color, thickness, line_type);
}

void Drawing::drawRectangle(cv::Mat &image, const cv::Point &pt1,
                            const cv::Point &pt2, const cv::Scalar &color,
                            const int thickness, const int line_type) {
  cv::rectangle(image, pt1, pt2, color, thickness, line_type);
}

void Drawing::drawEllipse(cv::Mat &image, const cv::Point center,
                          const cv::Size axes, const double angle,
                          const cv::Scalar &color, const int thickness,
                          const int line_type) {
  cv::ellipse(image, center, axes, angle, 0, 360, color, thickness, line_type);
}

void Drawing::addMarker(cv::Mat &image, cv::Point position,
                        const cv::Scalar &color, const int marker_type,
                        const int marker_size, const int thickness,
                        const int line_type) {
  cv::drawMarker(image, position, color, marker_type, marker_size, thickness,
                 line_type);
}

void Drawing::drawCircle(cv::Mat &image, const cv::Point center,
                         const int radius, const cv::Scalar &color,
                         const int thickness, const int line_type) {
  cv::circle(image, center, radius, color, thickness, line_type);
}
