/**************************************************************************
File:         cnew_project_dlg.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cnew_project_dlg.h"
#include <QtWidgets/QMessageBox>
#include <QtCore/QDir>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CNewProjectDlg::CNewProjectDlg(QWidget *parent)
	: QDialog(parent)
{
	/////////////dialog settings 
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	/////////////connect to controller
	m_controller = CProjectController::getInstance();
	connect(this, &CNewProjectDlg::signal_new_project,m_controller, &CProjectController::slot_new_project);
	connect(m_controller, &CProjectController::signal_project_born, this, &CNewProjectDlg::slot_project_born);
}

CNewProjectDlg::~CNewProjectDlg()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CNewProjectDlg::mSetStyle() {
	this->setStyleSheet(
		//"border: 2px solid gray;"
		//"border-radius: 4px;"
		"font-size: 16px;"
		);
}

void CNewProjectDlg::accept() {
	//get name and path
	QString name = ui.lineEdit_name->text();
	QString path = ui.lineEdit_path->text();
	//check name and path
	if ("" == name) {
		QMessageBox::warning(this, tr("warning"), tr("invalid project name!"));
		return;
	}
	if ("" == path) {
		QMessageBox::warning(this, tr("warning"), tr("invalid project path!"));
		return;
	}
	QDir dir;
	bool exist = dir.exists(path + "/" + name);
	if (exist) {
		QMessageBox::warning(this, tr("warning"), tr("dir already exists!"));
		return;
	}

	// emit signal
	emit signal_new_project(name, path);
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CNewProjectDlg::on_pushButton_browse_clicked() {
	QString s = QFileDialog::getExistingDirectory(
		this,
		tr("select path"),
		"c:",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
		);
	QString path = s;
	ui.lineEdit_path->setText(path);
}

void CNewProjectDlg::slot_project_born() {
	QDialog::accept();
}