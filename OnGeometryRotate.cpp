#include <math.h>
#define PI 3.14159265

void CImageProc학번2017View::OnGeometryRotate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProc학번2017Doc* pDoc = GetDocument();

	int i, x, y;
	int angle = 30;	// degree
	float radian;
	int Cx, Cy, Oy;
	int x_source, y_source;
	int xdiff, ydiff;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	radian = 2 * PI / 360 * angle;
	pDoc->gImageWidth = pDoc->imageHeight*fabs(cos(PI / 2 - radian)) + pDoc->imageWidth*fabs(cos(radian));
	pDoc->gImageHeight = pDoc->imageHeight*fabs(cos(radian)) + pDoc->imageWidth*fabs(cos(PI / 2 - radian));

	// 메모리 할당
	pDoc->gResultImg = (unsigned char **)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth*pDoc->depth);
	}

	// 중심점
	Cx = pDoc->imageWidth / 2;	Cy = pDoc->imageHeight / 2;
	//y의 마지막
	Oy = pDoc->imageHeight - 1;
	xdiff = (pDoc->gImageWidth - pDoc->imageWidth) / 2;
	ydiff = (pDoc->gImageHeight - pDoc->imageHeight) / 2;

	for (y = -ydiff; y < pDoc->gImageHeight - ydiff; y++)
		for (x = -xdiff; x < pDoc->gImageWidth - xdiff; x++)
		{
			x_source = ((Oy - y) - Cy)*sin(radian) + (x - Cx)*cos(radian) + Cx;
			y_source = Oy - (((Oy - y) - Cy)*cos(radian) - (x - Cx)*sin(radian) + Cy);

			if (pDoc->depth == 1)
			{
				if (x_source<0 || x_source>pDoc->imageWidth - 1 ||
					y_source<0 || y_source>pDoc->imageHeight - 1)
					pDoc->gResultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gResultImg[y + ydiff][x + xdiff] = pDoc->inputImg[y_source][x_source];
			}
		}
	Invalidate();
}
