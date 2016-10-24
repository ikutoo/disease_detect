#include <opencv2/opencv.hpp>
#include "DiseaseDetect.h"
#include "Test.h"
#include <fstream>
#include "DataIO.h"
using namespace cv;
using namespace std;
#define _TEST

#ifdef _TEST
int main() {
	TestProjection();
	return 0;
}
#else
int main(int argc, char ** argv) {
	if ((argc % 2) != 1) {
		cerr << "param error!" << endl;
		exit(0);
	}

	string src = "";
	string dst = "";

	for (int i = 1; i < argc; i += 2) {
		char * s1 = argv[i];
		char * s2 = argv[i + 1];
		if (0 == strcmp(s1, "-s")) {
			src = s2;
		}
		else if (0 == strcmp(s1, "-d")) {
			dst = s2;
		}
	}

	list<ImageInfo*> lstImages;
	list<ResultInfo*> lstResults;

	ReadImageInfo(src, lstImages);
	ProcessImages(lstImages, lstResults);
	WriteResultInfo(dst, lstResults);

	ReleaseData(lstImages, lstResults);
	return 0;
}

#endif

