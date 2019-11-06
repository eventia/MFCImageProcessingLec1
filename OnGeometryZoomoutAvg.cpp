void CImageProc학번2017View::OnGeometryZoomoutAvg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProc학번2017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int x, y, i, j;
	int sum, rsum, gsum, bsum;
	int src_x, src_y;
	int xscale = 3;
	int yscale = 3;


	//기존메모리 삭제
	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->imageWidth / xscale + 1;
	pDoc->gImageHeight = pDoc->imageHeight / yscale + 1;


	// 메모리할당	
	pDoc->gResultImg = (unsigned char **)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char *)malloc(pDoc->gImageWidth*pDoc->depth);
	}

	for (y = 0; y < pDoc->imageHeight; y += yscale)
		for (x = 0; x < pDoc->imageWidth; x += xscale)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;
						if (src_x > pDoc->imageWidth - 1) src_x = pDoc->imageWidth - 1;
						if (src_y > pDoc->imageHeight - 1) src_y = pDoc->imageHeight - 1;

						sum += pDoc->inputImg[src_y][src_x];
					}
				pDoc->gResultImg[y / yscale][x / xscale] = sum / (xscale*yscale);
			}
			else
			{
				rsum = 0;	gsum = 0;	bsum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;
						if (src_x > pDoc->imageWidth - 1) src_x = pDoc->imageWidth - 1;
						if (src_y > pDoc->imageHeight - 1) src_y = pDoc->imageHeight - 1;

						rsum += pDoc->inputImg[src_y][3 * src_x + 0];
						gsum += pDoc->inputImg[src_y][3 * src_x + 1];
						bsum += pDoc->inputImg[src_y][3 * src_x + 2];
					}
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (xscale*yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (xscale*yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (xscale*yscale);
			}
		}
	Invalidate();

}
