#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWin.h"

class CMainWin : public QMainWindow
{
	Q_OBJECT

public:
	CMainWin(QWidget *parent = 0);
	~CMainWin();

private:
	Ui::CMainWinClass ui;
};

#endif // MAINWIN_H
