#ifndef CDETEC_RESULT_FRM_H
#define CDETEC_RESULT_FRM_H

#include <QFrame>
#include "ui_cdetec_result_frm.h"
#include "Controller/cproject_controller.h"
class CDetecResultFrm : public QFrame
{
	Q_OBJECT

public:
	CDetecResultFrm(QWidget *parent = 0);
	~CDetecResultFrm();
private:
	void mSetStyle();
	void mInitConnects();

signals:
	void signal_show_image(const QString & path);

	public slots:
	void slot_read_reslut();

private:
	Ui::CDetecResultFrm ui;
	CProjectController * m_controller;
};

#endif // CDETEC_RESULT_FRM_H
