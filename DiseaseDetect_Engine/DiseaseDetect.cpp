#include "DiseaseDetect.h"
#include <math.h>
#include <vector>
using namespace cv;
using namespace std;
void eng::PreProcess(const cv::Mat& src, cv::Mat& dst) {
	cv::cvtColor(src, dst, CV_BGR2GRAY);
	//cv::imshow("灰度图像", dst);
	cv::GaussianBlur(dst, dst, cv::Size(5, 5), 0.0);
	//cv::imshow("高斯平滑图像", dst);
	//cv::Canny(dst, dst, 3, 9, 3);
	//cv::imshow("canny算子边缘检测", dst);
	//eng::EdgeDetection_Sobel(dst, dst);
	//cv::imshow("Sobel边缘检测", dst);
	//eng::EdgeDetection_Scharr(dst, dst);
	//cv::imshow("Scharr边缘检测", dst);
	//cv::Laplacian(dst, dst, CV_16S, 3, 1, 0);
	//cv::convertScaleAbs(dst, dst);
	//cv::imshow("Laplacian边缘检测", dst);
	//eng::HoughLine(dst, dst);
	//cv::imshow("霍夫线变换结果", dst);
}

void eng::SplitGrid(cv::Mat& img, uint8_t color) {
	int nr = img.rows;
	int nc = img.cols;
	for (int i = SUBBLOCK_HEIGHT; i < nr; i += SUBBLOCK_HEIGHT) {
		uint8_t * data = img.ptr<uint8_t>(i);
		//uint8_t * datau = img.ptr<uint8_t>(i - 1);
		//uint8_t * datad = img.ptr<uint8_t>(i + 1);
		for (int j = 0; j < nc; j++) {
			data[j] = color;
			//datau[j] = color;
			//datad[j] = color;
		}
	}
	for (int i = SUBBLOCK_WIDTH; i < nc; i += SUBBLOCK_WIDTH) {
		for (int j = 0; j < nr; j++) {
			uint8_t * data = img.ptr<uint8_t>(j);
			data[i] = color;
			//data[i - 1] = color;
			//data[i + 1] = color;
		}
	}
}
void eng::SubblockVariance(const cv::Mat& img, std::list<uint8_t> & list, uint16_t threshold) {
	int nr = img.rows;
	int nc = img.cols;
	int nbr = nr / SUBBLOCK_HEIGHT + ((nr%SUBBLOCK_HEIGHT == 0) ? 0 : 1);
	int nbc = nc / SUBBLOCK_WIDTH + ((nr%SUBBLOCK_HEIGHT == 0) ? 0 : 1);

	for (int i = 0; i < nbr; i++) {
		for (int j = 0; j < nbc; j++) {
			int np = 0;
			float average = 0;
			float variance = 0;
			for (int bi = 0; bi < SUBBLOCK_HEIGHT && (bi + i*SUBBLOCK_HEIGHT < nr); bi++) {
				const uint8_t * data = img.ptr<uint8_t>(bi + i*SUBBLOCK_HEIGHT);
				for (int bj = 0; bj < SUBBLOCK_WIDTH && (bj + j*SUBBLOCK_WIDTH < nc); bj++) {
					uint8_t value = data[bj + j*SUBBLOCK_WIDTH];
					np++;
					average += value;
				}
			}
			average /= np;
			for (int bi = 0; bi < SUBBLOCK_HEIGHT && (bi + i*SUBBLOCK_HEIGHT < nr); bi++) {
				const uint8_t * data = img.ptr<uint8_t>(bi + i*SUBBLOCK_HEIGHT);
				for (int bj = 0; bj < SUBBLOCK_WIDTH && (bj + j*SUBBLOCK_WIDTH < nc); bj++) {
					uint8_t value = data[bj + j*SUBBLOCK_WIDTH];
					variance += (value - average)*(value - average);
				}
			}
			variance /= np;
			//std::cout << variance << std::endl;
			if (variance > threshold)
				list.push_back(i*nbc + j);
		}
	}
}

