/**************************************************************************
File:         casset_viewer.h
Author:       Song Xiaofeng
Date:         2016-05-012
Description:  this file provide a class with some funcs to preview some kind
			  of file, such as picture, text, audio and so on.
**************************************************************************/
#pragma once
#include <QObject>
#include <QThread>
#include <QGraphicsScene>
//////////////////////////////////////////////////////////////////
///    Class:  CAssetViewer
///    Brief:  
//////////////////////////////////////////////////////////////////
class CAssetViewer : public QThread {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CAssetViewer();
	~CAssetViewer();
	static void sPreViewFile(const QString &path, const QString &type, const QPointF &point);

///////////////////////////////////////////////////////////////////
//all signals are here
///////////////////////////////////////////////////////////////////
//signals:
	//void signal_load_scene(QGraphicsScene * scene);
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
//public slots:
	//void slot_preview_file(const QString &path, const QString &type, const QPointF &point);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void run();
	static void mPreViewPicture(const QString &path, const QString &type, const QPointF &point);
	static void mPreViewText(const QString &path, const QString &type, const QPointF &point);
	static void mPreViewAudio(const QString &path, const QString &type, const QPointF &point);
	//static void mPreViewScene(const QString &path);

///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////

};
