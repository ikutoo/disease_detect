/**************************************************************************
File:         casset_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "casset_frm.h"
#include "controller/cproject_controller.h"
#include "expert/cfile_expert.h"
#include "expert/casset_viewer.h"
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <qdirmodel>
#include <QList>
#include <QFileDialog>
#include "Manager/casset_manager.h"
#include "Manager/cscene_manager.h"
#include <iostream>

extern QString param_s;
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAssetFrm::CAssetFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	mSetStyle();
	mCreateMenu();
	this->setMouseTracking(true);
	/////////////////////////////////////////////
	m_tree = ui.treeWidget;
	m_item = 0;
	m_isActive = false;
	m_tree->setMouseTracking(true);
	m_tree->setHeaderLabel("Empty Project");
	m_tree->setDragEnabled(true);
	m_menu->setEnabled(false);
	//////////////////////////////////////////

	/////////////////////////////////////////////
	mBuildAllConnects();
}

CAssetFrm::~CAssetFrm()
{

}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::slot_project_born(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	m_isActive = true;
	m_menu->setEnabled(true);
	//mCreateTreeView();
	mCreateTree();
}

void CAssetFrm::slot_project_close() {
	m_tree->setHeaderLabel("Empty Project");
	m_isActive = false;
	m_menu->setEnabled(false);
	mDestroyTree();
	this->update();
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
	);
}

void CAssetFrm::mCreateTree() {
	m_tree->setHeaderLabel(m_strName);
	CAssetTreeNode* node = 0;
	QString path = m_strPath + "/" + m_strName + "/assets";
	CFileExpert::readTreeRecursively(path, node);
	//CFileExpert::readTreeRecursively("C:/Users/Administrator/Desktop/sss/assets",node);
	mRecurCreateTree(node, m_item);
	m_tree->addTopLevelItem(m_item);
}

void CAssetFrm::mCreateTreeView() {
	QDirModel *model = new QDirModel;
	m_treeView = new QTreeView(this);
	m_treeView->setModel(model);
	m_treeView->setRootIndex(model->index(m_strPath + "/" + m_strName + "/assets"));
}

void CAssetFrm::mCreateMenu() {
	m_menu = new QMenu(this);
	m_action_delte = new QAction("delete", this);
	m_action_importResouce = new QAction("import asset", this);
	m_menu->addAction(m_action_importResouce);
	m_menu->addAction(m_action_delte);
}

void CAssetFrm::mDestroyTree() {
	if (m_item != 0)
		delete m_item;
	m_item = 0;
}

void CAssetFrm::mRecurCreateTree(CAssetTreeNode* node, QTreeWidgetItem* (&item)) {
	if (node == 0) {
		item = 0;
		return;
	}
	//////////////////////////////////////////////////
	item = new QTreeWidgetItem();
	item->setText(0, node->data.name);
	item->setData(0, Qt::UserRole, node->data.id);
	item->setData(0, Qt::UserRole + 1, node->data.name);
	item->setData(0, Qt::UserRole + 2, node->data.path);
	item->setData(0, Qt::UserRole + 3, node->data.type);
	//////////////////////////////////////////////
	QString s = node->data.type;
	if (s == "txt")
		node->data.type = "text";
	if ((s == "png") || (s == "jpg") || (s == "jpeg") || (s == "bmp"))
		node->data.type = "picture";

	/////////////////////////////////////////////////
	if (node->data.type == "folder")
		item->setIcon(0, QIcon(":/picture/ui_picture/folder.png"));
	else if (node->data.type == "picture")
		item->setIcon(0, QIcon(":/picture/ui_picture/objects/picture.png"));
	else if (node->data.type == "text")
		item->setIcon(0, QIcon(":/picture/ui_picture/objects/text.png"));
	else if (node->data.type == "scene")
		item->setIcon(0, QIcon(":/picture/ui_picture/file/scene.png"));
	////////////////////////////////////////////////////
	QTreeWidgetItem * lchild;
	mRecurCreateTree(node->lchild, lchild);
	item->addChild(lchild);
	//////////////////////////////////////////////////////
	CAssetTreeNode* tmp = node->lchild;
	if (tmp == 0)
		return;
	else {
		for (tmp = tmp->rsibling; tmp != 0; tmp = tmp->rsibling) {
			QTreeWidgetItem * rchilds;
			mRecurCreateTree(tmp, rchilds);
			item->addChild(rchilds);
		}
	}
	//////////////////////////////////////////////////////
}

void CAssetFrm::contextMenuEvent(QContextMenuEvent * event) {
	QCursor cur = this->cursor();
	m_menu->exec(cur.pos());
}

void CAssetFrm::mBuildAllConnects()
{
	//connect(m_tree, &QTreeWidget::itemEntered, 
	//  this, &CAssetFrm::on_treeWidget_itemEntered);
	connect(m_tree, &QTreeWidget::itemDoubleClicked,
		this, &CAssetFrm::on_treeWidget_itemDoubleClicked);
	connect(m_tree, &QTreeWidget::itemClicked, this, &CAssetFrm::on_treeWidget_itemClicked);
	///////////////////////////////////////////////////
	CProjectController *controller = CProjectController::getInstance();
	//connect(controller, &CProjectController::signal_new_project, 
	//  this, &CAssetFrm::slot_project_born);
	connect(controller, &CProjectController::signal_project_born,
		this, &CAssetFrm::slot_project_born);
	connect(controller, &CProjectController::signal_project_close,
		this, &CAssetFrm::slot_project_close);
	connect(this, &CAssetFrm::signal_load_scene,
		controller, &CProjectController::slot_load_scene);
	connect(this, &CAssetFrm::signal_load_picture,
		controller, &CProjectController::slot_load_picture);
	//////////////////////////////////////////////////////
	connect(m_action_delte, &QAction::triggered,
		this, &CAssetFrm::on_action_delete_triggered);
	connect(m_action_importResouce, &QAction::triggered,
		this, &CAssetFrm::on_action_import_triggered);

	emit signal_load_scene("");

}

///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::on_treeWidget_itemEntered(QTreeWidgetItem * item, int col)
{

}

void CAssetFrm::on_treeWidget_itemClicked(QTreeWidgetItem * item, int col) {
	QString path = item->data(col, Qt::UserRole + 2).toString();
	param_s = path;
}

void CAssetFrm::on_treeWidget_itemDoubleClicked(QTreeWidgetItem * item, int col) {
	static bool click = true;
	click = !click;
	if (!click)
		return;
	QString path = item->data(col, Qt::UserRole + 2).toString();
	QString type = item->data(col, Qt::UserRole + 3).toString();
	QPointF point;
	QCursor cur = this->cursor();
	point.setX(this->pos().x() + this->width());
	point.setY(cur.pos().y());

	//if (type != "scene")
		//CAssetViewer::sPreViewFile(path, type, point);
	//else {
		//emit signal_load_scene(path);
	//}
	emit signal_load_picture(path);
}

void CAssetFrm::on_action_delete_triggered() {

	QTreeWidgetItem * item = m_tree->currentItem();
	QString path;
	path = item->data(0, Qt::UserRole + 2).toString();
	delete item;
	m_tree->update();
	CFileExpert::deleteDir(path);
}

void CAssetFrm::on_action_import_triggered() {
	/////////////////////////////////////////
	QTreeWidgetItem * item = m_tree->currentItem();
	QString desPath = item->data(0, Qt::UserRole + 2).toString();
	if (item != m_item) {
		item = item->parent();
	}
	CAssetTreeNode* node = 0;
	QString path = QFileDialog::getExistingDirectory(
		this,
		tr("select path"),
		"",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
	);
	CFileExpert::readTreeRecursively(path, node);
	QTreeWidgetItem * tmp = m_tree->currentItem();
	mRecurCreateTree(node, tmp);
	item->addChild(tmp);
	m_tree->update();
	///////////////////////////////
	bool b = CFileExpert::copyRecursively(path, desPath);

}


