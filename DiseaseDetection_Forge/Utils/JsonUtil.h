#pragma once


#include "json/document.h"
#include "json/writer.h"  
#include "json/stringbuffer.h"  
#include "json/filestream.h" 

using namespace std;
using namespace rapidjson;
//************************************************************************
//@brief:  Tool class for parsing JSON profiles                           
//************************************************************************
class CJsonReader
{
public:
	//********************************************************************************
	// Method:    CJsonReader
	// FullName:  CJsonReader::CJsonReader
	// Access:    public 
	// Returns:   
	// Description: constructor of the class 
	// Parameter: const std::string & _filename
	//********************************************************************************
	CJsonReader(const std::string& _filename);


	//********************************************************************************
	// Method:    readString
	// FullName:  CJsonReader::readString
	// Access:    public 
	// Returns:   std::string
	// Description: read field $_attributName from the JSON file and convert it to string type and return
	// Parameter: const string & _attributName
	//********************************************************************************
	string readString(const string& _attributName);

	//********************************************************************************
	// Method:    readInt
	// FullName:  CJsonReader::readInt
	// Access:    public 
	// Returns:   int
	// Description: read field $_attributName from the JSON file and convert it to string type and return
	// Parameter: const string & _attributName
	//********************************************************************************
	int readInt(const string& _attributName);

	//********************************************************************************
	// Method:    readDouble
	// FullName:  CJsonReader::readDouble
	// Access:    public 
	// Returns:   double
	// Description: read field $_attributName from the JSON file and convert it to double type and return
	// Parameter: const string & _attributName
	//********************************************************************************
	double readDouble(const string& _attributName);

	//********************************************************************************
	// Method:    readBool
	// FullName:  CJsonReader::readBool
	// Access:    public 
	// Returns:   bool
	// Description: read field $_attributName from the JSON file and convert it to bool type and return
	// Parameter: const string & _attributName
	//********************************************************************************
	bool readBool(const string& _attributName);

private:
	//GenericDocument with UTF8 encoding
	rapidjson::Document m_doc;

};

//************************************************************************
//@brief: 用于写入json配置文件的工具类
//************************************************************************
class CJsonWriter {

public:
	CJsonWriter(const std::string& _filename);

	void writeBool(const string& _attributName, bool _value);

	void writeInt(const string& _attributName, int _value);

	void writeDouble(const string& _attributName, double _value);

	void saveFile();

private:
	string m_fileName; //要写入的文件路径名

	rapidjson::Document m_doc; //GenericDocument with UTF8 encoding
};