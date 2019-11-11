#include <morphology.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: gradient.out <Image_Path>\n");
    return -1;
  }
  cv::Mat image;
  image = cv::imread(argv[1], 1);
  // check for null pointer in data implying invalid file path
  if (!image.data) {
    printf("No image data \n");
    return -1;
  }

  // Initialize Class
  auto morph_ops = Morphology();

  // Set up variables
  int dilation_type;
  int erosion_type;
  dilation_type = erosion_type = cv::MORPH_RECT;
  int dilation_size;
  int erosion_size;
  dilation_size = erosion_size = 3;

  auto dilated_output = morph_ops.dilation(image, dilation_type, dilation_size);
  auto eroded_output = morph_ops.erosion(image, erosion_type, erosion_size);
  cv::Mat res;
  cv::subtract(dilated_output, eroded_output, res);

  cv::imwrite("gradient_image.jpg", res);

  return 0;
}
