#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
// keep containing 5 elements in picked container.
// last modified 14 Apr 19


// 마우스로 네 점 입력 -> 사다리꼴 roi 생성, mask
    // 윈도우를 띄워두고 MouseCallback 실행, 네 점 추출. 선책시 색칠
    // 네 개가 모이면 마스크 생성 후 마스크를 리턴
// 이 부분 내부에서만 당구 공 색상별로 추출
// 수식 변환해서 당구 테이블로 만들고, 출력
// 동영상 전체에 적용

// container for four edgings
vector<Point> picked;

// function that chose four points by setMouseCallback
// starts from showing the image, ending with closing the window
void pick4(const Mat &table, MouseCallback trapezoid)
{
    vector<Point> picked;

    namedWindow("table", WINDOW_AUTOSIZE);
    setMouseCallback("table", trapezoid, &picked);
    imshow("table", table);

    waitKey(0);

}
void trapezoid(int, int, int, int, void *);

int main(void) {

    // call table image
    Mat table = imread("/Users/mr.y/Desktop/biltest.png");
    CV_Assert(table.data);

    // pick four points
    picked.clear();
    pick4(table, trapezoid);

    // create trapezoid shaped mask
    Mat mask(table.size(), CV_8U, Scalar(0));

    // test confirm picked points
    cout << picked.size() << endl;
    for(int i = 0; i < picked.size(); ++i)
    {
        cout << "[" + i << "번째]" << picked[i] << endl;
    }


    return 0;

}


// onMouse function
void trapezoid(int event, int x, int y, int flags, void *)
{


    if(event == EVENT_LBUTTONDOWN &  picked.size() <= 4)
    {
        Point pt(cvRound(x), cvRound(y));
        picked.push_back(pt);

        cout << picked.size() << "번째 좌표 입력 됨" << endl;
        cout << "x: " << cvRound(x) << ", y: " << cvRound(y) << endl << endl;

        if(picked.size() == 4) cout << "4개 모두 선택 완료.\n아무 키나 눌러 주세요" << endl;

        waitKey(10);
    } else if(event == EVENT_LBUTTONDOWN & picked.size() > 4) cout << "Wrrr" << endl;

}




