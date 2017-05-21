/**************************************************************************
File:         cscene_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05-14
Description:
**************************************************************************/
#include "cscene_manager.h"
#include <QGraphicsPixmapItem>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CSceneManager * CSceneManager::getInstance() {
	static CSceneManager manager;
	return &manager;
}

QGraphicsScene * CSceneManager::loadScene(const QString& path) {
	m_scene = new QGraphicsScene(this);
	m_scene->setBackgroundBrush(QBrush(QColor("#A0A0A0"), Qt::CrossPattern));
	//pixmapItem->setPixmap(QPixmap(":/picture/ui_picture/objects/sprite.png"));
	return m_scene;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CSceneManager::slot_load_scene(const QString &path) {
	m_scene = loadScene(path);
	emit signal_show_scene(m_scene);
}

void CSceneManager::slot_load_picture(const QString &path) {
	QGraphicsPixmapItem * item = new QGraphicsPixmapItem;
	QPixmap pix(path);
	item->setPixmap(pix);
	item->setFlag(QGraphicsItem::ItemIsSelectable, true);
	item->setFlag(QGraphicsItem::ItemIsMovable, true);
	m_scene->clear();
	m_scene->addItem(item);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CSceneManager::CSceneManager(QObject * parent) : QObject(parent) {
	
}

CSceneManager::~CSceneManager() {
	
}
