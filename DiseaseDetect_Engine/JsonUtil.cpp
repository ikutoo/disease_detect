#include "JsonUtil.h"

#include <iostream>

CJsonReader::CJsonReader(const std::string& _filename) {
	FILE *fp = fopen(_filename.c_str(), "r");
	FileStream is(fp);

	m_doc.ParseStream<0>(is);
	assert(!m_doc.HasParseError());
	assert(!m_doc.IsArray());
}

string CJsonReader::readString(const string& _attributName) {
	const rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	return p[_attributName.c_str()].GetString();
}

int CJsonReader::readInt(const string& _attributName) {
	const rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	return p[_attributName.c_str()].GetInt();
}

double CJsonReader::readDouble(const string& _attributName) {
	const rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	return p[_attributName.c_str()].GetDouble();
}

bool CJsonReader::readBool(const string& _attributName) {
	const rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	return p[_attributName.c_str()].GetBool();
}

