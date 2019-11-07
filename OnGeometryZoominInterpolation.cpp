void CImageProc학번2017View::OnGeometryZoominInterpolation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProc학번2017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int x, y, i, j;

	float xscale = 3.0;
	float yscale = 3.0;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;


	//기존메모리 삭제
	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->imageWidth*xscale;
	pDoc->gImageHeight = pDoc->imageHeight*yscale;

	// 메모리할당	
	pDoc->gResultImg = (unsigned char **)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char *)malloc(pDoc->gImageWidth*pDoc->depth);
	}


	// TODO : 확대, 양선형보간법
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			src_x = x / xscale;
			src_y = y / yscale;

			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;

			Ax = (int)src_x;
			Ay = (int)src_y;

		/*
			Bx = Ax + 1;
			By = Ay;
			Cx = Ax;
			Cy = Ay + 1;
			Dx = Ax + 1;
			Dy = Ay + 1;
		*/
			Dx = Bx = (Cx = Ax) + 1;
			Dy = Cy = (By = Ay) + 1;


			if (Bx > pDoc->imageWidth - 1) Bx = pDoc->imageWidth - 1;
			if (Cy > pDoc->imageHeight - 1) Cy = pDoc->imageHeight - 1;
			if (Dx > pDoc->imageWidth - 1) Dx = pDoc->imageWidth - 1;
			if (Dy > pDoc->imageHeight - 1) Dy = pDoc->imageHeight - 1;

			if (pDoc->depth == 1)
			{
				E = (1 - alpha)*pDoc->inputImg[Ay][Ax] + alpha * pDoc->inputImg[By][Bx];
				F = (1 - alpha)*pDoc->inputImg[Cy][Cx] + alpha * pDoc->inputImg[Dy][Dx];
				pDoc->gResultImg[y][x] = (1 - beta)*E + beta * F;
			}
		}

	Invalidate();

}
