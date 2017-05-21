/**************************************************************************
File:         cproperty_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#include "cproperty_frm.h"
#include <iostream>
#include "Utils/JsonUtil.h"
#include <QProcess>
#include "Manager/clog_manager.h"
#include "Utils/Untility.h"
string conf_path = "engine/config.json";
string engine_path = "engine/detect.exe";

QString param_s = "engine/in";
QString param_d = "engine/result.data";
QString param_i = "engine/out";
QString param_p = "engine/config.json";
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CPropertyFrm::CPropertyFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	mSetStyle();
	mInitUI();
	mInitConnects();
}

CPropertyFrm::~CPropertyFrm()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CPropertyFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"background: rgb(80,80,80);"
	);
}

void CPropertyFrm::mInitUI() {
	CJsonReader reader(conf_path);
	int blurType = reader.readInt("blurType");
	bool bMaft = reader.readBool("bMaft");
	int detectType = reader.readInt("detectType");
	bool bProDetect = reader.readBool("bProDetect");
	bool bColorDetect = reader.readBool("bColorDetect");
	double varThreshold = reader.readDouble("varThreshold");
	double entThreshold = reader.readDouble("entThreshold");
	int binThreshold = reader.readInt("binThreshold");

	ui.checkBox_maft->setChecked(bMaft);
	ui.checkBox_mutliC->setChecked(bColorDetect);
	ui.checkBox_projection->setChecked(bProDetect);
	ui.comboBox_blur->setCurrentIndex(blurType);
	ui.comboBox_detect->setCurrentIndex(detectType);

	char buf[16];
	if (detectType == 0)
		sprintf(buf, "%f", varThreshold);
	else if (detectType == 1)
		sprintf(buf, "%f", entThreshold);
	ui.lineEdit_detThreshold->setText(buf);
	sprintf(buf, "%d", binThreshold);
	ui.lineEdit_binThreshold->setText(buf);
}

void CPropertyFrm::mInitConnects() {
	m_controller = CProjectController::getInstance();
	connect(ui.pushButton_save, &QPushButton::clicked, this, &CPropertyFrm::on_pushButton_save_clicked);
	connect(ui.pushButton_detect, &QPushButton::clicked, this, &CPropertyFrm::on_pushButton_detect_clicked);
	connect(ui.pushButton_read, &QPushButton::clicked, this, &CPropertyFrm::on_pushButton_read_clicked);
	connect(this, &CPropertyFrm::signal_read_result, m_controller, &CProjectController::slot_read_result);
}

void CPropertyFrm::on_pushButton_save_clicked() {
	static bool b = false;
	b = !b;
	if (b) {
		return;
	}
	std::cout << "click!!!!!!!!!!" << std::endl;
	CJsonWriter writer(conf_path);
	int blurType = ui.comboBox_blur->currentIndex();
	bool bMaft = ui.checkBox_maft->isChecked();
	int detectType = ui.comboBox_detect->currentIndex();
	bool bProDetect = ui.checkBox_projection->isChecked();
	bool bColorDetect = ui.checkBox_mutliC->isChecked();
	int binThreshold = ui.lineEdit_binThreshold->text().toInt();
	double threshold = ui.lineEdit_detThreshold->text().toDouble();

	writer.writeInt("blurType", blurType);
	writer.writeBool("bMaft", bMaft);
	writer.writeInt("detectType", detectType);
	writer.writeBool("bProDetect", bProDetect);
	writer.writeBool("bColorDetect", bColorDetect);
	writer.writeInt("binThreshold", binThreshold);

	if (detectType == 0) {
		writer.writeDouble("varThreshold", threshold);
	}
	else if (detectType == 1) {
		writer.writeDouble("entThreshold", threshold);
	}

	writer.saveFile();
	CLogManager::getInstance()->printLog(WStrToUTF8(L"配置已保存.").c_str(), 0);
}

void CPropertyFrm::on_pushButton_detect_clicked() {
	static bool b = false;
	b = !b;
	if (b) {
		return;
	}
	QStringList strLst;
	strLst << "-s" << param_s;
	strLst << "-d" << param_d;
	strLst << "-i" << param_i;
	strLst << "-p" << param_p;
	CLogManager::getInstance()->printLog(WStrToUTF8(L"开始检测.").c_str(), 0);
	QProcess::startDetached(tr(engine_path.c_str()), strLst);

}

void CPropertyFrm::on_pushButton_read_clicked() {
	emit signal_read_result();
}