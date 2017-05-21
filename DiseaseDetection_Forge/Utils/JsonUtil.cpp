#include "JsonUtil.h"

#include <iostream>
#include <fstream>
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

///////////////////////////////////////////////////////////////////////////////////
CJsonWriter::CJsonWriter(const std::string& _filename) {
	m_fileName = _filename;

	FILE *fp = fopen(_filename.c_str(), "r");
	FileStream is(fp);

	m_doc.ParseStream<0>(is);
	assert(!m_doc.HasParseError());
	assert(!m_doc.IsArray());
}

void CJsonWriter::writeBool(const string& _attributName, bool _value) {
	rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	p[_attributName.c_str()].SetBool(_value);
}

void CJsonWriter::writeInt(const string& _attributName, int _value) {
	rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	p[_attributName.c_str()].SetInt(_value);
}
void CJsonWriter::writeDouble(const string& _attributName, double _value) {
	rapidjson::Value &p = m_doc;
	assert(p.HasMember(_attributName.c_str()));
	p[_attributName.c_str()].SetDouble(_value);
}

void CJsonWriter::saveFile() {
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	m_doc.Accept(writer);

	std::ofstream ofile;
	ofile.open(m_fileName);
	ofile << buffer.GetString() << endl;

	ofile.close();
}