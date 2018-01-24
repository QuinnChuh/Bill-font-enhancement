#include <stdio.h>
#include"cv.h"	
#include"highgui.h"

#include<opencv2/opencv.hpp>  
#include<iostream>  
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("image.png");
	int nr = image.rows;
	int nl = image.cols * image.channels();
	for(int k=0;k<nr;k++)
	{
		const uchar* inData = image.ptr<uchar>(k);
		for(int i=0;i<nl;i++)
		{
			
		}
	}
}