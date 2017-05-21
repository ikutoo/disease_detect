/**************************************************************************
File:         cproject_controller.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cproject_controller.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CProjectController* CProjectController::getInstance() {
	static CProjectController controller;
	return &controller;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CProjectController::slot_new_project(const QString& p_name, const QString& p_path) {
	emit signal_new_project(p_name, p_path);
}

void CProjectController::slot_open_project(const QString & path) {
	emit signal_open_project(path);
}

void CProjectController::slot_close_project() {
	emit signal_project_close();
}

void CProjectController::slot_project_born(const QString& p_name, const QString& p_path) {
	emit signal_project_born(p_name, p_path);
}

void CProjectController::slot_project_err(ProjectError errType) {
	emit signal_project_err(errType);
}

void CProjectController::slot_new_file(const QString &name, const QString &type) {
	emit signal_new_file(name, type);
}

void CProjectController::slot_load_scene(const QString &path) {
	emit signal_load_scene(path);
}

void CProjectController::slot_load_picture(const QString &path) {
	emit signal_load_picture(path);
}

void CProjectController::slot_show_scene(QGraphicsScene* scene) {
	emit signal_show_scene(scene);
}

void CProjectController::slot_read_result() {
	emit signal_read_result();
}

void CProjectController::slot_show_image(const QString & path) {
	emit signal_show_image(path);
}
//////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CProjectController::CProjectController() {
	m_projectManager = CProjectManager::getInstance();
	connect(this, &CProjectController::signal_new_project,
		m_projectManager, &CProjectManager::slot_new_project);
	connect(m_projectManager, &CProjectManager::signal_project_born,
		this, &CProjectController::slot_project_born);
	connect(this, &CProjectController::signal_open_project,
		m_projectManager, &CProjectManager::slot_open_project);
	connect(m_projectManager, &CProjectManager::signal_project_close,
		this, &CProjectController::slot_close_project);
	connect(this, &CProjectController::signal_new_file,
		m_projectManager, &CProjectManager::slot_new_file);

	m_sceneManager = CSceneManager::getInstance();
	connect(this, &CProjectController::signal_load_scene,
		m_sceneManager, &CSceneManager::slot_load_scene);
	connect(m_sceneManager, &CSceneManager::signal_show_scene,
		this, &CProjectController::slot_show_scene);
	connect(this, &CProjectController::signal_load_picture,
		m_sceneManager, &CSceneManager::slot_load_picture);
	connect(this, &CProjectController::signal_show_image, m_sceneManager, &CSceneManager::slot_load_picture);
}

CProjectController::~CProjectController() {

}