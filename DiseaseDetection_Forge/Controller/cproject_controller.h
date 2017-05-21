/**************************************************************************
File:         cproject_controller.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
#include <QObject>
#include "manager/cproject_manager.h"
#include "Manager/cscene_manager.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
//////////////////////////////////////////////////////////////////
///    Class:  CProjectController
///    Brief:  
//////////////////////////////////////////////////////////////////
class CProjectController : public QObject {
	Q_OBJECT

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	static CProjectController* getInstance();
///////////////////////////////////////////////////////////////////
//all signals  are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_new_project(const QString& p_name, const QString& p_path);
	void signal_project_born(const QString& p_name, const QString& p_path);
	void signal_project_err(ProjectError errType);
	void signal_project_close();
	void signal_open_project(const QString & path);
	void signal_new_file(const QString &name, const QString &type);
	void signal_load_scene(const QString &path);
	void signal_load_picture(const QString &path);
	void signal_show_scene(QGraphicsScene* scene);
	void signal_read_result();
	void signal_show_image(const QString & path);
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
public slots:
	void slot_new_project(const QString& p_name, const QString& p_path);
	void slot_close_project();
	void slot_project_born(const QString& p_name, const QString& p_path);
	void slot_project_err(ProjectError errType);
	void slot_open_project(const QString & path);
	void slot_new_file(const QString &name, const QString &type);
	void slot_load_scene(const QString &path);
	void slot_load_picture(const QString &path);
	void slot_show_scene(QGraphicsScene* scene);
	void slot_read_result();
	void slot_show_image(const QString & path);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	CProjectController();
	~CProjectController();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	CProjectManager* m_projectManager;
	CSceneManager *  m_sceneManager;
};
