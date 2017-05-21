/**************************************************************************
File:         cdatabase_expert.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cdatabase_expert.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CDataBaseExpert::CDataBaseExpert(QObject * parent) : QObject(parent) {

}

CDataBaseExpert::~CDataBaseExpert() {

}

QSqlDatabase & CDataBaseExpert::createDB(const QString & p_dbPath, const QString & p_dbName) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(p_dbPath + "/" + p_dbName);
	return db;
}