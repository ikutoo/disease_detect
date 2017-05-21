/**************************************************************************
File:         cfile_expert.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cfile_expert.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CFileExpert::CFileExpert()
{
}

bool CFileExpert::copyRecursively(const QString & srcFilePath, const QString & tgtFilePath)
{
	QFileInfo srcFileInfo(srcFilePath);
	if (srcFileInfo.isDir()) {
		QDir targetDir(tgtFilePath);
		targetDir.cdUp();
		if (!targetDir.mkdir(QFileInfo(tgtFilePath).fileName()))
			return false;
		QDir sourceDir(srcFilePath);
		QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs |
			QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		foreach(const QString &fileName, fileNames) {
			const QString newSrcFilePath
				= srcFilePath + QLatin1Char('/') + fileName;
			const QString newTgtFilePath
				= tgtFilePath + QLatin1Char('/') + fileName;
			if (!copyRecursively(newSrcFilePath, newTgtFilePath))
				return false;
		}
	}
	else {
		if (!QFile::copy(srcFilePath, tgtFilePath))
			return false;
	}
	return true;
}

bool CFileExpert::deleteDir(const QString &dirName)
{
	QDir directory(dirName);
	if (!directory.exists())
	{
		return true;
	}

	QString srcPath = QDir::toNativeSeparators(dirName);
	if (!srcPath.endsWith(QDir::separator()))
		srcPath += QDir::separator();

	QStringList fileNames = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
	bool error = false;
	for (QStringList::size_type i = 0; i != fileNames.size(); ++i)
	{
		QString filePath = srcPath + fileNames.at(i);
		QFileInfo fileInfo(filePath);
		if (fileInfo.isFile() || fileInfo.isSymLink())
		{
			QFile::setPermissions(filePath, QFile::WriteOwner);
			if (!QFile::remove(filePath))
			{
				qDebug() << "remove file" << filePath << " faild!";
				error = true;
			}
		}
		else if (fileInfo.isDir())
		{
			if (!deleteDir(filePath))
			{
				error = true;
			}
		}
	}

	if (!directory.rmdir(QDir::toNativeSeparators(directory.path())))
	{
		qDebug() << "remove dir" << directory.path() << " faild!";
		error = true;
	}

	return !error;
}

bool CFileExpert::readRecursively(const QString &srcFilePath, QList<Data_Asset> &list) {
	QFileInfo srcFileInfo(srcFilePath);
	if (srcFileInfo.isDir()) {
		QDir sourceDir(srcFilePath);
		QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		foreach(const QString &fileName, fileNames) {
			const QString newSrcFilePath
				= srcFilePath + QLatin1Char('/') + fileName;
			if (!readRecursively(newSrcFilePath, list))
				return false;
		}
	}
	else {
		Data_Asset da;
		da.id = 0;
		da.name = srcFileInfo.fileName();
		da.path = srcFileInfo.absoluteFilePath();
		da.type = convertFileTpye(srcFileInfo.suffix());
		list.append(da);
	}
	return true;
}

bool CFileExpert::readTreeRecursively(const QString &srcFilePath, CAssetTreeNode * (&node)) {
	QFileInfo srcFileInfo(srcFilePath);
	if (srcFileInfo.isDir()) {
		QDir sourceDir(srcFilePath);
		QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);

		CAssetTreeNode * tmp = new CAssetTreeNode;
		tmp->data.id = 0;
		tmp->data.name = srcFileInfo.fileName();
		tmp->data.path = srcFileInfo.filePath();
		tmp->data.type = "folder";
		if (node == 0)
			node = tmp;
		else {
			node->addSibling(tmp);
		}
		for (QStringList::iterator it = fileNames.begin(); it != fileNames.end(); it++) {
			const QString newSrcFilePath
				= srcFilePath + QLatin1Char('/') + *it;
			if (!readTreeRecursively(newSrcFilePath, tmp->lchild)) {
				return false;
			}
		}
	}
	else {
		CAssetTreeNode * tmp = new CAssetTreeNode;
		tmp->data.id = 0;
		tmp->data.name = srcFileInfo.fileName();
		tmp->data.path = srcFileInfo.filePath();
		tmp->data.type = convertFileTpye(srcFileInfo.suffix());
		if (node == 0)
			node = tmp;
		else {
			node->addSibling(tmp);
		}
	}
	return true;
}

QString CFileExpert::convertFileTpye(const QString& type) {
	if (type == "bmp" || type == "jpg" || type == "jpeg" || type == "png" || type == "gif")
		return "picture";
	else if (type == "txt")
		return "text";
	else if (type == "mp3" || type == "mdi" || type == "wav")
		return "audio";
	else if (type == "scene")
		return "scene";
	else
		return type;
}