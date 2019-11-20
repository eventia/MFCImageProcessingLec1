

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
