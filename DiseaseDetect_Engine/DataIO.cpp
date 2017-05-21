#include "DataIO.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <vector>
#include "JsonUtil.h"
#include "params.h"
using namespace std;

std::vector<string> g_files;

wstring ANSIToUnicode(const string& str)
{
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar(CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0);
	wchar_t *  pUnicode;
	pUnicode = new  wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP,
		0,
		str.c_str(),
		-1,
		(LPWSTR)pUnicode,
		unicodeLen);
	wstring  rt;
	rt = (wchar_t*)pUnicode;
	delete  pUnicode;

	return  rt;
}

string UnicodeToANSI(const wstring& str)
{
	char*     pElementText;
	int    iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0,
		NULL,
		NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1));
	::WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	string strText;
	strText = pElementText;
	delete[] pElementText;
	return strText;
}

bool is_dir(const char* path) {
	return GetFileAttributes(ANSIToUnicode(path).c_str())&FILE_ATTRIBUTE_DIRECTORY;
}

int find_all_files(const char * lpPath)
{
	char szFind[MAX_PATH];
	WIN32_FIND_DATA FindFileData;
	strcpy(szFind, lpPath);
	strcat(szFind, "\\*.*");
	HANDLE hFind = ::FindFirstFile(ANSIToUnicode(szFind).c_str(), &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
		return -1;

	do
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (strcmp(UnicodeToANSI(FindFileData.cFileName).c_str(), ".") != 0 && strcmp(UnicodeToANSI(FindFileData.cFileName).c_str(), "..") != 0)
			{
				char szFile[MAX_PATH] = { 0 };
				strcpy(szFile, lpPath);
				strcat(szFile, "\\");
				strcat(szFile, UnicodeToANSI(FindFileData.cFileName).c_str());
				find_all_files(szFile);
			}
		}
		else
		{
			string fp = string(lpPath) + "/" + UnicodeToANSI(FindFileData.cFileName);
			g_files.push_back(fp);
		}
	} while (::FindNextFile(hFind, &FindFileData));

	::FindClose(hFind);

	return 0;
}

bool ReadImageInfo(const std::string& _path, std::list<ImageInfo*>& _info) {
	if (is_dir(_path.c_str())) {
		g_files.clear();
		find_all_files(_path.c_str());
		for (int i = 0; i < g_files.size(); ++i) {
			ImageInfo * info = new ImageInfo(i, g_files[i]);
			_info.push_back(info);
		}
	}
	else {
		ImageInfo * info = new ImageInfo(0, _path);
		_info.push_back(info);
	}
	return true;
}

bool WriteResultInfo(const std::string& _path, const std::list<ResultInfo*> _info) {
	ofstream fout(_path);
	if (!fout) {
		return false;
	}
	for each (ResultInfo* p in _info) {
		fout << p->id << "\t";
		fout << p->path << "\t";
		fout << (p->isDisease ? "true" : "false") << "\t";
		fout << (int)p->type << "\t";
		for each (uint16_t t in p->areas) {
			fout << (int)t << "\t";
		}
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

bool ReadParams(const std::string& _path) {
	CJsonReader reader(_path);
	int blurType = reader.readInt("blurType");
	bool bMaft = reader.readBool("bMaft");
	int detectType = reader.readInt("detectType");
	bool bProDetect = reader.readBool("bProDetect");
	bool bColorDetect = reader.readBool("bColorDetect");
	double varThreshold = reader.readDouble("varThreshold");
	double entThreshold = reader.readDouble("entThreshold");
	int binThreshold = reader.readInt("binThreshold");

	s_blurType = blurType;
	s_bMaft = bMaft;
	s_detectType = detectType;
	s_bProDetect = bProDetect;
	s_bColorDetect = bColorDetect;
	s_varThreshold = varThreshold;
	s_entThreshold = entThreshold;
	s_binThreshold = binThreshold;

	return true;
}