#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main()
{
	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat img = imread("S:\\IMG_4267.JPG");
	// ����һ����Ϊ "ͼƬ"����    
	namedWindow("ͼƬ");
	// �ڴ�������ʾͼƬ   
	cv::imshow("ͼƬ", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�    
	waitKey(6000);
	return 0;
}
