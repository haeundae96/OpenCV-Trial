#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;



int main(void) {
    Mat image = imread("/Users/mr.y/Desktop/biltest.png", IMREAD_GRAYSCALE);
    Mat RecTable(image.size(), CV_32F);

    const int r = image.rows;
    const int p = image.cols;
    const int q = 15;

    for (int i = 0; i < image.rows; ++i){
        for (int j = 0; j < image.cols; ++j) {
            // for Point(i, j) to make Point(x,y)
            int x = r * i / (p - 2 * q * (r - j)) - q * (r - j) / (p * r - 2 * q * (r - j));
            int y = j;
            if (x < 0 || x > image.rows) continue;
            RecTable.at<float>(x, y) = image.at<float>(i, j);

        }
    }

    imshow("Original Image", image);
    imshow("Convoluted", RecTable);


    waitKey(0);
    return 0;

}