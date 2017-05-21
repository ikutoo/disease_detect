/**************************************************************************
File:         casset_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "casset_manager.h"
#include "expert/cfile_expert.h"
#include "unit/cdb_operator.h"
#include <QXmlStreamWriter>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAssetManager* CAssetManager::getInstance() {
	static CAssetManager manager;
	return &manager;
}

bool CAssetManager::initAsset(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	bool b1 = mInitAssetsDir();
	bool b2 = mInitAssetsDB();
	return b1 && b2;
}

bool CAssetManager::loadAsset(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	return true;
}

bool CAssetManager::createFile(const QString &name, const QString &type) {
	if (type == "Scene") {
		if (mCreateScene(name))
			return false;
	}
	return true;
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CAssetManager::CAssetManager() {

}

CAssetManager::~CAssetManager() {

}

bool CAssetManager::mInitAssetsDB() {
	CDBOperator * dbp = CDBOperator::getInstance();
	dbp->start();
	if (!(dbp->createDB(m_strPath + "/" + m_strName, m_strName + ".db")))
		return false;
	if (!dbp->createTable()) {
		//return false;
	}
	emit signal_insert_db("asset", m_strPath + "/" + m_strName + "/assets");
	return true;
}

bool CAssetManager::mInitAssetsDir() {
	bool bOk = CFileExpert::copyRecursively(":/picture/ui_picture/projectInit", m_strPath + "//"
		+ m_strName + "//" + "assets");
	return bOk;
}

bool CAssetManager::mCreateScene(const QString &name) {
	QFile file(m_currentPath+"/"+name+".scene");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);
	writer.writeStartDocument("1.0");
	writer.writeStartElement("config");
	//writer.writeAttribute("name", m_strName);
	//writer.writeAttribute("path", m_strPath);
	writer.writeEndElement();
	writer.writeEndElement();
	writer.writeEndElement();
	file.close();
	return true;
}