/**************************************************************************
File:         cview_style.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "ViewStyle.h"
#include <QApplication>
#include <QStyle>
#include <QStyleFactory>
#include <QFile>
#include <QDebug>

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

}