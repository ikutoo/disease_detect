/**************************************************************************
File:         cscene_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cscene_frm.h"
#include <QtWidgets/QGraphicsPixmapItem>
#include <iostream>
///////////////////////////////////////////////////////////////////
//all public functions are here 
///////////////////////////////////////////////////////////////////
CSceneView::CSceneView(QWidget* parent) {
	this->setParent(parent);
	this->setSceneRect(-5000, -5000, 10000, 10000);
	this->setDragMode(QGraphicsView::RubberBandDrag);
	this->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setAcceptDrops(true);
	this->show();
}

CSceneFrm::CSceneFrm(QWidget *parent)
	: QFrame(parent) {
	//ui.setupUi(this);
	mSetStyle();
	mBuildAllConnects();
	mInitUI();
}

CSceneFrm::~CSceneFrm() {

}
///////////////////////////////////////////////////////////////////
//all private slots  are here
///////////////////////////////////////////////////////////////////
void CSceneFrm::slot_show_scene(QGraphicsScene* scene) {
	//delete m_scene;
	m_scene = nullptr;
	m_scene = scene;
	m_view->setScene(scene);
	m_view->show();
}

void CSceneFrm::on_action_move_triggered() {
	m_view->setDragMode(QGraphicsView::ScrollHandDrag);
}

void CSceneFrm::on_action_select_triggered() {
	m_view->setDragMode(QGraphicsView::RubberBandDrag);
}

void CSceneFrm::slot_show_image(const QString & path) {
	
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CSceneFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 1px solid gray;"
		"border-radius: 1px;"
		"font-size: 16px;"
	);
}

void CSceneFrm::mInitScene() {
	//m_scene = new QGraphicsScene(this);
	//m_view->setScene(m_scene);
	//m_scene->setBackgroundBrush(QBrush(QColor("#A0A0A0"), Qt::CrossPattern));
}

void CSceneFrm::mBuildAllConnects() {
	m_controller = CProjectController::getInstance();
	connect(m_controller, &CProjectController::signal_show_scene, this, &CSceneFrm::slot_show_scene);
	//connect(m_controller, &CProjectController::signal_show_image, this, &CSceneFrm::slot_show_image);
}

void CSceneFrm::mInitUI() {
	m_view = new CSceneView(this);
	m_layout = new QVBoxLayout(this);
	m_toolBar = new QToolBar(this);

	m_layout->addWidget(m_toolBar);
	m_layout->addWidget(m_view);

	mInitToolBar();
	mInitScene();
}

void CSceneFrm::mInitToolBar() {
	QAction * action_select = new QAction(this);
	action_select->setIcon(QIcon(":/picture/ui_picture/toolBar/arrow.png"));
	//action_select->

	QAction * action_move = new QAction(m_toolBar);
	action_move->setIcon(QIcon(":/picture/ui_picture/toolBar/hand.png"));

	m_toolBar->addAction(action_move);
	m_toolBar->addAction(action_select);

	connect(action_move, &QAction::triggered, this, &CSceneFrm::on_action_move_triggered);
	connect(action_select, &QAction::triggered, this, &CSceneFrm::on_action_select_triggered);
}

void CSceneView::wheelEvent(QWheelEvent *event) {
	int numDegrees = event->delta() / 8;
	int numSteps = numDegrees / 15;
	float s = 1 + ((float)numSteps) / 10;
	this->scale(s, s);
}

void CSceneView::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		this->setDragMode(QGraphicsView::ScrollHandDrag);
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}

void CSceneView::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		this->setDragMode(QGraphicsView::RubberBandDrag);
	}
	else {
		QGraphicsView::mouseReleaseEvent(event);
	}
}
