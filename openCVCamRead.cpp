/*
  1. OpenCV-4.1.1 을 다운로드 (구글검색)
  2. opencv 설치(C:\opencv-4.1.1 에 설치)
  3. Visual Studio 2017 실행 >> 새프로젝트 >> Visual C++ >> windows 데스크톱 >> windows 데스크톱 마법사
  4. [v] 빈프로젝트
  5. 솔루션탐색기 - 소스 파일  (마우스 우클릭) 추가 >> 새항목
  6. C++ 선택 , 이름은 main.cpp 로
  7. 솔류션 플랫폼을 x64 로 변경
  8. 솔루션 탐색기 - 프로젝트 이름 선택 (마우스 우클릭) 속성
  9. [모든구성] >> C/C++ >> 추가 포함 디렉터리 : C:\opencv-4.1.1\build\include
  10. [링커] - 추가 라이브러리 디덱터리 : C:\opencv-4.1.1\build\x64\vc15\lib
  11. [디버깅] -  환경 : PATH=C:\opencv-4.1.1\build\x64\vc15\bin;%PATH%
  12. 구성 : Debug // 속성 페이지 변경 내용 저장
  13. [링커]-[입력] - 추가 종속성 : opencv_world411d.lib;
  14. 구성 : Release // 저장
  15. [링커]-[입력] - 추가 종속성 : opencv_world411d.lib;
*/

// main.cpp 내용

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
  Mat frame;
  //--- INITIALIZE VIDEOCAPTURE
  VideoCapture cap;
  // open the default camera using default API
  cap.open(0);
  // OR advance usage: select any API backend
  int deviceID = 0;             // 0 = open default camera
  int apiID = cv::CAP_ANY;      // 0 = autodetect default API
                                // open selected camera using selected API
  cap.open(deviceID + apiID);
  // check if we succeeded
  if (!cap.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }

  //--- GRAB AND WRITE LOOP
  cout << "Start grabbing" << endl
    << "Press any key to terminate" << endl;
  for (;;)
  {
    // wait for a new frame from camera and store it into 'frame'
    cap.read(frame);
    // check if we succeeded
    if (frame.empty()) {
      cerr << "ERROR! blank frame grabbed\n";
      break;
    }
    // show live and wait for a key with timeout long enough to show images
    imshow("Live", frame);
    if (waitKey(5) >= 0)
      break;
  }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}
