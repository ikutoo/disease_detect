/**************************************************************************
File:         cconsole_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cconsole_frm.h"
#include <QTextEdit>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CConsoleFrm::CConsoleFrm(QWidget *parent)
	: QFrame(parent)
{
	//ui->setupUi(this);
	mSetStyle();
	mInitText();

	m_logManager = CLogManager::getInstance();
	m_logManager->setLog(m_text);
}

CConsoleFrm::~CConsoleFrm()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CConsoleFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
		);
}

void CConsoleFrm::mInitText() {
	this->setWindowTitle("Console");
	this->setMinimumSize(100, 100);
	m_layout = new QVBoxLayout();
	m_text = new QTextEdit();
	m_text->setStyleSheet("background:#505050;color:white");
	//m_text->setEnabled(false);
	m_layout->addWidget(m_text);

	this->setLayout(m_layout);
}