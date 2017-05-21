/**************************************************************************
File:         cdatabase_expert.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
#include <QObject>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
//////////////////////////////////////////////////////////////////
///    Class:  CDataBaseExpert
///    Brief:  
//////////////////////////////////////////////////////////////////
class CDataBaseExpert : public QObject {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CDataBaseExpert(QObject * parent = Q_NULLPTR);
	~CDataBaseExpert();
	static QSqlDatabase & createDB(const QString & p_dbPath, const QString & p_dbName);

	
};
