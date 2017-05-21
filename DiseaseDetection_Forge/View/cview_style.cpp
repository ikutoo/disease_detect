/**************************************************************************
File:         cview_style.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cview_style.h"
#include <QApplication>
#include <QStyle>
#include <QStyleFactory>
#include <QFile>
#include <QDebug>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CViewStyle::CViewStyle(QObject *parent)
	: QObject(parent)
{

}

CViewStyle::~CViewStyle()
{

}

void CViewStyle::sSetAppStyle(QApplication & a) {
	a.setStyle(QStyleFactory::create("fusion"));

	QPalette palette;
	palette.setColor(QPalette::Window, QColor(50, 50, 50));
	palette.setColor(QPalette::WindowText, Qt::white);
	a.setPalette(palette);

	QFile file(":/qss/ui_qss/styleMenuBar.qss");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Can't open the file!" << endl;
	}
	a.setStyleSheet(file.readAll());
	file.close();
}