/**************************************************************************
File:         cview_style.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef CVIEW_STYLE_H
#define CVIEW_STYLE_H

#include <QObject>
//////////////////////////////////////////////////////////////////
///    Class:  CViewStyle
///    Brief:  
//////////////////////////////////////////////////////////////////
class CViewStyle : public QObject
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CViewStyle(QObject *parent);
	~CViewStyle();
	static void sSetAppStyle(QApplication & a);
};

#endif // CVIEW_STYLE_H
