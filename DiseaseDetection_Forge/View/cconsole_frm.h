/**************************************************************************
File:         cconole_frm.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef CCONSOLE_FRM_H
#define CCONSOLE_FRM_H
#include <QVBoxLayout>
#include <QFrame>
#include "ui_cconsole_frm.h"
#include "Manager/clog_manager.h"
#include <QTextEdit>
//////////////////////////////////////////////////////////////////
///    Class:  CConsoleFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CConsoleFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CConsoleFrm(QWidget *parent = 0);
	~CConsoleFrm();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitText();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CConsoleFrm ui;
	QVBoxLayout * m_layout;
	QTextEdit * m_text;
	CLogManager * m_logManager;
};

#endif // CCONSOLE_FRM_H
