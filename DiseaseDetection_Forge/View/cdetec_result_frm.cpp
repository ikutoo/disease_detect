#include "cdetec_result_frm.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include "Utils/Untility.h"
#include "Manager/clog_manager.h"
extern QString param_d;
extern QString param_i;

CDetecResultFrm::CDetecResultFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
	);
	mInitConnects();
}

CDetecResultFrm::~CDetecResultFrm()
{

}
void CDetecResultFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 12px;"
	);
}

void CDetecResultFrm::slot_read_reslut() {
	static bool b = false;
	b = !b;
	if (b) {
		return;
	}
	ui.tableWidget->clearContents();
	for (int i = 0; i < ui.tableWidget->height(); ++i) {
		ui.tableWidget->removeRow(i);
	}

	QFile dataFile(param_d);

	if (dataFile.open(QFile::ReadOnly | QIODevice::Text))
	{
		QTextStream data(&dataFile);
		QString line;
		int rowNum = 0;
		while (!data.atEnd())//逐行读取文本，并去除每行的回车
		{
			line = data.readLine().trimmed();
			QStringList lst = line.split("\t");
			QString id = lst[0];
			QString path = lst[1];
			QString isDisease = lst[2];
			QString type = "";
			int blockNum = lst.size() - 4;
			QString blocks = "";
			if (isDisease == "true") {
				switch (lst[3].toInt()) {
				case 1:
					type = WStrToUTF8(L"裂缝").c_str();
					break;
				case 2:
					type = WStrToUTF8(L"破损").c_str();
					break;
				case 3:
					type = WStrToUTF8(L"渗漏水").c_str();
					break;
				}

			}
			for (int i = 0; i < blockNum; ++i) {
				blocks += lst[i + 4] + " ";
			}

			ui.tableWidget->insertRow(rowNum);
			ui.tableWidget->setItem(rowNum, 0, new QTableWidgetItem(id));
			ui.tableWidget->setItem(rowNum, 1, new QTableWidgetItem(isDisease));
			ui.tableWidget->setItem(rowNum, 2, new QTableWidgetItem(type));
			ui.tableWidget->setItem(rowNum, 3, new QTableWidgetItem(QString::number(blockNum)));
			ui.tableWidget->setItem(rowNum, 4, new QTableWidgetItem(blocks));
			ui.tableWidget->setItem(rowNum, 5, new QTableWidgetItem(path));
			rowNum++;
		}
		emit signal_show_image(param_i + "/0.bmp");
	}
	CLogManager::getInstance()->printLog(WStrToUTF8(L"读取检测结果成功.").c_str(), 0);
}

void CDetecResultFrm::mInitConnects() {
	m_controller = CProjectController::getInstance();
	connect(m_controller, &CProjectController::signal_read_result, this, &CDetecResultFrm::slot_read_reslut);
	connect(this, &CDetecResultFrm::signal_show_image, m_controller, &CProjectController::slot_show_image);
}