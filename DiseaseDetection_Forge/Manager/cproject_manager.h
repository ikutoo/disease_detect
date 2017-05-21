/**************************************************************************
File:         cproject_manager.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
#include "cmanager.h"
#include <QObject>
enum ProjectError
{
	init_project_err,
	init_asset_err,
	read_profile_err,
	open_project_err,
	create_file_err
};
//////////////////////////////////////////////////////////////////
///    Class:  CProjectManager
///    Brief:  
//////////////////////////////////////////////////////////////////
class CProjectManager : public QObject {
	Q_OBJECT

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	static CProjectManager * getInstance();
	void setPath(const QString& p_path) { m_strPath = p_path; }
	void setName(const QString& p_name) { m_strName = p_name; }
	void setOpen(bool bOpen) { m_isOpen = bOpen; }
	QString getPath() { return m_strPath; }
	QString getName() { return m_strName; }
	bool isOpen() { return m_isOpen;  }

///////////////////////////////////////////////////////////////////
//all signals  are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_project_error(ProjectError errType);
	void signal_project_born(const QString& p_name, const QString& p_path);
	void signal_project_close();
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
public slots:
	void slot_new_project(QString p_name, QString p_path);
	void slot_close_project();
	void slot_open_project(const QString &path);
	void slot_new_file(const QString &name, const QString &type);

///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	CProjectManager();
	~CProjectManager();
	bool mInitProject();
	bool mOpenProject();
	void mRemoveProDir();
	bool mWriteProfile();
	bool mReadProfile(const QString& path);
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	QString m_strPath;// the path of project
	QString m_strName;// the name of project
	bool m_isOpen;

};
