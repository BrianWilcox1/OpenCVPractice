#include <image_operations.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: sobel.out <Image_Path>\n");
    return -1;
  }
  cv::Mat image;
  image = cv::imread(argv[1], 1);
  // check for null pointer in data implying invalid file path
  if (!image.data) {
    printf("No image data \n");
    return -1;
  }

  cv::Mat sobel;
  cv::Mat normalized_sobel;

  auto img_ops = ImageOperations();
  sobel = img_ops.sobel(image, cv::COLOR_BGR2GRAY, 1, 1);
  normalized_sobel = img_ops.normalizeToGrayscale(sobel);

  cv::imwrite("sobel_image.jpg", normalized_sobel);

  return 0;
}
