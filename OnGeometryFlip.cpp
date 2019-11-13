void CImageProc학번2017View::OnGeometryFlip()
{
    // TODO: 여기에 명령 처리기 코드를 추가합니다.
    CImageProc학번2017Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    int x, y, i, j;


    //기존메모리 삭제
    if (pDoc->gResultImg != NULL)
    {
        for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
        free(pDoc->gResultImg);
        pDoc->gResultImg = NULL;
    }

    pDoc->gImageWidth = pDoc->imageWidth;
    pDoc->gImageHeight = pDoc->imageHeight;


    // 메모리할당    
    pDoc->gResultImg = (unsigned char **)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
    for (i = 0; i < pDoc->gImageHeight; i++)
    {
        pDoc->gResultImg[i] = (unsigned char *)malloc(pDoc->gImageWidth*pDoc->depth);
    }


    // TODO : 처리할 코드
    for (y = 0; y < pDoc->imageHeight; y++)
        for (x = 0; x < pDoc->imageWidth; x++)
        {
            if (pDoc->depth == 1)
            {
                pDoc->resultImg[pDoc->imageHeight - 1 - y][x] = pDoc->inputImg[y][x];
            }
            else
            {
                pDoc->resultImg[pDoc->imageHeight - 1 - y][3 * x + 0] = pDoc->inputImg[y][3 * x + 0];
                pDoc->resultImg[pDoc->imageHeight - 1 - y][3 * x + 1] = pDoc->inputImg[y][3 * x + 1];
                pDoc->resultImg[pDoc->imageHeight - 1 - y][3 * x + 2] = pDoc->inputImg[y][3 * x + 2];
            }

        }

    Invalidate();

}
