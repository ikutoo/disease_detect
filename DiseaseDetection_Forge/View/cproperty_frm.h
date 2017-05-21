/**************************************************************************
File:         cproperty_frm.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#ifndef CPROPERTY_FRM_H
#define CPROPERTY_FRM_H

#include <QFrame>
#include "ui_cproperty_frm.h"
#include "Controller/cproject_controller.h"
//////////////////////////////////////////////////////////////////
///    Class:  CPropertyFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CPropertyFrm : public QFrame
{
	Q_OBJECT
		///////////////////////////////////////////////////////////////////
		//all public functions are here
		///////////////////////////////////////////////////////////////////
public:
	CPropertyFrm(QWidget *parent = 0);
	~CPropertyFrm();
	///////////////////////////////////////////////////////////////////
	//all private functions are here
	///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitUI();
	void mInitConnects();

signals:
	void signal_read_result();

	public slots:
	void on_pushButton_save_clicked();
	void on_pushButton_detect_clicked();
	void on_pushButton_read_clicked();
	///////////////////////////////////////////////////////////////////
		//all properties  are here
		///////////////////////////////////////////////////////////////////
private:
	Ui::CPropertyFrm ui;
	CProjectController * m_controller;
};

#endif // CPROPERTY_FRM_H
