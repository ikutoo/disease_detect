/**************************************************************************
File:         cmanager.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
#include <QObject>

class CManager : public QObject {
	Q_OBJECT

public:
	CManager(QObject * parent = Q_NULLPTR);
	~CManager();

private:
	
};
