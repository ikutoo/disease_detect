/**************************************************************************
File:         basic_table_structure.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
//////////////////////////////////////////////////////////////////
///    Class:  Data_Asset
///    Brief:  
//////////////////////////////////////////////////////////////////
class Data_Asset {
public:
	int id;
	QString name;
	QString type;
	QString path;
};
const QString table_asset = "asset (id int primary key, name varchar(30), type varchar(10), path varchar(128))";