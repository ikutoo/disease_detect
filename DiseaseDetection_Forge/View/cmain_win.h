/**************************************************************************
File:         cmain_win.h
Author:       Song Xiaofeng
Date:         2016-05
Description:  
**************************************************************************/
#ifndef CMAIN_WIN_H
#define CMAIN_WIN_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDockWidget>
#include "ui_cmain_win.h"
#include "cscene_frm.h"
#include "cdetec_result_frm.h"
#include "cproperty_frm.h"
#include "cconsole_frm.h"
#include "casset_frm.h"
#include "cnew_project_dlg.h"
#include "Controller/cproject_controller.h"
//////////////////////////////////////////////////////////////////
///    Class:  CMainWin
///    Brief:  
//////////////////////////////////////////////////////////////////
class CMainWin : public QMainWindow
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CMainWin(QWidget *parent = 0);
	~CMainWin();
///////////////////////////////////////////////////////////////////
//all signals are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_close_project();
	void signal_open_project(const QString & path);
////////////////////////////////////////////////////////////////////
//all private functions are here
////////////////////////////////////////////////////////////////////
private:
    
	void mSetStyle();
	void mCreateWindows();
	void mBuildAllConnects();
////////////////////////////////////////////////////////////////////
//all private slots are here
////////////////////////////////////////////////////////////////////
private slots:
	void on_action_newProject_triggered();
	void on_action_object_triggered(bool checked);
	void on_action_asset_triggered(bool checked);
	void on_action_hierarchy_triggered(bool checked);
	void on_action_property_triggered(bool checked);
	void on_action_console_triggered(bool checked);
	void on_action_closeProject_triggered();
	void on_action_openProject_triggered();
////////////////////////////////////////////////////////////////////
//all properties slots are here
////////////////////////////////////////////////////////////////////
private:
	Ui::CMainWin ui;
	QDockWidget *m_dockDetecResultFrm;
	QDockWidget *m_dockPropertyFrm;
	QDockWidget *m_dockConsoleFrm;
	QDockWidget *m_dockAssetFrm;
	QDockWidget *m_dockSceneFrm;
	CProjectController * m_controller;

};

#endif // CMAIN_WIN_H
