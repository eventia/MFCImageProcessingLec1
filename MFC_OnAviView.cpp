/*
  1. OpenCV-4.1.1 을 다운로드 (구글검색)
  2. opencv 설치(C:\opencv-4.1.1 에 설치)
  3. 편집중인 프로젝트 열기
  4. 솔루션 플랫폼을 x64 로 변경
  5. 솔루션 탐색기 - 프로젝트 이름 선택 (마우스 우클릭) 속성
  6. [모든구성] >> C/C++ >> 추가 포함 디렉터리 : C:\opencv-4.1.1\build\include
  7. [링커] - 추가 라이브러리 디덱터리 : C:\opencv-4.1.1\build\x64\vc15\lib
  8. [디버깅] -  환경 : PATH=C:\opencv-4.1.1\build\x64\vc15\bin;%PATH%
  9. 구성 : Debug // 속성 페이지 변경 내용 저장
  10. [링커]-[입력] - 추가 종속성 : opencv_world411d.lib;
  11. 구성 : Release // 저장
  12. [링커]-[입력] - 추가 종속성 : opencv_world411d.lib;
*/

/*
  구성속성 - 일반 - 프로젝트기본값 - MFC사용 : 공유 DLL에서 MFC사용
                                  - 문자집합 : 멀티바이트 문자 집합 사용
*/

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>


using namespace cv;
using namespace std;

void CImageProc학번2017View::OnAviView()
{
    CImageProc학번2017Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    CFileDialog dlg(TRUE);
    CFile file;
    int x, y;
    int value;

    if (dlg.DoModal() == IDCANCEL)
        return;

    CString movfile = dlg.GetPathName();
    std::string strMovFIle((LPCSTR)movfile);



    Mat frame;

    VideoCapture cap(strMovFIle);
    if (!cap.isOpened()) {
        AfxMessageBox("파일을 불러오는데 실패하였습니다.");
    }


    while(1) {
        cap.read(frame);
        if (frame.empty()) {
            AfxMessageBox("영상파일이 아닙니다");
            break;
        }
        imshow("Live", frame);
        if (waitKey(30) >= 0) break;
    }   

}
