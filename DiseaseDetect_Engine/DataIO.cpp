#include "DataIO.h"
#include <fstream>
using namespace std;
bool ReadImageInfo(const std::string& _path, std::list<ImageInfo*>& _info) {
	ifstream fin(_path);
	if (!fin) {
		return false;
	}

	char line[256] = { 0 };

	while (fin.getline(line, sizeof(line))) {
		char tmp[256];
		int j = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] != ' ') {
				tmp[j] = line[i]; j++;
			}
		}
		tmp[j] = '\0';
		if (tmp[0] == '|')
			continue;

		string word = "";
		ImageInfo *info = new ImageInfo;
		for (int i = 0, j = 0; j < 2; i++) {
			if (tmp[i] != ',' &&  tmp[i] != '\0') {
				word.push_back(tmp[i]);
			}
			else {
				if (j == 0) {
					info->id = atoi(word.c_str());
				}
				else if (j == 1) {
					info->path = word;
				}
				++j;
				word.clear();
			}
		}
		_info.push_back(info);
	}
	fin.close();
	return true;
}

bool WriteResultInfo(const std::string& _path, const std::list<ResultInfo*> _info) {
	ofstream fout(_path);
	if (!fout) {
		return false;
	}
	for each (ResultInfo* p in _info) {
		fout << p->id << "  ";
		fout << (p->isDisease ? "true" : "false");
		fout << endl;
	}
	fout.close();
	return true;
}

void ReleaseData(std::list<ImageInfo*> _images, std::list<ResultInfo*> _results) {
	for each (ImageInfo* p in _images) {
		delete p;
	}
	for each (ResultInfo* p in _results) {
		delete p;
	}
}