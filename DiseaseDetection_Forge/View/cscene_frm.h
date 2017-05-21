/**************************************************************************
File:         cscene_frm.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef CSCENE_FRM_H
#define CSCENE_FRM_H

#include <QFrame>
#include "ui_cscene_frm.h"
#include <QtWidgets/qgraphicsview.h>
#include <QtWidgets/qgraphicsscene.h>
#include "Controller/cproject_controller.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QVBoxLayout>
#include <QToolBar>
//////////////////////////////////////////////////////////////////
///    Class:  CSceneView
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneView : public QGraphicsView {
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSceneView(QWidget* parent = 0);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
};
//////////////////////////////////////////////////////////////////
///    Class:  CSceneFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSceneFrm(QWidget *parent = 0);
	~CSceneFrm();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitScene();
	void mBuildAllConnects();
	void mInitUI();
	void mInitToolBar();
///////////////////////////////////////////////////////////////////
//all private slots  are here
///////////////////////////////////////////////////////////////////
private slots:
    void slot_show_scene(QGraphicsScene* scene);
	void on_action_select_triggered();
	void on_action_move_triggered();
	void slot_show_image(const QString & path);
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CSceneFrm ui;
	QGraphicsView * m_view;
	QGraphicsScene * m_scene;
	CProjectController* m_controller;
	QVBoxLayout * m_layout;
	QToolBar * m_toolBar;
};

#endif // CSCENE_FRM_H
