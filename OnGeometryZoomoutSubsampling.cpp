void CImageProc학번2017View::OnGeometryZoomoutSubsampling()
{
    // TODO: 여기에 명령 처리기 코드를 추가합니다.
    CImageProc학번2017Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    int x, y, i;
    int xscale = 3;
    int yscale = 2;


    //기존메모리 삭제
    if (pDoc->gResultImg != NULL)
    {
        for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
        free(pDoc->gResultImg);
        pDoc->gResultImg = NULL;
    }

    pDoc->gImageWidth = pDoc->imageWidth / xscale;
    pDoc->gImageHeight = pDoc->imageHeight / yscale;


    // 메모리할당    
    pDoc->gResultImg = (unsigned char **)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
    for (i = 0; i < pDoc->gImageHeight; i++)
    {
        pDoc->gResultImg[i] = (unsigned char *)malloc(pDoc->gImageWidth*pDoc->depth);
    }


    //역방향사상
    for (y = 0; y < pDoc->gImageHeight; y++)
        for (x = 0; x < pDoc->gImageWidth; x++)
        {
            if (pDoc->depth == 1)
                pDoc->gResultImg[y][x] = pDoc->inputImg[y*yscale][x*xscale];
            
        }
    Invalidate();
}
