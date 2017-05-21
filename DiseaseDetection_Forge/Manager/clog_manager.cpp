/**************************************************************************
File:         clog_manager.cpp
Author:       Song Xiaofeng
Date:         2016-06-15
Description:
**************************************************************************/
#include "clog_manager.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CLogManager* CLogManager::getInstance() {
	static CLogManager manager;
	return &manager;
}

void CLogManager::printLog(const QString &text, int level) {
	QString color;
	switch (level)
	{
	case 0:
		color = "<font color = #00FF00  size = 4>";
		break;
	case 1:
		color = "<font color = orange size = 4>";
		break;
	case 2:
		color = "<font color = red size = 4>";
		break;
	}
	m_log->append(color + ">> " + text);
}

void CLogManager::clearLog() {
	m_log->clear();
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CLogManager::CLogManager()
{

}

CLogManager::~CLogManager()
{

}
