#pragma once
#include "opencv2/opencv.hpp"
#include "DiseaseDetect.h"
#include "DataIO.h"

//子块方差法测试
void TestSubblockVariance(const cv::Mat& img);
//子块信息熵测试
void TestSubblockEntropy(const cv::Mat& img);
//写出测试信息测试
void TestWriteResultInfo();
//读入图像信息测试
void TestReadImageInfo();
//病害检测测试
void TestDetect();
//释放资源测试
void TestReleaseData();
//图像处理测试
void TestProcessImage();
//残余谱方法测试
void TestAmftSrMethod();
//投影分析测试
void TestProjectionAnalysis();
//投影测试
void TestProjection();
//二值化测试
void TestBinaryzation();
//标记病害区域测试
void TestTagDiseaseArea();