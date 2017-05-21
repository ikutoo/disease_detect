/**************************************************************************
File:         main.cpp
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#define USE_WIN32_CONSOLE

#include "view/cmain_win.h"
#include <QtWidgets/QApplication>
#include "view/cview_style.h"
#include <windows.h>
//设置应用程序全局风格
void setAppStyle(QApplication & a);
int main(int argc, char *argv[])
{
#ifdef USE_WIN32_CONSOLE
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
#endif

	QApplication a(argc, argv);
	setAppStyle(a);
	CMainWin w;
	w.showMaximized();
	int ret = a.exec();

#ifdef USE_WIN32_CONSOLE
	FreeConsole();
#endif

	return ret;
}
void setAppStyle(QApplication & a) {
	CViewStyle::sSetAppStyle(a);
}