void eng::SubblockEntropy(const cv::Mat& img, std::list<uint8_t> & list, float threshold) {
	int nr = img.rows;
	int nc = img.cols;
	int nbr = nr / SUBBLOCK_HEIGHT + ((nr%SUBBLOCK_HEIGHT == 0) ? 0 : 1);
	int nbc = nc / SUBBLOCK_WIDTH + ((nr%SUBBLOCK_HEIGHT == 0) ? 0 : 1);

	for (int i = 0; i < nbr; i++) {
		for (int j = 0; j < nbc; j++) {
			int np = 0;
			float entropy = 0;
			int count[256] = { 0 };
			for (int bi = 0; bi < SUBBLOCK_HEIGHT && (bi + i*SUBBLOCK_HEIGHT < nr); bi++) {
				const uint8_t * data = img.ptr<uint8_t>(bi + i*SUBBLOCK_HEIGHT);
				for (int bj = 0; bj < SUBBLOCK_WIDTH && (bj + j*SUBBLOCK_WIDTH < nc); bj++) {
					uint8_t value = data[bj + j*SUBBLOCK_WIDTH];
					np++;
					count[value]++;
				}
			}
			for (int k = 0; k < 256; k++) {

				if (count[k] != 0) {
					float p = ((float)(count[k])) / np;
					entropy += -1 * p*log(p)*LOG2_E;
				}
			}
			//std::cout << entropy << std::endl;
			if (entropy > threshold)
				list.push_back(i*nbc + j);
		}
	}

}

void eng::EdgeDetection_Sobel(const cv::Mat& src, cv::Mat& dst) {
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	cv::Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	cv::Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 1);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
} 

void eng::EdgeDetection_Scharr(const cv::Mat& src, cv::Mat& dst) {
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	cv::Scharr(src, grad_x, CV_16S, 1, 0, 1, 0);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	cv::Scharr(src, grad_y, CV_16S, 0, 1, 1, 0);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
}

void eng::HoughLine(const cv::Mat& src, cv::Mat& dst) {
	std::vector<cv::Vec2f> lines;
	std::cout << lines.size() << std::endl;
	cv::HoughLines(src, lines, 1, CV_PI / 180, 150, 0, 0);
	std::cout << lines.size() << std::endl;
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		cv::Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		cv::line(dst, pt1, pt2, cv::Scalar(55, 100, 195), 1, cv::LINE_AA);
	}
}

