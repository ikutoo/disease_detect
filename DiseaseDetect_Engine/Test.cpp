#include "Test.h"
#include <list>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Utilities.h"
#include <fstream>
using namespace cv;
using namespace std;
void TestSubblockVariance(const cv::Mat& img) {
	std::list<DiseaseArea> lst;
	Mat tagImg = img, dst;
	std::cout << "\n子块方差法：\n";
	eng::PreProcess(img, dst);
	eng::SubblockVariance(dst, lst, 90);

	for each(DiseaseArea a in lst) {
		cout << a.minV << "," << a.maxV << "," << a.minH << "," << a.maxH << endl;
	}
	cvtColor(tagImg, tagImg, CV_BGR2GRAY);
	eng::TagDiseaseArea(tagImg, lst, 255);
	imshow("标记图像", tagImg);

}

void TestSubblockEntropy(const cv::Mat& img) {
	std::list<DiseaseArea> lst;
	Mat tagImg = img, dst;
	std::cout << "\n子块信息熵法：\n";
	eng::PreProcess(img, dst);
	eng::SubblockEntropy(dst, lst, 4.9);

	for each(DiseaseArea a in lst) {
		cout << a.minV << "," << a.maxV << "," << a.minH << "," << a.maxH << endl;
	}
	cvtColor(tagImg, tagImg, CV_BGR2GRAY);
	eng::TagDiseaseArea(tagImg, lst, 255);
	imshow("标记图像", tagImg);
}

void TestSubblockHsv(const cv::Mat& img) {

	std::list<uint8_t> lst;
	std::cout << "\n子块HSV法：\n";
	eng::SubblockHsv(img, lst, 4.0);
	for each (uint8_t  val in lst) {
		std::cout << (int)val << "  ";
	}

}

void TestSubblockRgb(const cv::Mat& img) {

	std::list<uint8_t> lst;
	std::cout << "\n子块RGB法：\n";
	eng::SubblockRgb(img, lst, 200, 150, 0.02);
	for each (uint8_t  val in lst) {
		std::cout << (int)val << "  ";
	}

}

void TestWriteResultInfo() {

}

void TestReadImageInfo() {
	std::list<ImageInfo*> lst;
	ReadImageInfo(s_foutPath + "in.data", lst);
	for each(ImageInfo* p in lst) {
		std::cout << p->id << "  " << p->path << std::endl;
	}
}

void TestDetect() {
	Mat src = imread(s_imgPath + "lf2.jpg");
	//Mat src = imread("1.jpg");
	Mat dst;

	imshow("原始图像", src);

	eng::PreProcess(src, dst);

	TestSubblockVariance(dst);
	TestSubblockEntropy(dst);

	eng::SplitGrid(dst, 255);

	cout << endl;
	imshow("网格分割", dst);
	waitKey(0);
}

void TestReleaseData() {

}

void TestProcessImage() {
	list<ImageInfo*> lstImages;
	list<ResultInfo*> lstResults;
	string src = s_finPath + "in.data";
	string dst = s_foutPath + "out.data";

	ReadImageInfo(src, lstImages);
	cout << lstImages.size() << endl;
	ProcessImages(lstImages, lstResults);
	cout << lstResults.size() << endl;
	WriteResultInfo(dst, lstResults);

	ReleaseData(lstImages, lstResults);
}

void TestAmftSrMethod() {
	Mat src = imread(s_imgPath + "liefeng/6.jpg");
	Mat dst1, dst2, dst3;

	//eng::PreProcess(src, dst1);
	cvtColor(src, dst1, CV_BGR2GRAY);
	eng::EdgeDetection_Sobel(dst1, dst2);

	eng::MaftSrMethod(dst1, dst3);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	//ShowManyImages("灰度-预处理-边缘检测-残余谱", 4, &IplImage(gray), &IplImage(dst1), &IplImage(dst2), &IplImage(dst3));
	//ShowManyImages("灰度-预处理-残余谱", 3, &IplImage(gray), &IplImage(dst1), &IplImage(dst3));
	imshow("1", dst1);
	imshow("2", dst3);

	TestSubblockVariance(dst3);
	eng::SplitGrid(dst3, 255);
	imshow("网格分割", dst3);
	waitKey(0);
}

void TestProjectionAnalysis() {

}

