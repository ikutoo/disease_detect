#pragma once

#include "opencv2/opencv.hpp"
#include <list>
#include "Defines.h"
#include "BasicStructs.h"
namespace eng {
	//预处理
	void PreProcess(const cv::Mat& src, cv::Mat& dst);
	//划分网格
	void SplitGrid(cv::Mat& img, uint8_t color);
	//子块方差法
	void SubblockVariance(const cv::Mat& img, std::list<uint8_t> & list, uint16_t threshold);
	//子块信息熵法
	void SubblockEntropy(const cv::Mat& img, std::list<uint8_t> & list, float threshold);
	//sobel算子边缘检测封装
	void EdgeDetection_Sobel(const cv::Mat& src, cv::Mat& dst);
	//scharr算子边缘检测封装
	void EdgeDetection_Scharr(const cv::Mat& src, cv::Mat& dst);
	//霍夫线变换封装
	void HoughLine(const cv::Mat& src, cv::Mat& dst);
	//调幅傅里叶变换-残余谱方法
	void MaftSrMethod(const cv::Mat& src, cv::Mat& dst);
	//二值化处理
	void Binaryzation(const cv::Mat& src, cv::Mat& dst, uint8_t threshold);
	//投影统计--针对二值图像
	void ProjectionStatistic(const cv::Mat& src, std::vector<uint16_t>& horizontal, std::vector<uint16_t>& vertical);
	//投影分析
	void ProjectionAnalysis(const cv::Mat& src, const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, float& probability, std::list<DiseaseArea>& area);
	//生成投影分布图
	void GenerateProjectionImage(const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, cv::Mat& imgV, cv::Mat& imgH);
	//标记病害区域--针对单通道图像
	void TagDiseaseArea(cv::Mat& src, const std::list<DiseaseArea>& area, uint8_t color);
}

void ProcessImages(const std::list<ImageInfo*>& _images, std::list<ResultInfo*>& _results);


