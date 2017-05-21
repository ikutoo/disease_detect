/**************************************************************************
File:         cfile_expert.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef FILEEXPERT_H
#define FILEEXPERT_H
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QList>
#include "unit/basic_table_structure.h"
#include "unit/basic_data_structure.h"
//////////////////////////////////////////////////////////////////
///    Class:  CFileExpert
///    Brief:  
//////////////////////////////////////////////////////////////////
class CFileExpert
{
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CFileExpert();
	static bool copyRecursively(const QString &srcFilePath, const QString &tgtFilePath);
	static bool readRecursively(const QString &srcFilePath, QList<Data_Asset> &list);
	static bool readTreeRecursively(const QString &srcFilePath, CAssetTreeNode * (& node));
	static bool deleteDir(const QString &dirName);
	static QString convertFileTpye(const QString& type);
};

#endif // FILEEXPERT_H
