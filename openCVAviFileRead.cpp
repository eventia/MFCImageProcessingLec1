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

using namespace cv;
using namespace std;

int main()
{
  Mat img_color;

  // 재생할 동영상 파일을 지정해줍니다.
  VideoCapture cap("output.avi");
  if (!cap.isOpened()) {
    cerr << "에러 - 카메라를 열 수 없습니다.\n";
    return -1;
  }

  while(1) {
    cap.read(img_color);
    if (img_color.empty()) {
      cerr << "빈 영상입니다.\n";
      break;
    }
    imshow("Color", img_color);
    if (waitKey(25) >= 0) break;
  }
	return 0;
}
