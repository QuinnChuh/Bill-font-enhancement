#include <stdio.h>
#include"cv.h"	
#include <math.h>
#include"highgui.h"
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>  
#include<iostream>  
using namespace std;
using namespace cv;
int main()
{
	Mat image = imread("image.png");
	imshow("source",image);
	Mat two_value=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat median_blur=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat mean_blur=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat gaussian_blur=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat dilate_blur=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat erode_blur=Mat::zeros(image.rows,image.cols,CV_8UC1);
	Mat result=Mat::zeros(image.rows,image.cols,CV_8UC3);
	Mat process_result=Mat::zeros(image.rows,image.cols,CV_8UC3);
	for(int i=0;i<image.rows;i++){
		for(int j =0;j<image.cols;j++)
		{
			//R G B
			if((image.at<Vec3b>(i,j)[2]<222) & (image.at<Vec3b>(i,j)[1]<222) & (image.at<Vec3b>(i,j)[0]>210))
			{
				result.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[0]+30;
				result.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[1]-80;
				result.at<Vec3b>(i,j)[2] = image.at<Vec3b>(i,j)[2]-80;
				if(result.at<Vec3b>(i,j)[0] > 255)
				{
					result.at<Vec3b>(i,j)[0] =255;
				}
				if(result.at<Vec3b>(i,j)[1] < 0)
				{
					result.at<Vec3b>(i,j)[1] = 0;
				}
				if(result.at<Vec3b>(i,j)[2] < 0)
				{
					result.at<Vec3b>(i,j)[2] = 0;
				}
				two_value.at<uchar>(i,j)=255;//white
			}
			else
			{
				result.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[0];
				result.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[1];
				result.at<Vec3b>(i,j)[2] = image.at<Vec3b>(i,j)[2];
				two_value.at<uchar>(i,j)=0;//black
			}
		}
	}
	imshow("result",result);
	//imwrite("result.bmp",result);
	imshow("mask",two_value);
	//imwrite("mask.bmp",two_value);
	medianBlur(two_value,median_blur,3);
	imshow("median_blur",median_blur);
	blur(two_value,mean_blur,Size(3,3),Point(-1,-1));
	imshow("mean_blur",mean_blur);
	GaussianBlur(two_value,gaussian_blur,Size(5,5),0,0);
	imshow("GaussianBlur",gaussian_blur);

	Mat element = getStructuringElement(MORPH_RECT, Size(2, 2));
	dilate(median_blur, dilate_blur, element);
	imshow("dilate",dilate_blur);
	erode(dilate_blur, erode_blur, element);
	imshow("erode",erode_blur);
	for(int i=0;i<erode_blur.rows;i++){
		for(int j =0;j<erode_blur.cols;j++)
		{
			if(erode_blur.at<uchar>(i,j) == 255)
			{
				int temp1 = image.at<Vec3b>(i,j)[0]+200;
				int temp2 = image.at<Vec3b>(i,j)[1]-80;
				int temp3 = image.at<Vec3b>(i,j)[2]-80;
				if(temp1 > 255)
				{
					process_result.at<Vec3b>(i,j)[0] =255;
				}
				if(temp2 < 0)
				{
					process_result.at<Vec3b>(i,j)[1] = 0;
				}
				if(temp3 < 0)
				{
					process_result.at<Vec3b>(i,j)[2] = 0;
				}
				process_result.at<Vec3b>(i,j)[0] = temp1;
				process_result.at<Vec3b>(i,j)[1] = temp2;
				process_result.at<Vec3b>(i,j)[2] = temp3;
			}
			else
			{
				process_result.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,j)[0];
				process_result.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,j)[1];
				process_result.at<Vec3b>(i,j)[2] = image.at<Vec3b>(i,j)[2];
			}
		}
	}
	imshow("process_result",process_result);
	waitKey(0);
	return 0;
}
