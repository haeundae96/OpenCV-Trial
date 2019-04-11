#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;




int main(void) {
    Mat table = imread("/Users/mr.y/Desktop/biltest.png", IMREAD_COLOR);
    CV_Assert(table.data);

    vector<Mat> bgr;
    split(table, bgr);

    // test some combinations
//    imshow("table", table);
    //imshow("g - b", bgr[1] - bgr[0]);   // Yellow ball
    //imshow("r - g", bgr[2] - bgr[1]);   // Red ball
//    imshow("b - r", bgr[0] - bgr[2]);   //  better all balls detected

    //imshow("b - g", bgr[0] - bgr[1]);
    //imshow("g - r", bgr[1] - bgr[2]);   // all balls detected
    //imshow("r - b", bgr[2] - bgr[0]);

    Mat balls = bgr[0] - bgr[2];
    vector<Vec3f> circles;

    //test
    imshow("balls", balls);
    waitKey(0);

    GaussianBlur(balls, balls, Size(5, 5), 2, 2);
    threshold(balls, balls, 60, 255, THRESH_BINARY);
    // test
    imshow("balls", balls);
    waitKey(0);

    HoughCircles(balls, circles, HOUGH_GRADIENT, 2, 20, 100, 50, 5, 50); // 200, 100 couldn't understand

    for(size_t i = 0; i < circles.size(); ++i)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        circle(balls, center, radius, Scalar(0, 0, 255), 25);

        //test printing out the coordinates
        cout << "x: " << circles[i][0] << ", y: " << circles[i][1] << endl;
        cout << "radius: " << circles[i][2] << endl << endl;

    }

    imshow("balls", balls);

    waitKey(0);




    return 0;

}