#pragma once
#include "BasicStructs.h"

bool ReadImageInfo(const std::string& _path, std::list<ImageInfo*>& _info);

bool WriteResultInfo(const std::string& _path, const std::list<ResultInfo*> _info);

void ReleaseData(std::list<ImageInfo*> _images, std::list<ResultInfo*> _results);

bool ReadParams(const std::string& _path);