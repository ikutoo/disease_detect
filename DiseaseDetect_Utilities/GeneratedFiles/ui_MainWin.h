/********************************************************************************
** Form generated from reading UI file 'MainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWinClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWinClass)
    {
        if (CMainWinClass->objectName().isEmpty())
            CMainWinClass->setObjectName(QStringLiteral("CMainWinClass"));
        CMainWinClass->resize(600, 400);
        menuBar = new QMenuBar(CMainWinClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CMainWinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWinClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainWinClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CMainWinClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CMainWinClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMainWinClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWinClass->setStatusBar(statusBar);

        retranslateUi(CMainWinClass);

        QMetaObject::connectSlotsByName(CMainWinClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWinClass)
    {
        CMainWinClass->setWindowTitle(QApplication::translate("CMainWinClass", "CMainWin", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWinClass: public Ui_CMainWinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
