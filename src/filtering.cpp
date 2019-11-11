#include <filtering.h>

cv::Mat Filters::sharpen(const cv::Mat &image) {
  CV_Assert(image.depth() == CV_8U); // unsigned char filter
  cv::Mat result;
  result.create(image.size(), image.type());
  auto kChannels = image.channels();
  for (auto j = 1; j < image.rows - 1; ++j) {
    const uchar *prior = image.ptr<uchar>(j - 1);
    const uchar *cur = image.ptr<uchar>(j);
    const uchar *next = image.ptr<uchar>(j + 1);

    auto output = result.ptr<uchar>(j);
    for (auto i = kChannels; i < kChannels * (image.cols - 1); ++i) {
      *output++ = cv::saturate_cast<uchar>(
          5 * cur[i] -
          (cur[i - kChannels] + cur[i + kChannels] + prior[i] + next[i]));
    }
  }

  result.row(0).setTo(cv::Scalar(0));
  result.row(result.rows - 1).setTo(cv::Scalar(0));
  result.col(0).setTo(cv::Scalar(0));
  result.col(result.cols - 1).setTo(cv::Scalar(0));
  return result;
}

cv::Mat Filters::conv2D(const cv::Mat &image, const cv::Mat &kernel) {
  cv::Mat result;
  filter2D(image, result, image.depth(), kernel);
  return result;
}
