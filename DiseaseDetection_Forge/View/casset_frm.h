/**************************************************************************
File:         casset_frm.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef CASSET_FRM_H
#define CASSET_FRM_H

#include <QFrame>
#include "ui_casset_frm.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "unit/basic_data_structure.h"
#include <QMouseEvent>
//////////////////////////////////////////////////////////////////
///    Class:  CAssetFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CAssetFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CAssetFrm(QWidget *parent = 0);
	~CAssetFrm();
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
public slots:
	void slot_project_born(const QString& p_name, const QString& p_path);
	void slot_project_close();
///////////////////////////////////////////////////////////////////
//all signals are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_load_scene(const QString &path);
	void signal_load_picture(const QString &path);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mCreateTree();
	void mRecurCreateTree(CAssetTreeNode* node,QTreeWidgetItem* (&item));
	void mBuildAllConnects();
	void contextMenuEvent(QContextMenuEvent * event);
	void mDestroyTree();
	void mCreateMenu();
	void mCreateTreeView();
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
private slots:
	void on_treeWidget_itemEntered(QTreeWidgetItem*, int);
	void on_treeWidget_itemDoubleClicked(QTreeWidgetItem*, int);
	void on_treeWidget_itemClicked(QTreeWidgetItem*, int);
	void on_action_delete_triggered();
	void on_action_import_triggered();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CAssetFrm ui;
	QTreeWidget * m_tree;
	QTreeView * m_treeView;
	QTreeWidgetItem *m_item;
	QString m_strPath;
	QString m_strName;
	QMenu * m_menu;
	QAction * m_action_delte ;
	QAction * m_action_importResouce;
	bool m_isActive;
	//QPointF m_mousePoint;

};

#endif // CASSET_FRM_H