void eng::MaftSrMethod(const cv::Mat& src, cv::Mat& dst) {
	Mat planes[] = { Mat_<float>(src), Mat::zeros(src.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI); //把单通道矩阵组合成复数形式的双通道矩阵
	dft(complexI, complexI);  // 使用离散傅立叶变换

							  //对复数矩阵进行处理，方法为谱残差
	Mat mag, pha, mag_mean;
	Mat Re, Im;
	split(complexI, planes); //分离复数到实部和虚部
	Re = planes[0]; //实部
	Im = planes[1]; //虚部
	magnitude(Re, Im, mag); //计算幅值
	phase(Re, Im, pha); //计算相角

	float *pre, *pim, *pm, *pp;
	//对幅值进行对数化
	for (int i = 0; i < mag.rows; i++)
	{
		pm = mag.ptr<float>(i);
		for (int j = 0; j < mag.cols; j++)
		{
			*pm = log(*pm);
			pm++;
		}
	}
	blur(mag, mag_mean, Size(5, 5)); //对数谱的均值滤波
	mag = mag - mag_mean; //求取对数频谱残差
						  //把对数谱残差的幅值和相角划归到复数形式
	for (int i = 0; i < mag.rows; i++)
	{
		pre = Re.ptr<float>(i);
		pim = Im.ptr<float>(i);
		pm = mag.ptr<float>(i);
		pp = pha.ptr<float>(i);
		for (int j = 0; j < mag.cols; j++)
		{
			*pm = exp(*pm);
			*pre = *pm * cos(*pp);
			*pim = *pm * sin(*pp);
			pre++;
			pim++;
			pm++;
			pp++;
		}
	}
	Mat planes1[] = { Mat_<float>(Re),Mat_<float>(Im) };

	merge(planes1, 2, complexI); //重新整合实部和虚部组成双通道形式的复数矩阵
	idft(complexI, complexI, DFT_SCALE); // 傅立叶反变换
	split(complexI, planes); //分离复数到实部和虚部
	Re = planes[0];
	Im = planes[1];
	magnitude(Re, Im, mag); //计算幅值和相角
	for (int i = 0; i < mag.rows; i++)
	{
		pm = mag.ptr<float>(i);
		for (int j = 0; j < mag.cols; j++)
		{
			*pm = (*pm) * (*pm);
			pm++;
		}
	}
	GaussianBlur(mag, mag, Size(7, 7), 2.5, 2.5);
	Mat invDFT;
	normalize(mag, invDFT, 0, 255, NORM_MINMAX); //归一化到[0,255]供显示
	invDFT.convertTo(dst, CV_8U); //转化成CV_8U型
}

void eng::Binaryzation(const cv::Mat& src, cv::Mat& dst, uint8_t threshold) {
	int nr = src.rows;
	int nc = src.cols;
	dst.create(nr, nc, CV_8UC1);
	for (int i = 0; i < nr; i++) {
		const uint8_t * dataSrc = src.ptr<uint8_t>(i);
		uint8_t * dataDst = dst.ptr<uint8_t>(i);
		for (int j = 0; j < nc; j++) {
			if (dataSrc[j] >= threshold) {
				dataDst[j] = 255;
			}
			else {
				dataDst[j] = 0;
			}
		}
	}
}

void eng::ProjectionStatistic(const cv::Mat& src, std::vector<uint16_t>& horizontal, std::vector<uint16_t>& vertical) {
	int nr = src.rows;
	int nc = src.cols;
	horizontal.resize(nr);
	vertical.resize(nc);
	for (int i = 0; i < nr; i++) {
		const uint8_t * data = src.ptr<uint8_t>(i);
		for (int j = 0; j < nc; j++) {
			if (0 != data[j]) {
				horizontal[i]++;
				vertical[j]++;
			}
		}
	}
}

void eng::ProjectionAnalysis(const cv::Mat& src, const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, float& probability, std::list<DiseaseArea>& area) {
	const int minCount = 2;
	const int minStripe = 10;
	const int minArea = 10;
	const int maxDistance = 50;
	vector<iVec2> vLst;
	vector<iVec2> hLst;
	int start, end;
	bool isStart = false;

	for (int i = 0; i < horizontal.size(); i++) {
		if (horizontal[i] >= minCount) {
			if (!isStart) {
				isStart = true;
				start = i;
			}
			else {
				end = i;
			}
		}
		else {
			if (!isStart) {
				continue;
			}
			else {
				isStart = false;
				end = i - 1;
				if (end - start + 1 >= minStripe) {
					hLst.push_back(iVec2(start, end));
				}
			}
		}
	}
	if (isStart) {
		end = horizontal.size() - 1;
		hLst.push_back(iVec2(start, end));
		isStart = false;
	}

	for (int i = 0; i < vertical.size(); i++) {
		if (vertical[i] >= minCount) {
			if (!isStart) {
				isStart = true;
				start = i;
			}
			else {
				end = i;
			}
		}
		else {
			if (!isStart) {
				continue;
			}
			else {
				isStart = false;
				end = i - 1;
				if (end - start + 1 >= minStripe) {
					vLst.push_back(iVec2(start, end));
				}
			}
		}
	}
	if (isStart) {
		end = vertical.size() - 1;
		vLst.push_back(iVec2(start, end));
		isStart = false;
	}

	vector<iVec2> vLst2;
	vector<iVec2> hLst2;
	for (int i = 0, start = 0, end = 0; i < vLst.size() - 1; i++) {
		start = vLst[i].x;
		end = vLst[i].y;
		while (i < (vLst.size() - 1) && ((vLst[i + 1].x - vLst[i].y) < maxDistance)) {
			end = vLst[i + 1].y;
			i++;
		}
		vLst2.push_back(iVec2(start, end));
	}
	if (vLst.size() == 1)
		vLst2.push_back(vLst[0]);
	for (int i = 0, start = 0, end = 0; i < hLst.size() - 1; i++) {
		start = hLst[i].x;
		end = hLst[i].y;
		while (i < (hLst.size() - 1) && ((hLst[i + 1].x - hLst[i].y) < maxDistance)) {
			end = hLst[i + 1].y;
			i++;
		}
		hLst2.push_back(iVec2(start, end));
	}
	if (hLst.size() == 1)
		hLst2.push_back(hLst[0]);

	cout << vLst.size() << endl;
	cout << hLst.size() << endl;
	cout << vLst2.size() << endl;
	cout << hLst2.size() << endl;
	for each (iVec2 v in vLst2) {
		int xMin = v.x;
		int xMax = v.y;
		for each (iVec2 h in hLst2) {
			int yMin = h.x;
			int yMax = h.y;
			int count = 0;
			for (int i = yMin; i <= yMax; ++i) {
				const uint8_t * data = src.ptr<uint8_t>(i);
				for (int j = xMin; j <= xMax; ++j) {
					if (255 == data[j])
						count++;
				}
			}
			if (count >= minArea)
				area.push_back(DiseaseArea(xMin, xMax, yMin, yMax));
		}
	}
}

void eng::TagDiseaseArea(cv::Mat& src, const  std::list<DiseaseArea>& area, uint8_t color) {
	int nr = src.rows;
	int nc = src.cols;
	for each (DiseaseArea a in area) {
		for (int i = a.minH; i <= a.maxH; i++) {
			uint8_t * data = src.ptr<uint8_t>(i);
			if (i == a.minH || i == a.maxH) {
				for (int j = a.minV; j <= a.maxV; j++) {
					data[j] = color;
				}
			}
			else {
				data[a.minV] = color;
				data[a.maxV] = color;
			}
		}
	}
}

void eng::GenerateProjectionImage(const std::vector<uint16_t>& horizontal, const std::vector<uint16_t>& vertical, cv::Mat& imgV, cv::Mat& imgH) {
	int wImgV, hImgV, wImgH, hImgH;
	hImgH = horizontal.size();
	wImgV = vertical.size();
	hImgV = 0;
	wImgH = 0;
	for each (uint16_t i in horizontal) {
		if (i > wImgH)
			wImgH = i;
	}
	for each (uint16_t i in vertical) {
		if (i > hImgV)
			hImgV = i;
	}
	wImgH *= 2;
	hImgV *= 2;
	imgH.create(hImgH, wImgH, CV_8UC1);
	imgV.create(hImgV, wImgV, CV_8UC1);

	for (int i = 0; i < hImgH; i++) {
		uint8_t * data = imgH.ptr<uint8_t>(i);
		for (int j = 0; j < wImgH; j++) {
			if (j < horizontal[i])
				data[j] = 255;
			else
				data[j] = 0;
		}
	}

	for (int i = 0; i < hImgV; i++) {
		uint8_t * data = imgV.ptr<uint8_t>(i);
		for (int j = 0; j < wImgV; j++) {
			if ((hImgV - i) < vertical[j])
				data[j] = 255;
			else
				data[j] = 0;
		}
	}
}

void ProcessImages(const std::list<ImageInfo*>& _images, std::list<ResultInfo*>& _results) {
	for each (ImageInfo* p in _images) {
		cv::Mat src = cv::imread(p->path);
		cv::Mat dst;
		eng::PreProcess(src, dst);
		std::list<uint8_t> lst;
		//std::cout << p->id << "  ";
		eng::SubblockVariance(dst, lst, 50);
		for each (uint8_t  val in lst) {
			//std::cout << (int)val << "  ";
		}
		//std::cout << std::endl;
		_results.push_back(new ResultInfo(p->id, lst.size() > 5));
	}
}

