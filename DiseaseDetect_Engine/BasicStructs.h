#pragma once
#include <string>
#include <list>
struct ImageInfo {
	ImageInfo(unsigned int _id, std::string _path) { id = _id; path = _path; }
	ImageInfo() {}
	unsigned int id;
	std::string path;
};

struct ResultInfo {
	ResultInfo(unsigned int _id, bool _isDisease) { id = _id; isDisease = _isDisease; }
	ResultInfo() {}
	unsigned int id;
	bool isDisease = false;
};

struct DiseaseArea {
	DiseaseArea(uint16_t _minV, uint16_t _maxV, uint16_t _minH, uint16_t _maxH) {
		minV = _minV; maxV = _maxV; minH = _minH; maxH = _maxH;
	}
	uint16_t minV;
	uint16_t maxV;
	uint16_t minH;
	uint16_t maxH;
};
struct iVec2
{
	iVec2(int _x, int _y) { x = _x; y = _y; }
	int x;
	int y;
};
