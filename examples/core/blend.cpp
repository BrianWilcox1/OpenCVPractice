#include <image_operations.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: blend.out <Image_1>  <Image_2> \n");
    return -1;
  }
  cv::Mat image1, image2;
  image1 = cv::imread(argv[1], 1);
  image2 = cv::imread(argv[2], 1);
  // check for null pointer in data implying invalid file path
  if (!image1.data || !image2.data) {
    printf("No image data \n");
    return -1;
  }
  auto image_ops = ImageOperations();
  double alpha = 0.5;

  auto blended = image_ops.blendImages(image1, image2, alpha);

  cv::imwrite("blended_image.jpg", blended);
  cv::waitKey(0);

  return 0;
}
