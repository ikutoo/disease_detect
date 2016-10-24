#include "Utilities.h"

void ShowManyImages(char* title, int nArgs, ...)
{
	IplImage *img;
	IplImage *DispImage;

	int size;
	int i;
	int m, n;
	int x, y;
	int w, h;

	float scale;
	int max;

	if (nArgs <= 0)
	{
		printf("Number of arguments too small....\n");
		return;
	}
	else if (nArgs > 12)
	{
		printf("Number of arguments too large....\n");
		return;
	}
	else if (nArgs == 1)
	{
		w = h = 1;
		size = 300;
	}
	else if (nArgs == 2)
	{
		w = 2; h = 1;
		size = 300;
	}
	else if (nArgs == 3 || nArgs == 4)
	{
		w = 2; h = 2;
		size = 300;
	}
	else if (nArgs == 5 || nArgs == 6) {
		w = 3; h = 2;
		size = 200;
	}
	else if (nArgs == 7 || nArgs == 8)
	{
		w = 4; h = 2;
		size = 200;
	}
	else
	{
		w = 4; h = 3;
		size = 150;
	}
	DispImage = cvCreateImage(cvSize(100 + size*w, 60 + size*h), 8, 1);

	va_list args;
	va_start(args, nArgs);
	for (i = 0, m = 20, n = 20; i < nArgs; i++, m += (20 + size))
	{
		img = va_arg(args, IplImage*);

		if (img == 0)
		{
			printf("Invalid arguments");
			cvReleaseImage(&DispImage);
			return;
		}
		x = img->width;
		y = img->height;
		max = (x > y) ? x : y;
		scale = (float)((float)max / size);

		if (i % w == 0 && m != 20)
		{
			m = 20;
			n += 0 + size;
		}
		cvSetImageROI(DispImage, cvRect(m, n, (int)(x / scale), (int)(y / scale)));
		cvResize(img, DispImage);
		cvResetImageROI(DispImage);
	}
	cvShowImage(title, DispImage);

	va_end(args);
	cvReleaseImage(&DispImage);
}