void TestProjection() {
	Mat src = imread(s_imgPath_wh + "4.jpg");
	imshow("src", src);
	Mat dst1, dst2, dst3, dst4;

	//eng::PreProcess(src, dst1);
	//eng::PreProcess(src, dst1);
	cvtColor(src, dst1, CV_BGR2GRAY);
	//eng::EdgeDetection_Sobel(dst1, dst2);

	eng::MaftSrMethod(dst1, dst3);

	eng::Binaryzation(dst3, dst4, 50);

	ShowManyImages("预处理-傅里叶-二值化", 3, &IplImage(dst1), &IplImage(dst3), &IplImage(dst4));

	vector<uint16_t> ver, hor;
	eng::ProjectionStatistic(dst4, hor, ver);
	Mat v, h;
	eng::GenerateProjectionImage(hor, ver, v, h);
	imshow("水平投影图", h);
	imshow("竖直投影图", v);

	float probability;
	list<DiseaseArea> area;
	eng::ProjectionAnalysis(dst4, hor, ver, probability, area);
	cout << "有裂缝可能性：" << probability << endl;
	eng::TagDiseaseArea(dst1, area, 255);
	imshow("病害区域", dst1);
	waitKey(0);
}

void TestBinaryzation() {
	Mat src = imread(s_imgPath_lf + "9.jpg");
	Mat gray, dst;
	cvtColor(src, gray, CV_BGR2GRAY);
	eng::Binaryzation(gray, dst, 150);
	imshow("原图", src);
	imshow("灰度图", gray);
	imshow("二值化", dst);
	waitKey(0);
}

void TestTagDiseaseArea() {
	Mat src = imread(s_imgPath + "liefeng/2.jpg");
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("灰度图", gray);
	list<DiseaseArea> area;
	area.push_back(DiseaseArea(10, 100, 10, 100));
	area.push_back(DiseaseArea(110, 200, 10, 100));
	area.push_back(DiseaseArea(10, 200, 120, 200));
	eng::TagDiseaseArea(gray, area, 0);
	imshow("标记图像", gray);
	waitKey(0);
}

void WriteMatrix() {
	string inPath_lf = s_imgPath_lf;
	string inPath_ps = s_imgPath_ps;
	string inPath_sl = s_imgPath_sl;
	string dataPath = "resource/images/data.mat";
	string labelPath = "resource/images/label.mat";

	list<ImageInfo*> lstImages_lf;
	list<ImageInfo*> lstImages_ps;
	list<ImageInfo*> lstImages_sl;
	list<ImageInfo*> lstImages;

	ReadImageInfo(inPath_lf, lstImages_lf);
	ReadImageInfo(inPath_ps, lstImages_ps);
	ReadImageInfo(inPath_sl, lstImages_sl);

	ofstream osLabel(labelPath);
	ofstream osData(dataPath);

	if (!osLabel) {
		cout << "不能打开label.mat" << endl;
	}
	if (!osData) {
		cout << "不能打开data.mat" << endl;
	}

	for each (ImageInfo* p in lstImages_lf) {
		osLabel << 1 << endl;
		lstImages.push_back(p);
	}
	for each (ImageInfo* p in lstImages_ps) {
		osLabel << 2 << endl;
		lstImages.push_back(p);
	}
	for each (ImageInfo* p in lstImages_sl) {
		osLabel << 3 << endl;
		lstImages.push_back(p);
	}
	for each (ImageInfo* p in lstImages) {
		cv::Mat src = cv::imread(p->path);
		cv::Mat gray, dst;
		cv::cvtColor(src, gray, CV_BGR2GRAY);
		int resize_height = 256;
		int resize_width = 256;
		cv::resize(gray, dst, cv::Size(resize_width, resize_height), (0, 0), (0, 0), cv::INTER_LINEAR);
		eng::MaftSrMethod(dst, dst);
		eng::Binaryzation(dst, dst, 50);
		vector<uint16_t> ver, hor;
		eng::ProjectionStatistic(dst, hor, ver);
		for (int i = 0; i < ver.size() - 1; ++i) {
			osData << ver[i] << " ";
		}
		osData << ver[ver.size() - 1] << endl;
		for (int i = 0; i < hor.size() - 1; ++i) {
			osData << hor[i] << " ";
		}
		osData << hor[hor.size() - 1] << endl;
	}

	osLabel.close();
	osData.close();
}